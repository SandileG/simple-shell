#include "shell.h"

/**
 * execute_command - Executes the command with arguments
 * @command: The command to be executed
 * @token: The tokenized command
 *
 * Return: void
 */

void execute_command(char *command, char *token)
{
	if (fork() == 0)
	{
		execve(command, &token, NULL);
		perror("execve");
		exit(EXIT_FAILURE);
	}
	wait(NULL);
}
