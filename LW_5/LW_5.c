#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* FUNCTIONS DECLARATION */

void f_creator();
void expr_w(int N, double X1, double X2, double delta, char gr_code[10], char st_name[20]);
void bin_r(int N, char gr_code[10], char st_name[20]);

/* MAIN */

int main() {

	int N;
	char gr_code[10]= {0}, st_name[20]= {0};
	double X1, X2, delta;

	//--- create files: txt, bin
	f_creator();

	FILE *input_data_r=fopen ("input_data.txt", "r");
	if (input_data_r==NULL) {
		printf("Error: input_data.txt cannot be opened or doesn't exist!");
	} else {
		fscanf(input_data_r, "%lf %lf %d %lf %s %s", &X1, &X2, &N, &delta, gr_code, st_name);
		fclose(input_data_r);

		if(!X1 && !X2 && !N && !delta && !gr_code && !st_name) {
			printf("Error: Data from input_data.txt not available!");
			exit(1);
		}
	}

	//--- expression data, write txt, bin
	expr_w(N, X1, X2, delta, gr_code, st_name);

	//--- read bin, show result
	bin_r(N, gr_code, st_name);

	return(0);
}

/* MAIN, END */

/* FUNCTIONS DEFINITION*/

//---
void f_creator() {

	FILE* t_table_c=fopen("t_table.txt", "w+b");
	FILE* b_table_c=fopen("b_table.bin", "w+b");

	if(t_table_c!=NULL) printf("\nFile t_table.txt is created: OK");
	if(b_table_c!=NULL) printf("\nFile b_table.bin is created: OK");

	else if(t_table_c==NULL && b_table_c==NULL) {
		printf("\nError: Files t_table.txt, b_table.bin weren't created");
		exit(1);
	}
}

void expr_w(int N, double X1, double X2, double delta, char gr_code[10], char st_name[20]) {

	FILE* t_table_w = fopen ("t_table.txt", "w");
	FILE* b_table_w = fopen ("b_table.bin", "w+b");

	if (t_table_w==NULL) {
		printf("Error: t_table.bin cannot be opened or doesn't exist!");
		exit(1);
	} else if (b_table_w==NULL) {
		printf("Error: b_table.bin cannot be opened or doesn't exist!");
		exit(1);
	} else {
		fprintf(t_table_w, "N\t\tX\t\tF(X)\n");
		fwrite(&N, sizeof(int), 1, b_table_w);
		double X;
		double Y;
		X=X1;
		for (int i=0; i<N; i++) {
			Y=powl(X, 2)/1000-0.5*X-1000;
			fprintf(t_table_w,"%d\t\t%.1lf\t\t%.4lf\n", i+1, X, Y);
			fwrite(&X, sizeof(double), 1, b_table_w);
			fwrite(&Y, sizeof(double),1, b_table_w);
			X+=delta;
		}
		fprintf(t_table_w, "%s, %s", gr_code, st_name);
		fclose(t_table_w);
		fclose(b_table_w);
	}
}

void bin_r(int N, char gr_code[10], char st_name[20]) {
	double val=0;
	FILE* b_table_r=fopen("b_table.bin", "r+b");
	if (b_table_r==NULL) {
		printf("Error: b_table.bin cannot be opened or doesn't exist!");
	} else {
		printf("\n\n");
		printf("************************************************************\n");
		printf("*  N   *            X            *           F(X)          *\n");
		printf("************************************************************\n");
		printf("+------+-------------------------+-------------------------+\n");

		fread(&N, sizeof(int), 1, b_table_r);
		for (int i=0; i<N; i++) {
			printf("|%5.0d |",i+1);
			fread(&val, sizeof(double), 1, b_table_r);
			printf("%24.3lf |", val);
			fread(&val, sizeof(double), 1, b_table_r);
			printf("%24.3lf |", val);
			printf("\n");
			printf("\r+------+-------------------------+-------------------------+\n");
		}
		printf("%s, %s", gr_code, st_name);
		fclose(b_table_r);
	}
}
