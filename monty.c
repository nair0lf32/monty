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
