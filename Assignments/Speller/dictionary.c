/* PROGRAM:  dictionary.c
   AUTHOR:
   DATE:     01/04/16
   TOPIC:    Dictionary implementation
   PURPOSE:
   NOTES:

*/

/**************************************************************************/
/* Declare include files
 **************************************************************************/
#include "dictionary.h"


/**************************************************************************/
/* Dictionary functions
 * int load_dictionary ( const char *dictionay_name, dictionary dict );
 *         Loads dictionary into memory from file dictionary_name
 *         Return the number of words in the dictionary
 *                and dict points to a valid dictionary
 *                0 otherwise and dict points to NULL
 * int check_dictionary ( dictionary dict, const char *word );
 *         Returns 1 if the word is part of the dictionary
 * int size_dictionary ( dictionary dict );
 *         Returns the number of words in the dictionary
 * int unload_dictionary ( dictionary dict );
 *         Unloads dictionary from memory
 *         Returns 1 if successful, 0 otherwise
 **************************************************************************/
int load_dictionary   ( const char *dictionay_name, dictionary dict ){

	FILE* file;
	char* b = NULL;

	size_t len = 0;
	size_t read;


	printf("File name is : %s\n " , dictionary_name);
	file = fopen (dictionary_name , "r");

	if(file == NULL) {
			printf("Problem in gluiojil File reading !!! \n");
			exit(EXIT_FAILURE);
	}
	while ((read = getline(&b , &len , file)) != -1 ){
			int length = strlen(b);
			b[length-1] = '\0';

			int a = trie_insert (&dict  , b);
			if ( a == 0 ){
				 dict = NULL;
					fclose (file);
					return 0;
			}
	}

	fclose (file);
	return 1;
}
/**************************************************************************/
int check_dictionary  ( dictionary dict, const char *word ) {

	int i ;
	int length = strlen (word);
	for (i = 0; i<length; i++){

			if(word[i] != '\'')
			word[i] = tolower(word[i]);
	}
			if(trie_contains(dict , word) == 1) {
			return 1;
	} else {
			return 0;
	}
}
/**************************************************************************/
int size_dictionary   ( dictionary dict ) {

	    int count;
	    count = trie_size(dict);

		return count;
	}
/**************************************************************************/
int unload_dictionary ( dictionary dict ) {

	int unload = trie_destroy(&dict);

	if(unload == 1) {
		return 1;
	} else {
			return 0;
	}
}
