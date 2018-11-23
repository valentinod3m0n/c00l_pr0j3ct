#ifndef _INSTRUCTION_H
#define _INSTRUCTION_H

enum instruction_type {AR_LOG, MEMORY};
enum arlog_operation_type {ADD, SUB, MUL, DIV, AND, OR, XOR};
enum mem_operation_type {LW, SW};

typedef enum instruction_type instruction_t;
typedef enum arlog_operation_type arglog_operation_t;
typedef enum mem_operation_type mem_operation_t;

struct instruction{
	instruction_type type;
};

struct arlog_instruction{
	instruction_type type;
	arglog_operation_t operation;
	int rd;
	int rs;
	int rt;
};

struct mem_instruction{
	instruction_type type;
	mem_operation_t operation;
	int rd;
	int rs;
};

#endif
