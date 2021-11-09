#pragma once

#include <string.h>

#ifndef DEFINES

#define SIMP_REGISTERS  16
#define DATA_MEMORY_CELLS  4096
#define NUMBER_OF_MEMORY_ELEMETS 1024
#define LABEL_MAX_LEN  51
#define INSTRUCTION_MAX_LEN  501




enum eREGISTERS {
	// Will map registers names and their number

	$zero, // Constant zero 
	$imm1, // Sign extended immediate 1
	$imm2, // Sign extended immediate 2
	$v0,   // Result value
	$a0,   // Argument register
	$a1,   // Argument register
	$a2,   // Argument register
	$t0,   // Temporary register
	$t1,   // Temporary register
	$t2,   // Temporary register
	$s0,   // Saved register
	$s1,   // Saved register
	$s2,   // Saved register
	$gp,   // Global Pointer (static data)
	$sp,   // Stack Pointer
	$ra    // Return Address
};


typedef struct Instruction {

	unsigned int opcode;
	unsigned int rd;
	unsigned int rs;
	unsigned int rt;
	unsigned int rm;
	unsigned int immediate1;
	unsigned int immediate1_type;
	unsigned int immediate2;
	unsigned int immediate2_type; //STODO: map relevant values for the type fields
	//char jump_to_label; //TODO: see if can be removed

}Instruction;

typedef struct Label {

	unsigned int PC;
	char label_name[LABEL_MAX_LEN];

}Label;


#endif