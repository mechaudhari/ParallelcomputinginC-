//SOURCE: pques3.c
//EXERCISE: Set 3 Question
//AUTHOR: Meenal Chaudhari
//DATE: 02/18/2017
//EMAIL: mchaudhari@aggies.ncat.edu
//DESCRIPTION: Parallel execution of various processes.
// Process 1 broadcast squares to three prccessor
// Process 2 takes every other element n divide by 3
// Process 3 divides by 53, nos. which are between 20 n 119.
#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char** argv) {
int square[200];
double divide[100];
double rea[100];
double new[100];// will this b real
int tag = 1;
int tag1 = 3;
int rank;
int numprocs;
int i,j,m;
int count = 200;
int cnt;
double compute,
starttime,
endtime;
for(i = 0;i<200;i++)
{
square[i] = i*i;
}
//chk whether the squares are forming correct
// for(i = 0;i<200;i++)
//{
// printf("the elements of array are %d\n", square[i]);
//}
//process 2: getting other no.
for(i=1;i<200;i+=2){
// if((j%2)==0){
new[i] = square[i];
}
for(i=0;i<100;i++){
divide[i] = new[i]/3;
}
//Process 3:
for(i=0;i<100;i++){
m = divide[i];
cnt = 0;
if(m > 20 && m < 119){
rea[i] = m/53;
cnt = cnt + 1;
}
}
// p2 should be defined inside rank 1: no it points to this array
// Initiate MPI
MPI_Init(NULL, NULL);
// Find out rank, size
MPI_Comm_rank(MPI_COMM_WORLD, &rank);
MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
//Do get proc name?
//there are total 4 processors
if(numprocs < 4)
{
printf("No. of processors less thann four");
// MPI_Abort(MPI_COMM_WORLD, 1);
}
// int number;
//Process1: Broadcast Square array
if (rank == 0) {
// initialize
starttime = MPI_Wtime();
printf("Rank 0 broadcasts square\n");
MPI_Bcast(&square,count, MPI_INT,0,MPI_COMM_WORLD);
}
//chk whether it is broadcasted: aall chks need to be done outside rank loop
// else {
// MPI_Bcast(&square,count, MPI_INT,0,MPI_COMM_WORLD);
// printf("\n Process %d received data %d from root process\n", rank, square[3]);
//}
//Call Barrier to synchronize prints
if(rank == 1){
MPI_Send(&divide, 100, MPI_DOUBLE, 3,tag, MPI_COMM_WORLD);
}
// MPI_Barrier(MPI_COMM_WORLD);
if(rank == 3){
MPI_Recv(&divide, 100, MPI_DOUBLE, 1, tag, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
/ MPI_Barrier(MPI_COMM_WORLD);
if(rank == 3){
MPI_Recv(&divide, 100, MPI_DOUBLE, 1, tag, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
}
if(rank == 2){
MPI_Send(&rea, cnt, MPI_DOUBLE, 0,tag1, MPI_COMM_WORLD);
}
// MPI_Barrier(MPI_COMM_WORLD);
if(rank == 0){
MPI_Recv(&rea, cnt, MPI_DOUBLE, 2, tag1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
}
printf("rank %d receives no.of elements: %d\n",rank,MPI_Get_count);
//MPI_Barrier(MPI_COMM_WORLD);
//rank 0 sayss bye
if(rank == 0){
printf("\nbye\n");
endtime = MPI_Wtime();
compute = endtime - starttime;
printf("total computation time:%f \n",compute);
}
//End MPI
MPI_Finalize();
}