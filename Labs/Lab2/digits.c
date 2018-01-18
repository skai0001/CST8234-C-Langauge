#include <stdio.h>



int digits (int);

int main()
{
    int num  ;
    int d;
    printf("Enter an Integer!\n");
    scanf("%d",&num);
    d = digits(num);
    printf ("Number of Digits in %d is %d\n", num , d);
    return 0;
}

int digits (int x){
int c ;
c=0;
while (x){

    x = x/10;
    c++;
}
return c ;

}


