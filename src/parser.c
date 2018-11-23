/* 
 * This is a parser 4FUN.
 * -valentinod3m0n
 */

#include "instruction.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//We can probably tweak this.
#define	BUFFER_MAX	128

//Segments
enum {DATA = 0, TEXT = 1};

void load_and_parse(char* file_name){
	FILE* f;

	char buffer[BUFFER_MAX] = {0};

	char* token;
	char* delim = " \t\r\n";

	int current_segment = TEXT;
	
	f = fopen(file_name, "r");
	if (f == NULL){
		perror("open");
		exit(1);
	}
	
	while (fgets(buffer, BUFFER_MAX, f)){
		//The first call to strtok has the string, the following will have just NULL.
		//The condition will be token != NULL
		for (token = strtok(buffer, delim); token; token = strtok(NULL, delim)){
			//Comments
			if (token[0] == '#')
				break;
			
			//Segments
			if (strcmp(token, ".text") == 0){
				current_segment = TEXT;
				break;
			}

			if (strcmp(token, ".data") == 0){
				current_segment = DATA;
				break;
			}

			//Extern
			if (strcmp(token, ".global") == 0)
				break;
			
			//Label
			if (token[strlen(token) - 1] == ':'){
				//Add the label
				//Remember that we can have a label followed by a instruction.
				continue;
			}

			//Variable
			if (token[0] == '.'){
				//Add variable
				//Need to keep track of .data size.
				break;
			} else {
				//Instruction
				//Need to keep track of .text size.
				break;
			}
		}

		//We don't know what will remain in the buffer.
		memset(0, buffer, BUFFER_MAX);
	}
}

struct instruction* parse_instruction(char* line){
	




}
