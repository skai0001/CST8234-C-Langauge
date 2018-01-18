/* PROGRAM:  particle header
   AUTHOR:  Hasan Skaiky 	
   DATE:   March 26 2017
   PURPOSE:  Assignment 2
*/



/**************************************************************************/
/* Macro Defines
**************************************************************************/
#define DFLT_INIT_NUM_PARTICLES 50
#define DELTA_LIFE_SPAN 1


/**************************************************************************/
/* Declare Structures
**************************************************************************/
typedef struct colour
{
  float r;
  float g;
  float b;
  float a;
}colour4_t;


struct vector
{
  float x,y,z;
};
typedef struct vector Point3D;
typedef struct vector Vector3D;

typedef struct particle
{
  colour4_t         col;
  Point3D           pos;
  Vector3D          dir;
  Vector3D          spd;
  int               lifespan;
  int               size;
  struct particle*  next;
}particle_t;


/**************************************************************************/
/* Function prototypes
**************************************************************************/
int particle_init( struct particle* p );
int particle_add( struct particle **head );
int particle_remove( struct particle* p );
int particle_destroy( struct particle **head );
int particle_update( struct particle **head );

int get_random_int(int r);
