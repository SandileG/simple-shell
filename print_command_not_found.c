#include "shell.h"

/**
 * print_command_not_found - Prints command not found error
 * @token: The tokenized command
 *
 * Return: void
 */

void print_command_not_found(char *token)
{
	printf("%s: command not found\n", token);
}
