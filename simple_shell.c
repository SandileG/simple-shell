#include "shell.h"
#include "error.h"
#include "tokenizer.h"

/**
 * Main entry point for the simple shell program.
 *
 * Returns: 0 on success, EXIT_FAILURE on failure.
 */

int main(void)
{
	char input[BUFFER_SIZE];

	while (1)
	{
		printf("> ");

		if (fgets(input, sizeof(input), stdin) == NULL)
		{
			break;
		}

		char **tokens = tokenize(input);
		
		if (tokens == NULL)
		{
			fprintf(stderr, "Error: Tokenization failed\n");
			continue;
		}

		execute_command(tokens);

		for (int s = 0; tokens[s] != NULL; s++)
		{
			free(tokens[s]);
		}

		free(tokens);
	}

	return (0);
}

/**
 * execute_command - Handles execution of commands entered by the user.
 *
 * @param tokens: An array of tokens representing the user's input.
 * 
 * Return: Terminates shell process - exit.
 */

void execute_command(char **tokens)
{
	if (strcmp(tokens[0], "exit") == 0)
	{
		int exit_status = 0;

		if (tokens[1] != NULL && sscanf(tokens[1], "%d", &exit_status) == 1)
		{
			exit(exit_status);
		}
		else
		{
			exit(0);
		}
		else if (strcmp(tokens[0], "setenv") == 0)
		{
			if (tokens[1] == NULL || tokens[2] == NULL)
			{
				fprintf(stderr, "Error: Invalid syntax for setenv\n");
				return;
			}

			if (setenv(tokens[1], tokens[2], 1) < 0)
			{
				fprintf(stderr, "Error: Failed to set environment variable\n");
			}
			else if (strcmp(tokens[0], "unsetenv") == 0)
			{
				if (tokens[1] == NULL)
				{
					fprintf(stderr, "Error: Invalid syntax for unsetenv\n");
					return;
				}
				if (unsetenv(tokens[1]) < 0)
				{
					fprintf(stderr, "Error: Failed to unset environment variable\n");
				}
				else
				{
					/* Handle other commands here. */
				}
			}
		}
	}
}
