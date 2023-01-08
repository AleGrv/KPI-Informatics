#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/* FUNCTIONS DECLARATION */

void Prn_A(); //
void Prn_B();
void Srt_AB(); // A sort;
void M_cleaner();

/* MAIN */
int main() {

	/* VARIABLES DEFINITION */
	int i, j, N, M, **A=NULL, **B=NULL;
	

	/* WORKSPACE */

printf("Enter the square matriix number, N= ");
scanf("%d", &N);
		
//--- A array init
		A=(int**)malloc(N*sizeof(int*));

		if(A==NULL) {
			printf("Error allocate memory A1.\n");
			exit(1);
		}

printf("\nEnter matrix elements values NxN= %d:\n\n", N*N);

		for(i=0; i<N; i++) {
			A[i]=(int*)malloc(N*sizeof(int));

			if(A[i]==NULL) {
				printf("Error allocate memory A2.\n");
				for(i=0; i<N; i++) {
					free(A[i]);
					free(A);
					exit(1);
				}
			}

			for(j=0; j<N; j++) {
printf("A[%d][%d]= ", i, j);
scanf("%d", &M);
				A[i][j]=M;
			}
		}

//--- B array itit
		B=(int**)malloc(N*sizeof(int*));

		if(B==NULL) {
			printf("Error allocate memory B1.\n");
			exit(1);
		}

		for(i=0; i<N; i++) {
			B[i]=(int*)malloc(M*sizeof(int));

			if(B[i]==NULL) {
				printf("Error allocate memory B2.\n");
				for(i=0; i<N; i++) {
					free(B[i]);
					free(B);
					exit(1);
				}
			}

			for(j=0; j<N; j++) {
				B[i][j]=0;
			}
		}

//--- switch


//--- A sorting

				Srt_AB(A, B, N);



	/* WORKSPACE, END */

	return 0;
}
/* MAIN, END */

/* FUNCTIONS DEFINITION */

void Prn_A(int **A, int N) {

	int i=0,j=0;

//--- A
		
		for(i=0; i<N; i++) {
			for(j=0; j<N; j++) printf("%5d", A[i][j]);
			puts("");
		}
}

void Prn_B(int **B, int N) {

	int i=0,j=0;

		for(i=0; i<N; i++) {
			for(j=0; j<N; j++) printf("%5d", B[i][j]);
			puts("");
		}
	}

void M_cleaner(int **A, int **B){

	if (A!=NULL) {
		printf("\n\nCleaning A\n");
		free(A[0]);
		free(A);
	}

	if (B!=NULL) {
		printf("\n\nCleaning B\n");
		free(B[0]);
		free(B);
	}
}

//A, B sort
void Srt_AB(int **A, int **B, int N) {
int k, i, j;

printf("\n\n A matrix:\n");
Prn_A(A, N);

	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			B[i][j]=A[i][j];
		}
	}

//--- A > ALL sorting
		int f_0=0; i=0; j=0;
		do {
			f_0=0;
			for (k=1; k<N*N; k++) {
				int j=k/N;
				int i=k-j*N;
				int jp=(k-1)/N;
				int ip=(k-1)-jp*N;
				if (B[i][j]<B[ip][jp]) {
					int tmp=B[i][j];
					B[i][j]=B[ip][jp];
					B[ip][jp]=tmp;
					B[i][j]==B[ip][jp];
					B[ip][jp]=tmp;
					B[i][j]=B[i][j];
					f_0++;
				}
			}
		} while(f_0!=0);

printf("\n\n Sorted A matrix in B:\n");
	Prn_B(B, N);
	
	//--- B > columns sorting
	
			f_0=0; 
		do {
			f_0=0;
			for (k=1; k<N*N; k++) {
				int i=k/N;
				int j=k-i*N;
				int ip=(k-1)/N;
				int jp=(k-1)-ip*N;
				
				if (B[i][j]<B[ip][jp]) {
					int tmp=B[i][j];
					B[i][j]=B[ip][jp];
					B[ip][jp]=tmp;
					B[i][j]==B[ip][jp];
					B[ip][jp]=tmp;
					B[i][j]=B[i][j];
					f_0++;
				}
			}
		} while(f_0!=0);
	
	printf("\n\n Sorted columns of B matrix:\n");
	Prn_B(B, N);
	
	}

