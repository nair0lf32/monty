#include "monty.h"
/**
*stack_init - initialize stack
*@head: pointer to pointer to stack_t 
*Return: void
*/
void stack_init(stack_t **head)
{
*head = NULL;
}
/**
*read_file - reads the file and executes the commands
*@filename: name of the file
*@head: pointer to pointer to stack_t
*Return: void
*/
void read_file(char *filename, stack_t **head)
{
FILE *fp;
char *line = NULL;
size_t len = 0;
ssize_t read;
int line_number = 1;
fp = fopen(filename, "r");
if (fp == NULL)
{
printf("Error: Can't open file %s\n", filename);
exit(EXIT_FAILURE);
}
while ((read = getline(&line, &len, fp)) != -1)
{
execute_command(line, head, line_number);
line_number++;
}
fclose(fp);
if (line)
free(line);
}
/**
*execute_command - executes the commands 
*@line: line of the file
*@head: pointer to pointer to stack_t
*@line_number: line number of the file
*Return: void
*/
void execute_command(char *line, stack_t **head, int line_number)
{
int i = 0;
instruction_t all_ops[] = {
{"push", _push},
{"pall", _pall},
{NULL, NULL}
};
char *token = strtok(line, " \n");
while (all_ops[i].opcode != NULL)
{
if (strcmp(token, all_ops[i].opcode) == 0)
{
all_ops[i].f(head, line_number);
break;
}
i++;
}
if (all_ops[i].opcode == NULL)
{
printf("L%d: unknown instruction %s\n", line_number, token);
}
}
