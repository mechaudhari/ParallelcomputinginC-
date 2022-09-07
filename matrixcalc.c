//SOURCE: mul.C
//EXERCISE: Multiply a Matrix with Vector Matrix
//AUTHOR: Meenal Chaudhari
//Student, CSE Deapartment
//DATE: 02/08/2017
//EMAIL: mchaudhari@aggies.ncat.edu
//DESCRIPTION: It initializes the matrices through calculation: a[ij] = i + j. It Prints both the matrices and the result of their multiplication.
//Header Files
#include<stdio.h>
#include<time.h>
void main() 
	{
	//Declarations
	FILE *no;
	int m, n, p, q, c, d, k, sum=0;
	no = fopen(“no.txt”, “r”);
	//Matrices
	int first[10][10];
	int second[10][10];
	int multiply[10][10];
	//reading values from file no.txt and storing into m,n p,q
	fscanf(no, “%d %d %d %d”, &m, &n, &p, &q);
	//timestamping the code
	char buff[100];
	time_t now = time(0);
	strftime(buff, 100, “%Y-%m-%d %H:%M:%S.000”, localtime(&now));
	printf(“Present time: %s\n”, buff);
	//declaring the no. of rows and columns in Array B
	printf("enter the number of rows and columns of first matrix \n");
	printf("m is %d", m);
	printf("n is %d ", n);
	//initializing first matrix
	for (c = 0; c < m; c++){
		for(d = 0; d < n; d++){
			first[c][d] = c + d;
			printf(" %d \t",first[c][d]);
			}
		printf("\n");
		}
	// declaring the no. of rows and columns in Array Y
	printf("enter the number of rows and columns of first matrix \n");
	printf("p = %d, q = %d:",p, q);
	//checking whether matrix are conformable
	if(n!=p){
		printf("Matrices with entered orders can't be multiplied with each other.\n");
		}
	else{
		printf("Enter the elements of second matrix\n");
		}
	//initialize second matrix
	for (c = 0; c < p; c++){
		for(d = 0; d < q; d++){
			first[c][d] = c + d;
			printf(" %d \t", second[c][d]);
			}
		printf("\n");
		}
	//Multiplication Loop
	for (c = 0; c < m; c++){
		for(d = 0; d < q; d++){
			for(k = 0; k < n; k++){
				sum = sum + first[c][k] * second[k][d];
				}
			multiply[c][d] = sum;
			}
		}
	// printing Matrix C
	printf("Product of entered matrices:\n");
	for (c = 0; c < m; c++){
		for(d = 0; d < q; d++){
			printf("%d \t",multiply[c][d]);
			printf("\n");
			}
		}
	}