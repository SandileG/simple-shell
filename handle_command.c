#include "shell.h"
#include "path.h"

/**
 * handle_command - Handles the command entered by the user.
 * @token: The tokenized command.
 *
 * Return: void.
 */

void handle_command(char *token)
{
	char *path = getenv("PATH");
	char *command;
	int found = 0;

	while (path != NULL)
	{
		command = malloc(strlen(path) + strlen(token) + 2);
		if (command == NULL)
		{
			print_error("Unable to allocate command");
			exit(EXIT_FAILURE);
		}

		sprintf(command, "%s/%s", path, token);

		if (access(command, X_OK) == 0)
		{
			found = 1;
			break;
		}

		free(command);
		path = strtok(NULL, PATH_DELIM);
	}

	if (found)
	{
		execute_command(command, token);
	}
	else if (strcmp(token, "exit") == 0)
	{
		free(buffer);
		exit(EXIT_SUCCESS);
	}
	else if (strcmp(token, "env") == 0)
	{
		char **env = environ;

		while (*env != NULL)
		{
			printf("%s\n", *env);
			env++;
		}
	}
	else
	{
		print_command_not_found(token);
	}
}
