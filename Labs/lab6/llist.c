/* PROGRAM:  llist.c
   AUTHOR:   C. Ayala
   DATE:     20/10/11
   	         19/03/16
   TOPIC:    simple linked list implementation
   PURPOSE:  Simple data structures
   NOTES:

*/

/**************************************************************************/
/* Declare include files
 **************************************************************************/
#include "llist.h"

/**************************************************************************/
/* Provided functions
 **************************************************************************/

/**************************************************************************/
/* llist_push:  Add an element to the head of the list
 **************************************************************************/
int llist_push( node_t **headRef, int data ) {

	node_t *new;

	if ( ( new = ( node_t *) malloc( sizeof( node_t ) ) ) == NULL )
		return EXIT_FAILURE;

	new->data = data;
	new->next = *headRef;
	*headRef  = new;

	return 0;

}
/**************************************************************************/
/* llist_pop:   Removes first element of the list
 **************************************************************************/
void llist_pop   ( node_t **headRef ) {

	node_t *h = * headRef;

	if ( h == NULL ) return;

	*headRef = h->next;
	free( h );

	return;
}
/**************************************************************************/
/* llist_size:  Returns number of elements in the list
 **************************************************************************/
int  llist_size  ( node_t * head ) {

	int cnt = 0;

	struct node * tmp = head;

	while( tmp != NULL ) {
		cnt++;
		tmp = tmp->next;
	}
	return cnt;

}
/**************************************************************************/
/* llist_print:   Prints a list
 **************************************************************************/
void llist_print ( node_t * head ){

	int nodes = 0;
	struct node *current = head;


	fprintf( stdout, "{ " );
	while( current != NULL ) {
		fprintf( stdout, "%4d -->", current->data );
		nodes++;
		current = current->next;
	}
	fprintf( stdout, " NULL }\n" );

	fprintf(stdout, "Number of elements in the list: %d\n", nodes );

	return;

}

/**************************************************************************/
/* Functions to be implemented by you
 **************************************************************************/
int llist_contains ( node_t *h, int value ){

	while (h!=NULL)
	{
		if (h->data==value){
			return 1;
		}
		h = h->next;

	}
	return 0 ;

}
int  llist_count    ( node_t *h, int value ){
	int num = 0;
	struct node * current = head;
	while (current!=NULL)	{
		if (current->data == value){
	   num++;
		 current =current->next;
	}

}
return num;
}
/*************************************************/

/************************************************/
int  llist_find     ( node_t *h, int value ) {
int num=0;
node_t * temp =h;
while(temp!=NULL){
	if (temp->data==value){
		return num;
	}
	num++;
	temp=temp->next;
}
return -1;
}

int  llist_is_equal ( node_t *h1, node_t *h2 ){

	if (llist_size(h1) != llist_size(h2)) return 0;

	if (llist_size(h1) == llist_size(h2)){
	while (h1 != NULL){
	if (h1->data != h2->data) return 0 ;
		h1=h1->next;
	  h2=h2->next;
	}
    }
return 1;
}
/***************************************************/
int llist_addlast  ( node_t **href, int value ){/* new*/
 node_t * temp = *href;
 node_t * new ;
	if ( ( temp = ( node_t *) malloc( sizeof( node_t ) ) ) == NULL )
		return EXIT_FAILURE;

	new->data=value;
	new->next=NULL;

		 if (*hef==NULL){
			*href= new;
			return 1;
		} else {
           while ( temp !=NULL){

						 if (temp->next == NULL){

							 temp->next = new;
							 return 1;
						 }
						 temp=temp->next;
					 }
		}

return 0;
}


/***************************************************/

/*******************************************************/



/******************************************************/




int llist_insert   ( node_t **href, int value , int index ){


return 0;
}
void llist_remove   ( node_t **href, int value ){
}
void llist_free     ( node_t **href ){
}
