//SOURCE: ppie.c
//EXERCISE: Set 3 Question
//AUTHOR: Meenal Chaudhari
//DATE: 02/18/2017
//EMAIL: mchaudhari@aggies.ncat.edu
//DESCRIPTION: Calculating PIe and determining error using MPI Reduce
//EXERCISE: Set 3 Question
//AUTHOR: Meenal Chaudhari
//DATE: 02/18/2017
//EMAIL: mchaudhari@aggies.ncat.edu
//DESCRIPTION: Scattering a matrix.
/*include header files*/
#include "mpi.h"
#include <math.h>
#include <stdio.h>
/*processorname string length*/
#define MAX_Name 80
/*define master processsor*/
#define ROOT 0
int main(int argc, char *argv[])
	{
	int comm,rank, numprocs, i, len;
	int n = 8;//no. of terms
	int m;
	double Actual_PI = 3.141592653589793238462643;//
	double mypi, pi, step, sum, x;
	int error;
	char name[MAX_Name];
	double start_time, end_time, computation_time;
	printf(" thevalue of pie is %f",Actual_PI);
	// INitialize MPIexecution environment
	MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Get_processor_name(name, &len);
	start_time = MPI_Wtime();
	//Broadcast the number of terms to all processors
	MPI_Bcast(&n, 1, MPI_INT, ROOT,MPI_COMM_WORLD);
	//Calculating for each processor:n/p terms?
	m = n/numprocs;
	step = 1.0 / (double) m;
	sum = 0.0;
	for(i = rank + 1; i <= n; i += numprocs)
	// for(rank = 0; rank < numprocs - 1; rank ++)
		{
		x = step * ((double)i - 0.5);
		sum += (4.0/(1.0 + x*x));
		}
	mypi = step * sum;
	printf("This is my sum: %f from rank: %d name: %s\n", mypi,rank,name);
	//reduce all terms to one value Pi
	MPI_Reduce(&mypi, &pi, 1, MPI_DOUBLE, MPI_SUM, ROOT, MPI_COMM_WORLD);
	error = pi - Actual_PI;
	if(rank == 0)
		{
		printf("Pi is approx. %f, Error is %f\n", pi, error);
		end_time = MPI_Wtime();
		computation_time = end_time - start_time;
		printf("Time of calculating PI is: %f\n", computation_time);
		}
	//Terminate MPI Execution
	MPI_Finalize();
	}