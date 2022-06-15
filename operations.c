#include "monty.h"
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
