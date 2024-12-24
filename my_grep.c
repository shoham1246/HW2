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
 
 #define BUFFER_SIZE 8 //number of temp bits to get data (for char 8, int 32..)

int main(int argc, char **argv) {

	FILE *fd; //source file


	//check if source file exists
	if (!strcmp("-", argv[1]) ){
		fd = stdin;
	} else{
		fd = fopen(argv[1], "r");
		if(fd == NULL){
			fprintf(stderr, "Error occurred");
			return(1);
		}
	}


	//envelope for lines process 
	while(fgets(buffer, BUFFER_SIZE, fd)!= EOF){
		char* line_pointer = fgets(buffer, BUFFER_SIZE, fd);

		val = match(line_pointer, regex_pointer);




		// decide what to do print
		if (val) print line



		//get to next line
		while(*line_pointer != '\n'){
			fseek(fd, 1, SEEK_CUR);
			line_pointer ++;
		}
		fseek(fd, 1, SEEK_CUR);



	}




	return 0;

}











