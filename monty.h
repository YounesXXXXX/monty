#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
/**
 * struct stack_sx - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_sx
{
	int n;
	struct stack_sx *prev;
	struct stack_sx *next;
} stack_t;
/**
 * struct bus_sx - variables -args, file, line content
 * @arg: value
 * @file: pointer to monty file
 * @content: line content
 * @lifi: flag change stack <-> queue
 * Description: carries values through the program
 */
typedef struct bus_sx
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
}  bus_tx;
extern bus_tx bus;
/**
 * struct instruction_sx - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_sx
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_tx;
char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
ssize_t getstdin(char **lineptr, int file);
char  *clean_line(char *content);
void f_pushx(stack_t **head, unsigned int number);
void f_pallx(stack_t **head, unsigned int number);
void f_pintx(stack_t **head, unsigned int number);
int execute(char *content, stack_t **head, unsigned int counter, FILE *file);
void free_stack(stack_t *head);
void f_popx(stack_t **head, unsigned int counter);
void f_swapx(stack_t **head, unsigned int counter);
void f_addx(stack_t **head, unsigned int counter);
void f_nopx(stack_t **head, unsigned int counter);
void f_subx(stack_t **head, unsigned int counter);
void f_divx(stack_t **head, unsigned int counter);
void f_mulx(stack_t **head, unsigned int counter);
void f_modx(stack_t **head, unsigned int counter);
void f_pcharx(stack_t **head, unsigned int counter);
void f_pstrx(stack_t **head, unsigned int counter);
void f_rotlx(stack_t **head, unsigned int counter);
void f_rotrx(stack_t **head, __attribute__((unused)) unsigned int counter);
void addnodex(stack_t **head, int n);
void addqueuex(stack_t **head, int n);
void f_queuex(stack_t **head, unsigned int counter);
void f_stackx(stack_t **head, unsigned int counter);
#endif
