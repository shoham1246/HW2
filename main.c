/* Welcome to Mamat, 044101
 *
 * Use this project as a template for other C/C++ projects.
 * To copy this project, right-click on the project name "hello-world"
 * in the "project explorer" tab (left), then "copy" and finally "paste".
 *
 * To compile the project use "gcc" within the terminal.
 * To debug the project use "gdb" within the terminal.
 *
 * The red vertical line (right) represents the code width limit (80 chars).
 * Make sure not to cross it. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Application's main entry point
 * @param argc Number of arguments
 * @param argv Pointer to arguments
 * @return Non-zero value in case of an error
 */

void calcMedian(FILE *fd);
int compare(const void* a, const void* b);
int checkNumberOfLinesAndValidation(FILE *fd);

int main(int argc, char **argv) {

	FILE *fd;

	//check input
	if (argc == 0 || !strcmp("-", argv[1])){
		fd = stdin;
	} else{
		fd = fopen(argv[1], "r");
	}

	// if(!fd){
	// 	fprintf(stderr, "Error occurred");
	// 	return 1;
	// }

    calcMedian(fd);

	fclose(fd);


	return 0;

}

int compare(const void* a, const void* b) {
	return (*(int*)a - *(int*)b);
}

int checkNumberOfLinesAndValidation(FILE *fd){

	int N = 0; // number of lines in file
	int scanf_return;
	int grade;

	while(1){
		scanf_return = fscanf(fd, "%d", &grade);

		if(scanf_return == EOF){
			break; //end of file
		} else if (scanf_return !=1){
			fprintf(stderr, "Error at line %d: invalid input YYY", N); //write input!!!!
			exit(1);
		}

		N++;
	}

	printf("N = %d\n", N);
	return N;

}

void calcMedian(FILE *fd){

	int hist[101] = {0};

	while(1){
		scanf_return = fscanf(fd, "%d", &grade);

		if(scanf_return == EOF){
			break; //end of file
		} else if (scanf_return !=1){
			fprintf(stderr, "Error at line %d: invalid input YYY", N); //write input!!!!
			exit(1);
		}

		hist[scanf_return] ++;
	}

	

	fprintf(stdout, "median number %d", grades[med_idx]); //prints median in stdout
}






