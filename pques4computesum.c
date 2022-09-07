//SOURCE: pques4computesum.c
//EXERCISE: Set 3 Question
//AUTHOR: Meenal Chaudhari
//DATE: 02/18/2017
//EMAIL: mchaudhari@aggies.ncat.edu
//DESCRIPTION: Compute sum of integers in interval provided by left and right limits in a file.
// Steps: read from a file
// broadcast
// distribute data
//Algorithm:
//1. At Root Processor
//Read input from file: l(left limit),r(right limit)
//2. At Rank =0, Determine the distribution of work to other processors:
//3. At Rank=0, Get number of processors, numprocs
//4. Calculate no. of integers, n = r – l
//5. If n is completely divisible by numprocs(checking remainder): if(n % numprocs = 0)
//Then data is equally distributed: n/numprocs=m, no.of integers at each processor
//Else calculate extra integers left for sum through remainder: n%numprocs = r, no of terms to be distributed as an overhead to one of the processors.
//6. Calculate individual left and right limits for each processor
//7.Communicate the individual left and right limits as calculated in previous step through point to point send n receive between root and other processors
//8.At individual processor, loop the numbers from start to end, adding each of them and generating individual sum as output : Parallel operation
//9.Use MPI_Reduce to get all individual sums added and reported to root
//10.Again at root, Print the Grand sum
//11. At root, Print the start and end time of entire process.
//12. Close the MPI: Finalize
#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char** argv) {
	FILE *no;
	int L,R;
	int g,l,r;
	int p;
	int sum,grandsum;
	int new[600];
	int rank;
	int len;
	int numprocs;
	int i,j;
	char name[600];
	double starttime,
	endtime,
	total_time;
	no = fopen("no.txt","r");
	fscanf(no," %d %d ", &L, &R);
	// Initiate MPI
	MPI_Init(NULL, NULL);
	// Find out rank, size
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
	MPI_Get_processor_name(name,&len);
	starttime = MPI_Wtime();
	//At root processor
	if(rank == 0){
		//Initializing data
		p = R - L;
		printf(" the no. of processors is %d\n",numprocs);
		printf("Total no. of integers to be distributed is %d\n",p);
		for(i=L;i<p;i++){
			new[i]=L;
			L++;
			}
		j = new[p];
		if(j == R){
			printf("we have complete array at root\n");
			}
		//Distributing data:Computing limits
		if((p%numprocs) == 0)
			{
			printf("data is equally distributed\n");
			g = p/numprocs;
			}
		else{
			r = p%numprocs;
			printf("overhead is %d\n",r);
			}
		MPI_Bcast(&L,1,MPI_INT,0,MPI_COMM_WORLD);
	}
	//data distb LOGIC
	for(rank=0;rank < numprocs - 1; rank++){
		l = L + rank*(g+1);
		r = L + (rank+1)*g;
		sum = L;
		for(i=0; i<g; i++){
			sum ++;
			}
		if(rank = numprocs -1)
			{
			for(i = 0; i < r; i++){
				sum++;
				}
			}
	}
	// MPI_Barrier(MPI_COMM_WORLD);
	//get grand sum
	MPI_Reduce(&sum,&grandsum,1,MPI_INT,MPI_SUM,0,MPI_COMM_WORLD);
	//synchhronize
	// MPI_Barrier(MPI_COMM_WORLD);
	//say Bye rank 0
	if(rank == 0){
		printf("the grand sum is %d\n",grandsum);
		endtime = MPI_Wtime();
		total_time = endtime - starttime;
		printf("Total time taken is: %f\n",total_time);
		}
	//synchronize
	MPI_Barrier(MPI_COMM_WORLD);
	//Exit MPI
	MPI_Finalize();
	}