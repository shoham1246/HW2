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


int main(int argc, char **argv) {

	FILE *fd;

	//check input
	if (argc == 1 || !strcmp("-", argv[1])){
		fd = stdin;
	} else{
		fd = fopen(argv[1], "r");
	}

	int hist[101] = {0};
	int num_of_grades = 0;

	while(1){
		int grade;
		int scanf_return = fscanf(fd, "%d", &grade);

		if(scanf_return == EOF){
			break; //end of file
		} else if (scanf_return !=1 || grade <0 || grade > 100){
			fprintf(stderr, "Error at line %d: invalid input %d", num_of_grades+1, grade ); //write input!!!!
			exit(1);
		}
		num_of_grades++;
		hist[grade] ++;
	}



	int median_idx = (num_of_grades+1)/2;
	int runner=0;
	int sum = 0;
	while ((sum < median_idx) && runner <=100)  {
		sum += hist[runner];
		runner ++;
		if(sum >= median_idx){
			break;
		}
	}

	fprintf(stdout, "%d", runner -1); //prints median in stdout


	fclose(fd);


	return 0;

}











