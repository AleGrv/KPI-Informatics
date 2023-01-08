#include <stdio.h>
#include <stdlib.h>

int main() {

	int char_counter=0, is_char;

	FILE* marks_count=fopen("marks_count.txt", "w+b");
	if(marks_count!=NULL) printf("\nFile marks_count.txt is created: OK\n\n");
	else if(marks_count==NULL) {
		printf("\nError: File marks_count.txt not created");
		exit(1);
	}
	printf("Write the text with punctuation marks here: \n");

	while((is_char=getchar())!=EOF) {
		if (is_char==33 || is_char==44 || is_char==46 || is_char==45 || is_char==63 || is_char==58 || is_char==59) {
			char_counter++;
		}
	}

	marks_count=fopen("marks_count.txt", "wt");
	if(marks_count==NULL) {
		printf("\nError: Files marks_count.txt cannot be opened or doesn't exist!");
		exit(1);
	}
	
	fprintf(marks_count,"Counted marks = %d",char_counter);
	fclose(marks_count);
	printf("Punctuation marks have been counted");
	exit(1);

	return 0;
}
