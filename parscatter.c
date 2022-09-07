//SOURCE: parscatter.c
//EXERCISE: Set 3 Question
//AUTHOR: Meenal Chaudhari
//DATE: 02/18/2017
//EMAIL: mchaudhari@aggies.ncat.edu
//DESCRIPTION: Scattering a matrix.
//Header Files
#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char** argv) {
	int rank;
	int numprocs;
	int cnt,
	len,
	m,a,j,I;
	char name[100];
	int sendbuf[4][4];
	int recvbuf[4];
	double compute,
	strtime,
	endtime;
	// cnt = sizeof(Scatter);
	cnt = 4;
	a=1;
	//fill in array
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			sendbuf[i][j] = a;
			a++;
			}
		}
	// Initiate MPI
	MPI_Init(NULL, NULL);
	// Find out rank, size
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
	MPI_Get_processor_name(name, &len);
	//Do get proc name?
	if(rank == 0){
		printf(“Scatter Matrix:C version”);
		printf(“no. of processsors is %d\n”,numprocs);
		}
	//synchronize
	MPI_Barrier(MPI_COMM_WORLD);
	//get start time
	strtime = MPI_Wtime();
	if(numprocs == 4){
		cnt = 4;
		MPI_Scatter(&sendbuf,cnt, MPI_INT,&recvbuf,cnt,MPI_INT,0,MPI_COMM_WORLD);
		}
	for(i=0;i<4;i++){
		m = recvbuf[i];
		printf( “%d results %d \n”,rank,m);
		}
	MPI_Barrier(MPI_COMM_WORLD);
	endtime = MPI_Wtime();
	compute = endtime – strtime;
	compute = endtime – strtime;
	printf(“ that took %f\n”, compute);
	if(rank == 0){
		printf(“ScatterExample”);
		}
	/exit MPI
	MPI_Finalize();
	}