//SOURCE: pbcast.C
//EXERCISE: Set 3 Question
//AUTHOR: Meenal Chaudhari
//DATE: 02/18/2017
//EMAIL: mchaudhari@aggies.ncat.edu
//DESCRIPTION: Broadcasting a string using MPI_Bcast.
//Header Files
#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char** argv) {
	int rank;
	int numprocs;
	int cnt,
	len;
	char name[100];
	double compute,
	strtime,
	endtime;
	char buf[6] = {'S','t','r','i','n','g'};
	cnt = sizeof(buf);
	// Initiate MPI
	MPI_Init(NULL, NULL);
	// Find out rank, size
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
	MPI_Get_processor_name(name, &len);
	if(rank == 0){
		strtime = MPI_Wtime();
		// buf = 'String';
		// If we are rank 0, set the number to -1 and send it to process 1
		MPI_Bcast(&buf,cnt, MPI_CHAR,0,MPI_COMM_WORLD);
		}
	endtime = MPI_Wtime();
	compute = endtime - strtime;
	printf( "Rank %d results %s\n",rank, buf);
	MPI_Barrier(MPI_COMM_WORLD);
	printf(" that took %f\n", compute);
	//Exit MPI
	MPI_Finalize();
	}