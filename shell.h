#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


#define BUFFER_SIZE 256
#define PATH_DELIM ":"

int tokenize(char *input, char ***tokens);
void execute_command(char **tokens);

#endif /* SHELL_H */
