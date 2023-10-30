/*
Name:Shreya Nigudkar
U.no.: UIT2023846
TO ADD,SUBTRACT,MULTIPLY 2 MATRICES
*/
#include <stdio.h>
int main(void){
int i=0;
int j=0;
int m=0;
int n=0;
int a[3][3]={0};
int b[3][3]={0};
int c[3][3]={0};
int d[3][3]={0};
int e[3][3]={0};

printf("Enter elements of first matrix:\n");
for (i=0;i<3;i++){

for (j=0;j<3;j++){
scanf("%d",&a[i][j]);
}
}
printf("\n");
printf("Enter elements of second matrix:\n");
for (m=0;m<3;m++){

for (n=0;n<3;n++){
scanf("%d",&b[m][n]);
}
}

printf("\n");

printf("\nFirst matrix:\n");
for (i=0;i<3;i++){
for (j=0;j<3;j++){

printf("%d ",a[i][j]);
}
printf("\n");
}
printf("\nSecond matrix:\n");
for (m=0;m<3;m++){
for (n=0;n<3;n++){
printf("%d ",b[m][n]);
}
printf("\n");
}
int ch;
do {
printf("\nEnter\n \t1 for addition\n\t2 for subtraction\n\t3 for multiplication\n\t4 to exit");
printf("\nEnter choice:");
scanf("%d",&ch);
switch (ch)
{
//addition
case 1:
printf("Addition is:\n");
for (i=0;i<3;i++){

for (j=0;j<3;j++){
c[i][j]=a[i][j]+b[i][j];
printf("%d ",c[i][j]);
}
printf("\n");
}
printf("\n");
break;

//Subtraction
case 2:
printf("Subtraction is:\n");
for (i=0;i<3;i++){

for (j=0;j<3;j++){
d[i][j]=a[i][j]-b[i][j];
printf("%d ",d[i][j]);
}
printf("\n");

}
printf("\n");
break;
//multiplication
case 3:
printf("Multiplication is:\n");
for(i=0;i<3;i++)
{
for(j=0;j<3;j++)
{
for(int k=0;k<3;k++)
{
e[i][j]=e[i][j]+(a[i][k]*b[k][j]);
}
printf("%d ",e[i][j]);
}
printf("\n");
}
break;
default:
printf("Exit!!!");
break;
} //switch ends
} //do ends
while(ch!=4);
return 0;
}