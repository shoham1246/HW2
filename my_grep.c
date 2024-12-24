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
 
 #define BUFFER_SIZE 1024 //number of temp bits to get data (for char 8, int 32..)


int match(char* line_pointer , char* regex_pointer);

int main(int argc, char **argv) {

	FILE *fd; //source file


	//check if source file exists
	if (!strcmp("-", argv[1]) ){
		fd = stdin;
	} else{
		fd = fopen(argv[1], "r");
		printf("i have file\n");
		if(fd == NULL){
			fprintf(stderr, "Error occurred");
			return(1);
		}
	}

	char* regex_pointer = argv[2];

	printf("\n");


	//envelope for lines process 
	int is_line_good = 0;
	char buffer[BUFFER_SIZE];
	while(fgets(buffer, BUFFER_SIZE, fd)!= NULL){


		char* line_pointer = buffer;

		is_line_good = match(line_pointer, regex_pointer);


		// decide what to do print
		if(is_line_good){
			//print line
			char* print_line_pointer = line_pointer; 
			while(*print_line_pointer != '\n' && *print_line_pointer!= '\0'){
				fprintf(stdout, "%c", *print_line_pointer);
				print_line_pointer ++;
			}
			fprintf(stdout, "\n");
		}


		//get to next line


	}



	return 0;

}


int match(char* line_pointer , char* regex_pointer){

	char* new_line_pointer = line_pointer;
	char* new_regex_pointer = regex_pointer;
	if(*new_regex_pointer == '\0'){
		//regex is finished, we found a line tp print!
		return 1;
	}

	//special regex char $ 
	if(*new_regex_pointer == '$'){
		//the wanted finish string was already compared with the line
		return 1;
	}

	if(*line_pointer == '\n'){
		//we didint finished the regex - the line is not good
		return 0;
	}

	//special regex char ^ 
	if(*new_regex_pointer == '^'){
		//check if the wanted start string is in current line
		return match(new_line_pointer, new_regex_pointer + 1);
	}



	//special regex char . 
	if(*new_regex_pointer == '.'){
		//ignore whatevere char is between #.# every char is allowed
		return match(new_line_pointer +1 , new_regex_pointer + 1);
	}


	//compare chars of regex and line
	if(*new_line_pointer == *new_regex_pointer){
		return match(new_line_pointer + 1, new_regex_pointer + 1);
	}


	//if chars not equal we try to advance the line pointer
	if(*new_line_pointer != *new_regex_pointer){

		int was_pattern_found = match(new_line_pointer +1, new_regex_pointer);
		//if the wanted regex pattern was found elsewhere in the line
		if(was_pattern_found == 1){
			return 1;
		} else{
			return 0;
			//because some pattren wasnt found
		}

	}

	return 0;
}









