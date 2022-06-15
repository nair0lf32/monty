#include "monty.h"
/**
*main - entry point
*@argc: argument count
*@argv: array of arguments
*Return: EXIT_SUCCESS or EXIT_FAILURE!!!
**/
int main(int argc, char **argv)
{
stack_t *head;
stack_init(&head);
if (argc != 2)
{
printf("USAGE: monty file\n");
exit(EXIT_FAILURE);
} else {
read_file(argv[1], &head);
exit(EXIT_SUCCESS);
}
}
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
/**
*_push - pushes an element to the stack
*@head: pointer to pointer to stack_t
*@line_number: line number of the file
*Return: void
*/
void _push(stack_t **head, unsigned int line_number)
{
stack_t *new_node;
char *token = strtok(NULL, " \n");
if (token == NULL)
{
printf("L%d: usage: push integer\n", line_number);
return;
}
new_node = malloc(sizeof(stack_t));
if (new_node == NULL)
{
printf("Error: malloc failed\n");
exit(EXIT_FAILURE);
}
new_node->n = atoi(token);
new_node->prev = NULL;
new_node->next = *head;
if (*head != NULL)
{
(*head)->prev = new_node;
}
*head = new_node;
}
/**
* _pall - prints all the elements of the stack
* @head: pointer to pointer to stack_t
* @line_number: line number of the file
* Return: void 
*/
void _pall(stack_t **head, unsigned int line_number)
{
stack_t *temp = *head;
if (*head == NULL)
{
printf("L%d: stack empty\n", line_number);
return;
}
while (temp != NULL)
{
printf("%d\n", temp->n);
temp = temp->next;
}
}
