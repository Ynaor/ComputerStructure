#pragma once
#include "assembler_defines.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "functions.h"


void loadInstructions(char* file_name, Instruction* instructionsArr, Label* LabelsArr, int* dataMemArr) {
	/*
	This function loads is the master function, in charge for loading the assembler file, loading everything into the memory and
	creating memory map.
	*/
	FILE* raw_file;			// pointer that will point to the raw assembler file in memory
	int PC = 0;				// Will represent the value of the PC register
	int line_type_id = 0;   // Will represent the type of the current line: empty = 0, macro = 1, label = 2, command = 3





	raw_file = fopen(file_name, "r"); // reading raw assembler file into our program
	if (raw_file == NULL) {  // file didn't load successfully
		printf("Could not load assembler file. exiting...\n");
		exit(1);
	}


	// starting to parse every line of the input file
}





void adjustLineFormat(char *line) {
	/*
	* will remove all comments from a specific string and converting all characters to lower-case
	*/
	int i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '#') {
			line[i] = '\0'; // ignore all chars after '#' and shorten the string by placing '\0'
			return;         // nothing else to do in this line
		}
		else {
			line[i] = tolower(line[i]);
			i++;
		}
	}
}
int convertStrtoInt(char* number) {
	/*
	* This function will get a number in a string format, and will convert in to an integer
	*/

	int hex_suffix; 
	hex_suffix = strstr(number, '0x' != NULL) || strstr(number, '0X' != NULL); // if the number has '0x' suffix, it is in hexadecimal format. else: decimal

	if (hex_suffix == 1){
		return (int)strtol(number, NULL, 16); // converting to long, and then using static casting to int
	}
	else { 
		return (int)strtol(number, NULL, 10); // this is a decimal format number
	}

}
int getLineTypeId(char* line) {
	/*
	* This function will check the type of the line by the leading characters of the line.
	* line types: empty = 0, macro = 1, label = 2, command = 3
	*/
	
	while (isspace(*line)) line++;        // if the leading characters are whitespaces, ignore them and move the line pointer to the next char
	if (line == NULL || *line == '\0') {  // Null line or we have reached the end of the line
		return 0;
	}
	else if (*line == '.') {					  // This line is a macro definition
		return 1;
	}
	else if (strstr(line, ':') != NULL) {        // This is a label
		return 2;
	}
	else{										 // This is a command
		return 3;
	}
}