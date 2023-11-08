#include "getline.h"

/**
 * my_getline - Reads a line of input from the specified stream.
 * @stream: The stream to read from.
 *
 * Return: Pointer to allocated line buffer, or NULL on error or end of file.
 */

char *my_getline(FILE *stream)
{
	char *line = NULL;
	int line_size = 0;
	char c;

	while ((c = fgets(stream)) != EOF && c != '\n')
	{
		if (line_size >= buffer_length)
		{
			line  = realloc(line, line_size + BUFFER_SIZE + 1);
			line_size += BUFFER_SIZE;
		}

		line[line_size++] = c;
	}

	if (c == EOF && line_size == 0)
	{
		return NULL;
	}

	if (line_size >= buffer_length)
	{
		line = realloc(line. line_size + 1);
	}

	line[line_size] = '\0';
	buffer_index = 0;
	buffer_length = 0;

	return (line);
}
