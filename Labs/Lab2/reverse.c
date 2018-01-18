/* PROGRAM: reverse.c  
   AUTHOR:  Hasan Skaiky
   DATE:    Jan 21/2017
   PURPOSE: This is a program is to reverse the number that is inputed by the user.
   LEVEL OF DIFFICULTY: 4
   CHALLENGES: The math part .
   HOURS SPENT: 3 hours             
*/


#include <stdio.h>
 

int reverse( int);          
  

   int main()
   {
       int num = 0 ;
       printf("Enter a number:");
       scanf("%d",&num);
       printf("Reverse Number is:%d\n",reverse(num));
       return 0;
   }

  int reverse(int revNum)
    {
int x = 0 ; 
while (revNum){
x = x*10 ; 
x = x + revNum%10;
revNum = revNum/10;
}
return x ;
}

