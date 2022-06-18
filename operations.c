#include "monty.h"
/**
*_push - pushes an element to the stack
*@head: pointer to pointer to stack_t
*@line_number: line number of the file
*Return: void
*/
void _push(stack_t **head, unsigned int line_number)
{
stack_t *new_node = malloc(sizeof(stack_t));
char *token;
if (new_node == NULL)
{
fprintf(stderr, "Error: malloc failed\n");
exit(EXIT_FAILURE);
}
token = strtok(NULL, DELIMS);
if (token == NULL || new_node == NULL)
{
fprintf(stderr, "Line %d: usage: push integer\n", line_number);
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
*_pall - prints all the elements of the stack
*@head: pointer to pointer to stack_t
*@line_number: line number of the file
*Return: nothing
*/
void _pall(stack_t **head, unsigned int line_number)
{
stack_t *temp = *head;
(void)line_number;
while (temp != NULL)
{
printf("%d\n", temp->n);
temp = temp->next;
}
}
