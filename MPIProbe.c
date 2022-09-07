//SOURCE: probe.C
//EXERCISE: Set 4 Question
//AUTHOR: Meenal Chaudhari
//DATE: 03/19/2017
//EMAIL: mchaudhari@aggies.ncat.edu
//DESCRIPTION: Using MPI_probe to dynamically know the size of message passed and MPI_getcount to know before send and receive.
#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>
int main(int argc, char *argv[])
	{
	//declare variables
	int rank, numprocs;
	int nos;
	int p;
	int sbuffer[100];
	MPI_Status status;
	//INitialize MPI
	MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD,&numprocs);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	//Needs only 2 processor for demonstration
	if(numprocs != 2){
		fprintf(stderr, "Must use two processors\n");
		MPI_Abort(MPI_COMM_WORLD,1);
		}
	//send random amount of nos to rank 1
	if(rank == 0){
		// const int MAX_sbuffer = 100;
		//SEt seed to generate random nos through rand() in next step
		void srand(unsigned int rank);
		//total nos to be sent
		p = rand();
		nos = (p /(float) RAND_MAX) *100;//MAX_sbuffer;
		MPI_Send(&sbuffer,nos,MPI_INT,1,0,MPI_COMM_WORLD);
		printf("Rank 0 sent %d nos to 1\n",nos);
		}
	else//rank == 1
		{
		MPI_Probe(0,0,MPI_COMM_WORLD,&status);
		//probe gets the size of the incoming msg
		MPI_Get_count(&status,MPI_INT,&nos);
		//Allocate buff in according to probe data
		int* rbuffer = (int*)malloc(sizeof(int) * nos);
		//Now rx
		MPI_Recv(rbuffer,nos,MPI_INT,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
		printf("Rank 1 dynamicaaly receive %d nos from Rank 0\n",nos);
		free(rbuffer);
		}
	MPI_Finalize();
	}