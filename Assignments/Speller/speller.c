#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/time.h>
#include <sys/resource.h>

#include "dictionary.h"
#include "speller.h"

/********************main****************/
int main(int argc, char *argv[]) {

	switch (argc) {
		case 3:

			if (strcmp(argv[1], "-t") == 0) {

			} else if (strcmp(argv[1], "-p") == 0) {
				option_p(DICT_L, argv[2]);
			} else if (strcmp(argv[1], "-n") == 0) {
				option_n(DICT_L, argv[2]);
			} else if (strcmp(argv[1], "-np") == 0) {
				option_n(DICT_L, argv[2]);
				option_p(DICT_L, argv[2]);
			}

			break;

		case 4:

			if (strcmp(argv[1], "-t") == 0) {

      }  else if (strcmp(argv[1], "-t") == 0) {
          option_p(argv[2], argv[3]);
			} else if (strcmp(argv[1], "-p") == 0) {
				option_p(argv[2], argv[3]);
			} else if (strcmp(argv[1], "-n") == 0) {
				option_n(argv[2], argv[3]);
			} else if (strcmp(argv[1], "-np")) {
				option_p(argv[2], argv[3]);
				option_n(argv[2], argv[3]);
			}

			break;

		default:
			perror("");
	}

	return 0;

}
double option_t(char *dict_name , char *file_name ){

    struct rusage a;
    struct rusage b;
    dictionary dict = NULL;
    dict = trie_new();
    getrusage( RUSAGE_SELF , &a);
    option_n (dict_name , file_name);
    unload_dictionary(dict);
    getrusage( RUSAGE_SELF , &b);
    return calculate(&a , &b);
}

void option_p(const char *dict_name, const char *file_name) {
	FILE *file;
	char *line = NULL;
  size_t len = 0;
	int misspelled = 0;
	int wordTotal = 0;
	char *word;
  dictionary dict = trie_new();
  int load = load_dictionary(dict_name, dict);

	if(load == 1){
    	if(! (file = fopen(file_name, "r") ) ){
        	perror ("open");
        	exit(EXIT_FAILURE);
    	}

    	while ((getline(&line, &len, file)) != EOF){

        	word = strtok(line, DELIM );

	        while (word) {
	        	wordTotal++;
	            if(check_dictionary(dict, word) == 0){
	                misspelled++;
	            }
	            word = strtok(NULL, DELIM);
	    	}
    	}
    } else {
    	perror("Failed to load dictionary\n");
    }

    fclose (fin);

    printf("Number of  words in dictionary: %d\n", size_dictionary(dict));
    printf("NUmber of  words in text: %d\n", wordTotal);
    printf("Misspelled words: %d\n", misspelled);
}

void option_n(const char *dict_name, const char *file_name) {
	FILE *file;
	char *line = NULL;
    size_t len = 0;
	int numLine= 0;
	char *word;
    dictionary dict = trie_new();

    int load = load_dictionary(dict_name, dict );

	if(load == 1){
    	if(! (file = fopen(file_name, "r") ) ){
        	perror ("open");
        	exit(EXIT_FAILURE);
    	}

    	while ((getline(&line, &len, file)) != EOF){

    		numLine++;
        	word = strtok(line, DELIM );

	        while ( word ) {
	            if(check_dictionary (dict , word) == 0){
	            	printf("Misspelled word is on : %d: %s\n", numLine, word);
	            }
	            word = strtok(NULL, DELIM);
	    	}
    	}
    } else {
    	perror("Can't load \n");
    }

    fclose (fin);
}

double calculate (const struct rusage* b , const struct rusage* a){

if(b == NULL || a == NULL) return 0.0;


return ((((a->ru_utime.tv_sec * 1000000 + a->ru_utime.tv_usec) -
        (b->ru_utime.tv_sec * 1000000 + b->ru_utime.tv_usec))+
        ((a->ru_stime.tv_sec * 1000000 + a->ru_stime.tv_usec)-
        (b->ru_stime.tv_sec * 1000000 + b->ru_stime.tv_usec)))
        / 1000000.0);

}
