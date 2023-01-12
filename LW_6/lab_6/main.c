#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "lib_6.h"

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