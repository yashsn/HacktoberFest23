#include<stdio.h>
int main(){
int a[10]={0}; //Declare array
int n,i,min,max; //Initialise variables
printf("Enter side of array: "); //Size of array as defined by the user
scanf("%d",&n);

printf("\nEnter elements of the array:\n");
for (i=0;i<=n;i++)
{
scanf("%d",&a[i]); //Entering elements of the array
}
min=max=a[0]; //Variable to store the min and max elements
for (i=1;i<=n;i++)
{
if(min>a[i])
{
min=a[i]; //to check minimum number
}
}
for (i=1;i<=n;i++)
{
if(max<a[i])
{
max=a[i]; //to check maximum number
}
}
printf("\nMinimum number is:%d",min); //Printing min number
printf("\nMaximum number is:%d",max); //Printing max number
}