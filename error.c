#include "error.c"

void print_error(char *message)
{
	perror(message);
	exit(EXIT_FAILURE);
}
