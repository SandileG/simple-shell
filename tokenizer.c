#include "tokenizer.h"


/**
 * tokenize - Tokenizes the given input string into an array of tokens.
 * @input: The input string to tokenize.
 *
 * Return: An array of tokens, or NULL on error.
 */
char **tokenize(char *input)
{

	char **tokens = malloc(sizeof(char *) * MAX_TOKENS);
	if (tokens == NULL)
	{
		fprintf(stderr, "Error: Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}


	int token_count = 0;
	int token_start = 0;
	int in_quotes = 0;


	for (int s = 0; input[s] != '\0'; s++)
	{
		if (in_quotes)
		{
			if (input[s] == '"')
			{
				in_quotes = 0;
			}
		}
		else
		{
      			if (isspace(input[s]))
			{
				if (s > token_start)
				{
					int token_length = s - token_start;
					char *token = malloc(token_length + 1);

					if (token == NULL)
					{
						fprintf(stderr, "Error: Memory allocation failed\n");
						exit(EXIT_FAILURE);
					}

					strncpy(token, input + token_start, token_length);
          				token[token_length] = '\0';

					tokens[token_count++] = token;

					if (token_count == MAX_TOKENS)
					{
						fprintf(stderr, "Error: Maximum token limit reached\n");
						exit(EXIT_FAILURE);
					}
				}

				token_start = s + 1;
			}
			else if (input[s] == '"')
			{
				in_quotes = 1;
			}
		}
	}

	if (!in_quotes && token_start < strlen(input))
	{
		int token_length = strlen(input) - token_start;
		char *token = malloc(token_length + 1);
    		
		if (token == NULL)
		{
      			fprintf(stderr, "Error: Memory allocation failed\n");
			exit(EXIT_FAILURE);
		}

		strncpy(token, input + token_start, token_length);
		token[token_length] = '\0';

		tokens[token_count++] = token;

		if (token_count == MAX_TOKENS)
		{
			fprintf(stderr, "Error: Maximum token limit reached\n");
			exit(EXIT_FAILURE);
		}
	}

	tokens[token_count] = NULL;

	return (tokens);
}
