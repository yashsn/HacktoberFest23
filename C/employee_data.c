
#include <stdio.h>
#include <stdlib.h>
struct details
{
char name[30];
int eid;
int salary;
};
struct details emp[30];
void disp(int r);
void emp_search(int r);
void greater(int r);
int main()
{
int n,i,ch;
printf("How many employees do you want to add?:");
scanf("%d",&n);
for (i=0;i<n;i++)
{
printf("\n-------------------------");
printf("\nEnter details of employee- %d",i+1);
printf("\n-------------------------");
printf("\nEnter name:");
scanf("%s",emp[i].name);
printf("\nEnter employee ID:");
scanf("%d",&emp[i].eid);
printf("\nEnter employee salary:");
scanf("%d",&emp[i].salary);
}
while(1){
printf("\nMENU");
printf("\n-------------------------");
printf("\nEnter\n1 for display\n2 for searching salary>10000\n3 for searching employee number\n4 to exit\nEnter choice:");
scanf("%d",&ch);
switch (ch)
{
case 1:
disp(n);
break;
case 2:
greater(n);

break;
case 3:
emp_search(n);
break;
case 4:
exit(0);
break;
}//switch closed
}//while closed
}//main closed
void disp(int r)
{
//int n;
printf("\nEmployee details are as follows:");
printf("\n-------------------------------------");
printf("\n");
printf("\nNAME\tEID\tSALARY\t");

for (int i=0;i<r;i++)
{
printf("\n\n%s",emp[i].name);
printf("\t%d",emp[i].eid);
printf("\t%d",emp[i].salary);
printf("\n-------------------------------------");
}
}
void greater(int r){
printf("Employee(s) having salary more than 10000:");
for (int i=0;i<r;i++){
if (emp[i].salary>=10000)
{
printf("\nNAME\tEID\tSALARY\t\n%s\t%d\t%d",emp[i].name,emp[i].eid,emp[i].salary);
}
}//for closed
}//greater closed
void emp_search(int r){
int k,i;
printf("\nEnter the E ID you want to search:");
scanf("%d",&k);
printf("\n-------------------------------------");
for (int i=0;i<r;i++){

if (emp[i].eid==k)
{
printf("\nNAME\tEID\tSALARY\t\n%s\t%d\t%d",emp[i].name,emp[i].eid,emp[i].salary);
}
}
}