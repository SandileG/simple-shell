#include "shell.h"

/**
 * split_path - Splits the input path into separate paths.
 * @path: The path to be split.
 *
 * Return: An array of strings containing individual paths.
 */

char **split_path(char *path)
{
	char *token;
	char *delim = ":";
	char *paths = strdup(path);
	int count = 0;
	char **result;

	token = strtok(paths, delim);

	while (token != NULL)
	{
		printf("%s\n", token);
		count++;
		token = strtok(NULL. delim);
	}

	free(paths);

	result = malloc((count + 1) * sizeof(char *));
	if (result == NULL)
	{
		fprintf(stderr, "Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(path, delim);
	count = 0;
	while (token != NULL)
	{
		result[count] = strdup(token);
		if (result[count] == NULL)
		{
			fprintf(stderr, "Memory allocation failed\n");
			exit(EXIT_FAILURE);
		}
		count++;
		token = strtok(NULL, delim);
	}
	result[count] = NULL;

	return (result);
}
