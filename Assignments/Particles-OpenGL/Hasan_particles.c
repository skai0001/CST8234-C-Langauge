/* PROGRAM:  particle
   AUTHOR:   Hasan Skaiky
   DATE:     March 26 2017 
   PURPOSE: create linkedlist of particles ( remove nodes , destroy whole linkedlist , and update it )
*/

/**************************************************************************/
/* Declare include files
**************************************************************************/
#include "Hasan_particles.h"
#include <stdlib.h>
#include <time.h>


/*******************************************************************************
 * FUNCTION : particle_init
 * PURPOSE  : initialize the properties of a single particle
 * INPUT    : pointer to the particle structure to be initialized
 * OUTPUT   : returns -1 on error, 0 on success
 * NOTES    :
 *******************************************************************************/
int particle_init( struct particle* p ) {

   p->col.r = (rand() % 10) * .1;
   p->col.g = (rand() % 10) * .1;
   p->col.b = (rand() % 10) * .1;
   p->col.a = 1.0;

   p->pos.x = (rand() % 400)-200.0;
   p->pos.y = 100.0;
   p->pos.z = 0.0;

   p->dir.x = 0.0;
   p->dir.y = 1.0;
   p->dir.z = 1.0;

   p->spd.x = (rand() % 10)+2;
   p->spd.y = (rand() % 10)+2;
   p->spd.z = 1.0;

   p->lifespan= 1;
   p->size= 1; 
 return 0 ;
}

/*******************************************************************************
 * FUNCTION : particle_add
 * PURPOSE  : add a particle to the dynamic particle linked list
 * INPUT    : struct particle *head. Head of the particle list
 * OUTPUT   : returns -1 on error, 0 on success
 * NOTES    : Calls particle_init()
 *******************************************************************************/
int particle_add( struct particle **head ) {

 particle_t *new;

	if ( ( new = (particle_t *) malloc( sizeof( particle_t) ) ) == NULL )
 	   return -1; 

 	 particle_init(new);
  	 new->next = *head;
	*head=new;
  	

  return 0;

} 


/*******************************************************************************
 * FUNCTION : particle_remove
 * PURPOSE  : remove a specific particle from the dynamic particle linked list
 * INPUT    : pointer to the particle to remove
 * OUTPUT   : returns -1 on error, 0 on success
 * NOTES    : Particle can be situated in any place in the list.
 *            Usually deleted becuase the lifespan ran out
 *******************************************************************************/
int particle_remove( struct particle *p ) {

   particle_t *curr = p;
   particle_t *temp; 


	 if (curr->next == NULL) {
	    return -1 ;
	}
	
	 if (curr->next == NULL ) {
             curr = NULL; 
 	     return 0 ; 
	} 
	temp = curr->next;
	curr->next = temp->next;	
	free(temp);

  
  return 0;
}


/*******************************************************************************
 * FUNCTION : particle_destroy
 * PURPOSE  : free memory used by the dynamic particle linked list
 * INPUT    : struct particle **head. Head of the particle list
 * OUTPUT   : returns -1 on error, the number of particles destroyed on success
 * NOTES    : removes all particles from the list
 *            Calls particle_remove
******************************************************************************/
int particle_destroy( struct particle **head )
{
   particle_t *prev;
  	int count = 0;

  	if (*head == NULL)
  		return -1;

  		while (*head != NULL) {
  			prev = *head;
  			*head = prev -> next;
  			particle_remove(prev);
  			count++;
  		}
  		return count;

}


/*******************************************************************************
 * FUNCTION : particle_update
 * PURPOSE  : update the particles properties to be rendered in the next frame
 * INPUT    : struct particle **head. Head of the particle list
 * OUTPUT   : returns -1 on error, 0 on success
 * NOTES    : Creativity and more Creativity here for you !!!
 *******************************************************************************/
int particle_update( struct particle **head ) {	
 
	struct particle* temp;
	temp = *head;

	if(temp == NULL)  return -1;
	
		while(temp != NULL){
			
		
			temp-> pos.y -= ( temp->spd.y * temp -> dir.y);
			
			if(temp -> pos.y <= -100){
				
				particle_init(temp);
                                 
			}
			temp->dir.x += 0.5;
			
			temp = temp->next;
			
		}
		return 0;
}

/*************************************************
 * FUNCTION  : get_random_int
 * PURPOSE  : generates random numbers
 * INPUT    : int r 
**************************************************/

int get_random_int(int r){

return (rand() % r);
}

