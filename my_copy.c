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
 
 #define BUFFER_SIZE 128 //number of temp bits to get data (for char 8, int 32..)

int main(int argc, char **argv) {

	FILE *fsrc; //source file
	FILE *fdst; //destination file

	//check input

	//check if source file exists
	if (!strcmp("-", argv[1]) ){
		fsrc = stdin;
	} else{
		fsrc = fopen(argv[1], "r");
		if(fsrc == NULL){
			fprintf(stderr, "Error occurred");
			return(1);
		}
	}

	//check if output exists
	if (!strcmp("-", argv[2]) ){
		fdst = stdout;
	} else{
		fdst = fopen(argv[2], "w");
		if(fdst == NULL){
			fprintf(stderr, "Error occurred");
			return(1);
		}
	}

	char buffer[BUFFER_SIZE];
	while(fgets(buffer, BUFFER_SIZE, fsrc)!= NULL){
		fputs(buffer, fdst);
	}



	fclose(fsrc);
	fclose(fdst);


	return 0;

}











