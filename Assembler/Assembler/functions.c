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

	FILE* raw_file = fopen(file_name, "r"); // reading raw assembler file into our program

	if (raw_file == NULL) {  // file didn't load successfully
		printf("Could not load assembler file. exiting...\n");
		exit(1);
	}
}
