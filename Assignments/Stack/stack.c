/* FILE:     stack.c
   AUTHOR:   
   DATE:     18/01/2017
   TOPIC:     
   PURPOSE:  Basic Stack data type function implementations
   NOTES:    
             
*/

#include "stack.h"


/**************************** PART A***************************************/



int    stack_contains( stack_t s, data_t value);
int    stack_find( stack_t s, data_t value);
void   stack_print( stack_t stack );


/**************************************************************************/
/* stack_int
 *        Initializes a new set
 *        O( 1 ) operation
 *   PRE:
 *        There is enough memory allocated for set     
 *   To DO:
 *        ( 1 ) Allocate memory for an array of size elements
 *              -- Don't forget to check if memory is available
 *        ( 2 ) Set size to size
 *        ( 3 ) Set top to size ( last posititon )
 *   RETURN
 *        0 if init was OK
 *       -1 if init encountered an error ( only problem is memory allocation)
 **************************************************************************/
int    stack_init( stack_t *stack, int size ) {

	if ( stack->array ) return -1;

	if ( !( stack->array = ( data_t * ) malloc ( sizeof( int ) * size )))
		return EXIT_FAILURE;
	
	stack->size = size;
	stack->top = size;
	
	return 0;	
}
/**************************************************************************/
/* stack_free
 *        Deallocates memory associated with a stack
 *        It must set top and size to zero
 **************************************************************************/
void stack_free( stack_t *stack ){

	free(stack);
	stack->top=0;
	stack->size=0;
}
/**************************************************************************/
/* get_stack_size
 *        Returns the size of the stack
 *        O( 1 ) operation
 **************************************************************************/
int get_stack_size( stack_t stack ) {

	return stack.size;
}
/**************************************************************************/
/* get_stack_top
 *        Returns position of the top
 *        O( 1 ) operation
 **************************************************************************/
int get_stack_top( stack_t stack ) {

	return stack.top;
}
/**************************************************************************/
/* get_stack_elements
 *        Returns the numbers of items in the stack
 *        O( 1 ) operation
 **************************************************************************/
int get_stack_elements( stack_t stack ) {
	
	return (stack.size - stack.top);
}
/**************************************************************************/
/* is_stack_empty
 *        returns 1 if stack is empty, 0 otherwise
 *        stack is empty when top is size
 *        
 **************************************************************************/
int  is_stack_empty( stack_t stack ){
	
	if (stack.top == stack.size){

		return 1; 
	}
	return 0;
}
/**************************************************************************/
/* is_stack_full
 *        returns 1 if stack is full, 0 otherwise
 *        stack is full when top is zero
 *        
 **************************************************************************/
int is_stack_full( stack_t stack ){
	
	if (stack.top == 0) {
		return 1;
	} 
	return 0; 
}
/**************************************************************************/
/* stack_clear
 *        Removes all elements from a set (doesn't deallocate anything!).
 *        clear elements with value CLEAR
 *        top is set to last index ( size - 1 )
 *        This function could be called to initialize all elements to 
 *        the CLEAR value or to ERASE all the array information
 **************************************************************************/
void stack_clear( stack_t *stack){

int i ; 
	for ( i = 0; i <= stack->size-1;i++){
		stack->array[i]=CLEAR;
		/*free(stack);*/
		stack->top = stack->size;
	}
}
/**************************************************************************/
/* stack_push
 *        Adds an item to a stack ( always on the top )
 *        
 **************************************************************************/
int stack_push( stack_t *stack, data_t value ){
	
       if (stack->top > 0) {
		stack->top--;
		stack->array[stack->top] = value;
	return 1;
} 
	else return 0;

}
/**************************************************************************/
/* stack_pop
 *        removes an item to a stack ( always on the top )
 *        
 **************************************************************************/
int stack_pop( stack_t *stack ){
	
	 if (stack->top > 0 || stack->top < stack->size-1){
		free(stack);
		return stack->array[stack->top];
	} 
/*if (stack->top <= 0 || stack == NULL){ */
	
	return 0;

}
/**************************************************************************/
/* stack_peek
 *        shows the item on the top of the stack
 *        
 **************************************************************************/
data_t stack_peek( stack_t stack ){
	if (stack.top == stack.size){
		return -1 ; 
    } else 
	return stack.array[stack.top];
}
 /**************************************************************************/
/* stack_contains
 *        Returns true of value is a member of the stack
 *        It does not return the index where value is!
 * RETURN
 *        1 if the element is a member of the set
 *        0 otherwise
 **************************************************************************/
 int stack_contains( stack_t s, data_t value){

 int i ; 
	for ( i = 0 ; i < s.size ; i++){
		if (s.array[i]==value){
			return 1 ; 
		} 
	}
	return 0;
		
}
/**************************************************************************/
/* stack_find
 *        Returns the index where value is
 * RETURN
 *        index where the element is in the set
 *        -1 if not found
 **************************************************************************/
 int stack_find( stack_t s, data_t value){
 int i ; 
	for ( i = 0 ; i < s.size;i++) {
	if ( s.array[i] == value) {
 
	return i;
	}
     }  
	return -1; 
 }


/**************************************************************************/
/* stack_print
 *        prints the stack and its elements
 **************************************************************************/
void   stack_print( stack_t stack ) {

int i ; 
	for ( i = 0 ; i < stack.size ; i++) { 
	printf("%d\n",stack.array[i]);
	
	}
}

/*************************PART B***************************************/

/**********************************************************************/
/* stack_are_equal 
 *        Returns true if and only if stack1 is equal to stack2.
 *        Two stacks are equal if they have the same number of elements
 *        and all elements are in the same position
 **********************************************************************/
int stack_are_equal( stack_t s1, stack_t s2){
int i ; 
	if (s1.size == s2.size ){
	for ( i =s1.top; i< s1.size ; i++){
	if (s1.array[i] != s2.array[i]){
		
		return 0;
	    }
	}
} 	
    return 1;
}
/*********************************************************************/
/* stack_are_disjoint
 *        Returns true if and only if stack1 and stack2 don't contain any 
 *        of the same items
 *********************************************************************/
int stack_are_disjoint( stack_t s1, stack_t s){
int i ,j; 
	
		for ( i = 0;i< s1.top ; i++){
		for (j=0 ;j < s.top;j++) {
	if (s1.array[i] == s.array[i]) {
		return 0;
	}
    }
  }
return 1;
}

/*************************PART C***************************************/
/*********************************************************************/
/* stack_merger
 *        merges stack1 and stack2, storing it in dest.
 *        stack1 and stack2 are freed 
 *********************************************************************/
void stack_merge( stack_t *dest, stack_t *s1, stack_t *s2){

    int c;
    int j;
    dest->size = (s1->size + s2->size);
    dest->top = dest->size;
   

    stack_init(dest, dest->size);


    if (s1->array != NULL && s2->array != NULL){

        for (c=s2->size-1; c>=s2->top; c--){
            stack_push(dest,s2->array[c]);
        }

        for (j=s1->size-1; j>=s1->top; j--){
            stack_push(dest,s1->array[j]);

        }

    }

    free(s1);
    free(s2);

}




