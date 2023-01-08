#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/* mtrx - matrix;
rws - matrixes rows;
clmns - matrixes columns;
N - variant number;
oprn - operations with matrixes; */

/* FUNCTIONS DECLARATION */

void Prn_Arr(); //
void Min_Max_A(); // A max/min elements search;
void Trns_B(); // B transpose;
void AxB(); // AxB;
void Srt_A(); // A sort;
void Sum_AB(); // A+B;

/* MAIN */
int main() {

	/* VARIABLES DEFINITION */
	int i, j, K, N, M, T, mx_oprn, **A=NULL, **B=NULL, **C=NULL;
	char e_chr;

	/* WORKSPACE */

	while(1) {
		system("cls");

//--- matrix number N
		printf("\tMatrix A number for NxN (6x6)\n");
		printf("\tMatrix B number for NxM (6x8)\n\n");

//--- matrix operation selection
		do {
			printf("\n\tSelect the matrix operation\n\n");
			printf("\t1 - A matrix MIN MAX elements searching\n");
			printf("\t2 - B matrix transposing\n");
			printf("\t3 - AxB (matrixes multiplying)\n");
			printf("\t4 - A matrix sorting\n");
			printf("\t5 - A+B (matrixes summing)\n\n");
			printf("\tEnter the matrix operation: ");
			scanf("%d", &mx_oprn);

			if(mx_oprn!=1 && mx_oprn!=2 && mx_oprn!=3 && mx_oprn!=4 && mx_oprn!=5) {
				printf("\t\nThis operation is not available!\n");
				printf("\n\tPress 'e' to Exit or ... Other key to Continue... ");
				e_chr=getch();
				if(e_chr=='e') exit(1);
				system("cls");
			}
		} while(mx_oprn!=1 && mx_oprn!=2 && mx_oprn!=3 && mx_oprn!=4 && mx_oprn!=5);

		system("cls");

		N=6;
		M=8;
		T=6;
		K=8;
		
//--- A array init
		A=(int**)malloc(N*sizeof(int*));

		if(A==NULL) {
			printf("Error allocate memory A1.\n");
			exit(1);
		}

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
				A[i][j]=rand()%100;
			}
		}

//--- B array itit

		if(mx_oprn==5) M=6;
		else M=8;
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

			for(j=0; j<M; j++) {
				B[i][j]=rand()%10;
			}
		}

//--- C array init
		if(mx_oprn==4) K=6;
		if(mx_oprn==5) K=6;
		if(mx_oprn==2) {
			T=8;
			K=6;
		}

		C=(int**)malloc(T*sizeof(int*));

		if(C==NULL) {
			printf("Error allocate memory, C1.\n");
			exit(1);
		}

		for(i=0; i<T; i++) {
			C[i]=(int*)malloc(K*sizeof(int));

			if(C[i]==NULL) {
				printf("Error allocate memory, C2.\n");
				for(i=0; i<T; i++) {
					free(C[i]);
					free(C);
					exit(1);
				}
			}
		}

//--- switch
		switch(mx_oprn) {

//--- min max A
			case 1: {
				Min_Max_A(A, N);
			}
			break; // case 1

//--- B transpose
			case 2: {
				Trns_B(A, B, C, N, M, K, mx_oprn, T);
			}
			break; // case 2

//--- AxB
			case 3: {
				AxB(A, B, C, N, M, K, mx_oprn, T);
			}
			break; // case 3

//--- A sorting
			case 4: {
				Srt_A(A, B, C, N, M, K, mx_oprn, T);
			}
			break; // case 4

//--- A+B
			case 5: {
				Sum_AB(A, B, C, N, M, K, mx_oprn, T);
			} // case 5
		} // switch

		printf("\n\n\tPress 'e' to Exit or ... Other key to Continue... ");
		e_chr=getch();
		if(e_chr=='e')exit(1);
	}
// while(1), end
	/* WORKSPACE, END */

	return 0;
}
/* MAIN, END */

/* FUNCTIONS DEFINITION */

void Prn_Arr(int **A, int **B, int **C, int AMn, int AMx, int a, int am, int b, int c, int N, int M, int K, int mx_oprn, int T) {

	int i=0,j=0;

//--- A
	if(a==1) {
		printf("\nA=\n\n");
		for(i=0; i<N; i++) {
			for(j=0; j<N; j++) printf("%5d", A[i][j]);
			puts("");
		}
	}

//--- B
	if(b==1) {
		printf("\nB=\n\n");
		for(i=0; i<N; i++) {
			for(j=0; j<M; j++) printf("%5d", B[i][j]);
			puts("");
		}
	}

//--- C
	if(c==1) {
		if(mx_oprn==2) printf("\n\nTransposed B=\n\n");
		if(mx_oprn==3) printf("\n\nAxB=\n\n");
		if(mx_oprn==4) printf("\n\nSorted A=\n\n");
		if(mx_oprn==5) printf("\n\nA+B=\n\n");

		for(i=0; i<T; i++) {
			for(j=0; j<K; j++) printf("%5d", C[i][j]);
			puts("");
		}
	}

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

	if (C!=NULL) {
		printf("\n\nCleaning C\n");
		free(C[0]);
		free(C);
	}
}

//--- 1: min max A
void Min_Max_A(int **A, int N) {
	int AMn, AMx, am=1, *R, T;

	printf("\nA=\n\n");
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) printf("%5d", A[i][j]);
		puts("");
	}

	T=15;
	R=(int*)malloc(T*sizeof(int));

	if(R==NULL) {
		printf("Error allocate memory, C1.\n");
		exit(1);
	}

	for(int k=0; k<T; k++) {
		for(int i=0; i<N; i++) {
			for(int j=0; j<N; j++) {
				if(j==i) {
					for(int m=i+1; m<N; m++) {
						R[k]=A[m][j];
						k++;
					}
				}
			}
		}
	}

	AMn=R[0];
	int imn=0;
	for(int i=1; i<T; i++) {
		if (R[i]<AMn) {
			AMn=R[i];
			imn=i;
		}
	}

	AMx=R[0];
	int imx=0;
	for(int i=1; i<T; i++) {
		if (R[i]>AMx) {
			AMx=R[i];
			imx=i;
		}
	}

	printf("\n\nMin value 1/2 A= %d\n", AMn);
	printf("\nMax value 1/2 A= %d\n", AMx);

	if (R!=NULL) {
		printf("\n\nCleaning R\n");
		free(R);
	}
}

//--- 2: B transpose
void Trns_B(int **A, int **B, int **C, int N, int M, int K, int mx_oprn, int T) {
	int a=0, b=1, c=1, AMn, AMx, am=0;

	for(int i=0; i<T; i++) {
		for(int j=0; j<K; j++) {
			C[i][j]=B[j][i];
		}
	}

	printf ("Transposing B\n");
	Prn_Arr(A, B, C, AMn, AMx, a, am, b, c, N, M, K, mx_oprn, T);
}

//--- 3: AxB
void AxB(int **A, int **B, int **C, int N, int M, int K, int mx_oprn, int T) {
	int a=1, b=1, c=1, AMn=0, AMx=0, am=0;

	for(int i=0; i<T; i++) {
		for(int j=0; j<K; j++) {
			C[i][j]=0;
			for(int k=0; k<T; k++) {
				C[i][j]+=A[i][k]*B[k][j];
			}
		}
	}

	printf ("AB\n");
	Prn_Arr(A, B, C, AMn, AMx, a, am, b, c, N, M, K, mx_oprn, T);
}

//--- 4: A sort
void Srt_A(int **A, int **B, int **C, int N, int M, int K, int mx_oprn, int T) {
	int a=1, b=0, c=1, AMn=0, AMx=0, am=0, k, row_1;

	for(int i=0; i<N; i++) {
		for(int j=0; j<K; j++) {
			C[i][j]=A[i][j];
		}
	}

//--- Bubble sorting
	printf("\nSelect operation: (0 - Matrix sorting. From 1 to 6 - Row sorting): ");
	scanf("%d", &row_1);
	puts("");

	int f_1;
	if(row_1!=0) {
		int i=row_1-1;

//--- ROW bubble sorting
		do {
			f_1=0;
			for (int j=0; j<N-1; j++) {
				if (C[i][j]>C[i][j+1]) {
					int tmp_1=C[i][j];
					C[i][j]=C[i][j+1];
					C[i][j+1]=tmp_1;
					f_1++;
				}
			}
		} while(f_1!=0);
	} else {

//--- ALL bubble sorting
		int f_0=0;
		do {
			f_0=0;
			for (k=1; k<N*N; k++) {
				int j=k/N;
				int i=k-j*N;
				int jp=(k-1)/N;
				int ip=(k-1)-jp*N;
				if (C[i][j]<C[ip][jp]) {
					int tmp=C[i][j];
					C[i][j]=C[ip][jp];
					C[ip][jp]=tmp;
					C[i][j]==C[ip][jp];
					C[ip][jp]=tmp;
					C[i][j]=C[i][j];
					f_0++;
				}
			}
		} while(f_0!=0);
	}

	printf ("Sorting A\n");
	Prn_Arr(A, B, C, AMn, AMx, a, am, b, c, N, M, K, mx_oprn, T);
}

//--- 5: A+B
void Sum_AB(int **A, int **B, int **C, int N, int M, int K, int mx_oprn, int T) {
	int a=1, b=1, c=1, AMn=0, AMx=0, am=0;

	for(int i=0; i<N; i++) {
		for(int j=0; j<K; j++) {
			C[i][j]=A[i][j]+B[i][j];
		}
	}

	printf ("A+B\n");
	Prn_Arr(A, B, C, AMn, AMx, a, am, b, c, N, M, K, mx_oprn, T);
}
