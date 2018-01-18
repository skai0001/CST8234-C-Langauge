/* PROGRAM:  sdt:  Stack Data Type
   AUTHOR:   
   DATE:     24/01/2017
   TOPIC:     
   PURPOSE:  main 
   NOTES:    
             
*/

#include "stack.h"
#include <stdlib.h>
#include <time.h>
#define SIZE_A 10

int numRandom(int min, int max );
/**************************************************************************/
/* main( )
 **************************************************************************/
   int main( ) {

    stack_t stack  = { NULL, 0, 0 };
    stack_t stack2  = { NULL, 0, 0 };
    stack_t dest = {NULL,0,0 };

    int i, num;

    stack_init(&stack, SIZE_A);
    stack_init(&stack2, SIZE_A);



    srand( time( NULL ) );


    for( i = 0; i < SIZE_A; i++ ) {
        num = numRandom( 1, 100 );
            stack_push( &stack, num );


        }

        for( i = 0; i < 9; i++ ) {
            num = numRandom( 1, 100 );
            stack_push(&stack2, num );

            }


    printf("Stack elements are: \n");
    stack_print( stack );
    stack_print(stack2);

    stack_merge(&dest,&stack,&stack2);
    return (EXIT_SUCCESS);
}


/**************************************************************************/

/**************************************************************************/
/* int numRandom(int min, int max );
 **************************************************************************/
int numRandom(int min, int max ) {

	return ( min + rand() % ( max - min + 1 ) );
}



