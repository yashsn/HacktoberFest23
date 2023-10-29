#include<stdio.h>
#include<stdlib.h>
int main ()
{
int a,b,ch;
printf("Enter first number:");
scanf("%f",&a);
printf("\nEnter second number:");
scanf("%f",&b);
printf("\nMENU\n**********\nEnter 1 to add numbers\nEnter 2 to subtract numbers\nEnter 3 to multiply numbers\nEnter 4 to divide numbers\nEnter 0 to exit\n");
printf("\nEnter your choice:");
scanf("%f",&ch);
    switch (ch)
    {
     case 1:
     printf("\nAddition is %f",a+b);
     break;
     case 2:
     printf("\nSubtraction is %f",a-b);
     break;
     case 3:
     printf("\nMultiplication is %f",a*b);
     break;
     case 4:
     printf("\nDivision is %f",a/b);
     break;
     case 0:
     exit(0);
     break;
     default:
     printf("Not a valid option");
     break;
    }



return 0;
}