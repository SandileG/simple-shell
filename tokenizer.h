#ifndef TOKENIZER_H
#define TOKENIZER_H

#define MAX_TOKENS 128
#define MAX_TOKEN_LENGTH 32

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char **tokenize(char *input);

#endif /* TOKENIZER_H */
