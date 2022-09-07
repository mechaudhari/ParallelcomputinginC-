//SOURCE: pingpong.c
//EXERCISE: Set 3 Question
//AUTHOR: Meenal Chaudhari
//DATE: 02/18/2017
//EMAIL: mchaudhari@aggies.ncat.edu
//DESCRIPTION: Scattering a matrix.
//Header Files
#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#define size 102400
int main(int argc, char** argv) {
	int rank;
	int numprocs;
	int cnt;
	int len;
	int no;
	int j,I,a;
	int dest;
	int src;
	int *array,*array1;
	char name[40];
	// char name[100];
	// int sendbuf[4][4];
	// int recvbuf[4];
	double compute,
	strtime,
	endtime;
	no = size;
	MPI_Init(NULL, NULL);
	// Find out rank, size
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
	MPI_Get_processor_name(name, &len);
	cnt = 0;
	a=1;
	strtime = MPI_Wtime();
	for(cnt = 0;cnt <=5; cnt++){
		if(rank == 0){
			no = cnt * size;
			array = (int*)malloc(sizeof(int)*no);
			//fill in array
			for(i=0;i<no;i++){
				array[i] = I;
				}
			dest=1;
			MPI_Send(&array,no,MPI_INT,1,100,MPI_COMM_WORLD);
			printf(“\n Rank: %d has send to Rank: %d\n”, rank, dest);
			src = 1;
			MPI_Recv(&array,no,MPI_INT,1,200,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
			printf(“\n Rank: %d has received from rank 1 \n”,rank);
			free(array);
			}
		else{
			//Rank ==1
			MPI_Recv(&array,no,MPI_INT,0,100,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
			printf(“\n Rank: %d has received from rank: %d \n”,rank, src);
			}
		MPI_Send(&array,no,MPI_INT,0,200,MPI_COMM_WORLD);
		printf(“\n Rank: %d has send to Rank 0\n”,rank);
		}
	if(numprocs != 2){
		printf(“\n Ping pong not feasible”);
		}
	MPI_Barrier(MPI_COMM_WORLD);
	endtime = MPI_Wtime();
	compute = endtime – strtime;
	if(rank == 0){
		printf(“\n ping pong program: normal end of execution\n”);
		printf(“Compute time: %f”,compute);
		}
	MPI_Barrier(MPI_COMM_WORLD);
	MPI_Finalize();
	return(0);
	}