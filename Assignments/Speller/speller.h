#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "dictionary.c"

#define DICT_L "dictionary_L.txt"
#define DELIM "!#$&()*+,-./:;<=>?@[]^_` {|}~"

double option_t(char *dict_name , char *file_name );
void option_p(const char *dict_name, const char *file_name);
void option_n(const char *dict_name, const char *file_name);
double calculate (const struct rusage* b , const struct rusage* a);
