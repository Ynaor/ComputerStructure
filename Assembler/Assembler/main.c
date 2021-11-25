#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <stdlib.h>
#include "assembler_defines.h"  // header file for this specific project, containing all relevant data structures.
#include "functions.h"


int main() {

   
    static Instruction instructionsArr[INSTRUCTION_MAX_LEN] = { 0 }; // creating a new instructions list and initizliaing all values to zero
    static Label LabelsArr[NUMBER_OF_MEMORY_ELEMETS] = { 0 };
    static int dataMemArr[DATA_MEMORY_CELLS] = { 0 };

    return 0;

    }