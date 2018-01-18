/* PROGRAM: Turtle Data types
   AUTHOR: Hasan Skaiky
   DATE:     08/03/2017
   TOPIC: C program that process commands for a file and output a postscript file
   PURPOSE:  main
   NOTES:

*/


#include<stdlib.h>
#include<math.h>
#include<stdio.h>
#include <time.h>

#define M_PI 3.14

/*Structures*/
typedef struct {
	float r, g, b;
} colour_t;

typedef struct {
	double x;
	double y;
	double dir;
} turtle_t;

typedef struct {
colour_t colour;
	int down;
	int filled;
} pen_t;



/*Prototype*/
void turtle_reset( turtle_t *t);
void pen_reset( pen_t *p );
int  process_commands( turtle_t *t, pen_t *p );
int  valid_colour(colour_t c);
void pen_fill(pen_t*p);
void turtle_state(turtle_t t, pen_t p);
void set_ps_header( int w, int h );
void set_ps_display( void );
void set_pen_color( pen_t *p, colour_t c );
int roll (int max);
void turtle_goto( turtle_t *t, float x, float y );
void turtle_square( turtle_t *t, int size );
void turtle_turn( turtle_t *t, float angle );
void turtle_walk( turtle_t *t, int d );
void turtle_row( turtle_t *t, int count, int size );
void turtle_polygon( turtle_t *t,pen_t *p, int count, int size );
void turtle_grid( turtle_t *t, int rows, int columns, int size);
void turtle_random_walk( turtle_t *t,pen_t *p, int steps );
void turtle_fractal(turtle_t *t, int height, int width);

	/*Main*/
int main( void ) {


		turtle_t boo;
		pen_t pen;
		srand(time(NULL));
		turtle_reset( &boo );
		pen_reset( &pen );
		set_ps_header(595,841);
		process_commands(&boo,&pen);
		set_ps_display();


   return 0;
   
  }
/**********************************************************************/
/* turtle_reset( )
**********************************************************************/

void turtle_reset( turtle_t *t ){
	t-> x = t-> y = 0.0;
	t->dir = 0.0;

	return;
  }

	/* reset_pen()*/
void pen_reset(pen_t *p) {

	p->colour.r=0.0;
	p->colour.g=0.0;
	p->colour.b= 0.0;
	p->down =0.0;
	p->filled=0.0;

	return;
  }
       /*checks for valid colour*/
int valid_colour(colour_t c) {

 	 if ((c.r<1 && c.r >0) && (c.g <1 && c.g>0) &&(c.b<1 && c.b>0))
  	 return 1;

  return 0;
 }
      
void pen_fill(pen_t *p) {

    if (p->filled == 1) p->filled = 0;
    if (p->filled == 0) p->filled = 1;
 }


void set_ps_header( int w, int h ){

    fprintf( stdout, "%%!PSAdobe3.0EPSF3.0\n");
    fprintf( stdout, "%%%%BoundingBox: 0 0 %d %d\n\n", w, h );

  return;
 }

void set_ps_display( ){

  fprintf(stdout, "showpage\n" );

 }

void set_pen_color( pen_t *p, colour_t c ) {

	p->colour.r = c.r;
	p->colour.g = c.g;
	p->colour.b = c.b;
	fprintf(stdout, "%.2f %.2f %.2f setrgbcolor\n", c.r, c.g, c.b );

   return;
 }

 int roll(int max) {
     return 1 + (rand() % max);
 }

void turtle_goto( turtle_t *t, float x, float y ){
    t->x =x;
    t->y=y;
    fprintf(stdout,"%f %f moveto\n", x, y );

return;

 }

void turtle_square( turtle_t *t, int size ){
    float x2 = t->x-(size/2);
    float y2 = t->y-(size/2);
    fprintf(stdout,"%f %f %d %d ",x2,y2,size,size);
    fprintf(stdout,"rectfill\n\n" );
 }

void turtle_turn( turtle_t *t, float angle ){
    	t->dir += angle;
   while (t->dir < 0) {
        t->dir += 360;
    }

    while (t->dir > 360){
   	 t->dir -= 360;
 	}
 }

void turtle_walk( turtle_t *t, int d ){
   double x2;
   double y2;

     x2=t->x + d * cos(t-> dir * M_PI/180);
     y2=t->y + d * sin(t-> dir * M_PI/180);
     fprintf(stdout, "%f %f lineto\n",x2,y2 );
     t->x=x2;
		 t->y=y2;
 }

void turtle_row( turtle_t *t, int count, int size )	{
	int i;
	for (i=0; i<count ; i++)
	{
		turtle_square( t, size);
		t->x +=  size * 1.5;
	}

 } 

void turtle_polygon( turtle_t *t,pen_t *p, int count, int size ){
	float angle = 360/count;
	
	int i;
	i=1;


	if (count>2){
			while (i<=count){
					turtle_walk(t, size);
					turtle_turn(t,angle);
					i++;

			}

			fprintf(stdout, "closepath\n");

			if (p->filled == 1){
					fprintf(stdout, "fill\n");

			}
					
	}

	return;
} 


void turtle_grid( turtle_t *t, int rows, int columns, int size){
	 double space = size/2;
    int i = 1;

    double x1 = t->x ;

    double y1 = t->y ;

    while (i<=rows){

        turtle_goto(t,x1,y1);
        turtle_row(t, columns, size);

        y1 -=  size + space;
        i++;

}

}  
void turtle_random_walk(turtle_t *t, pen_t *p, int steps) {

int r_walk;
int i;
    
	colour_t c;
    	c.r = 0.0;
   	c.g = 0.0;
    	c.b = 0.0;
    	set_pen_color(p, c);

   	 for (i = 0; i < steps; i++) {
       	 r_walk = roll(4);

        switch (r_walk) {
           case 1:

                turtle_goto(t, t->x, t->y);
                turtle_walk(t, 10);
                fprintf(stdout,"stroke\n");

                break;

            case 2:

                turtle_turn(t, 90);

                break;

            case 3:

                turtle_turn(t, -90);

                break;

            case 4:
                c.r = (rand() % 10) * .1;
                c.g = (rand() % 10) * .1;
                c.b = (rand() % 10) * .1;
                set_pen_color(p, c);

                break;
        }
    }
}

void turtle_fractal(turtle_t *t, int height, int width){

    if (width == 0){
        turtle_walk(t, height);
    }else{
            turtle_fractal(t, height/3, width-1);
            turtle_turn(t, 60);
            turtle_fractal(t, height/3, width-1);
            turtle_turn(t, -120);
            turtle_fractal(t, height/3, width-1);
            turtle_turn(t, 60);
            turtle_fractal(t, height/3, width-1);
 	    turtle_turn(t, -120);
            turtle_fractal(t, height/3, width-1);
         
          
          

    }
}

	/*process_commands()*/
int process_commands( turtle_t *t, pen_t *p ) {
	
	char cmd;
	colour_t c;
	float x, y,angle;
	int d,ct,s,cl,r;
	

	while (( fscanf( stdin, "%c", &cmd )) != EOF ) {
	switch ( cmd ) {

		/*Colour*/
 	case 'C':

		fscanf( stdin, "%f %f %f\n", &c.r, &c.g, &c.b );
		if (valid_colour( c ) ==1)
		set_pen_color( p, c );

		break;

		/* Go To */
	case 'G':

		fscanf( stdin, "%f %f\n", &x, &y );
		turtle_goto( t, x, y );
		break;

		/* walk */
 	case 'W':

		fscanf( stdin,"%d\n",&d);
		turtle_walk(t,d);
		fprintf(stdout,"stroke\n");
		break;

		/* Turn */
	case 'T':

		fscanf(stdin, "%f\n", &angle);
		turtle_turn(t, angle);
             	break;

	/* Draw square*/
	case 'S':

		fscanf( stdin,"%d\n",&d);
		turtle_square(t,d);
		break;

	/* Draw row */
	case 'R':

		fscanf(stdin, "%d %d\n", &ct, &s);
		turtle_row(t, ct, s);
		 break;

	/* A grid of squares */
	case 'M':

		fscanf(stdin, "%d %d %d\n", &r, &cl, &s);
		turtle_grid(t, r, cl, s);
		 break;
		/* Random walk */

	case 'Z':
	
		fscanf(stdin, "%d\n", &d);
		turtle_random_walk(t,p,d);
		break;

		/* Polygon */
	case 'P':
	
		fscanf(stdin, "%d %d\n", &ct, &s);
		turtle_polygon(t,p, ct, s);
		fprintf(stdout,"stroke\n");
		break;

		/* Pen Fill*/
	case 'F':

    		pen_fill(p);
		break;

		/*fractal*/
	case 'X':
		fscanf(stdin, "%d %d\n", &ct, &s);
		turtle_fractal(t,ct,s);
		fprintf(stdout,"stroke\n");
		break;

	}/* end of swtich*/

    }/* end of while*/

	return 0;
}
