#include<stdio.h>
#define MAX 5
void pal();
void push();
int pop();
void display();

int stk[MAX],top= -1,ele,i; 

void pal()
{
top=-1;
int i=1,len=0,rev=0,digit,temp,n;
printf("Enter a Number\n"); 
scanf("%d",&n);
temp=n; 
while(n!=0)
{
digit=n%10; 
n=n/10; 
push(digit); 
len++;
}
while(len!=0)
{
digit=pop(); 
rev=rev+(digit*i); 
len--;
i=i*10;
}

if(temp==rev)
printf("Number is a palindrome\n"); 
else
printf("Number is not a palindrome\n");
}

void push(int ele)
{
if(top==MAX-1)
{
printf("Stack Overflow"); 
return;
}
top++; 
stk[top]=ele;
}


int pop()
{
int ele; 
if(top==-1)
{
printf("Stack underflow\n"); 
return -1;
}
ele=stk[top]; 
top--; 
return ele;
}


void display()
{
if(top==-1)
{
printf("Stack underflow\n"); 
return;
}
printf("Stack Contents are\n"); 
for(i=top;i>=0;i--)
printf("%d\n",stk[i]);
}


void main()
{
int ch; 
do
{
printf("1.Push, 2.Pop 3. Display 4. Palindrome\n");
printf("Enter your choice\n");
scanf("%d",&ch);
switch(ch)
{
case 1: printf("Enter the element to be pushed \n"); 
scanf("%d",&ele);
push(ele); 
break;

case 2: ele=pop();
printf("Element deleted is %d\n",ele); 
break;

case 3:
display(); 
break;

case 4:
pal(); 
break;

default: printf("invalid choice\n");
}
}while(ch<=4);
}