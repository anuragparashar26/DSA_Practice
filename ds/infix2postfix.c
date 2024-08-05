#include<stdio.h> 
#include <ctype.h>

char infix[25],postfix[25]; 
int s[10],top=-1;

int pri(char c) {
switch(c) {
case '+':
case '-': return 1; 
case '*':
case '/': return 2; 
case '^': return 3; 
case '(':
case '#': return 0;
    }
}

void push(char c) {
top++; 
s[top]=c;
}

char pop() {
char e; 
e=s[top];
top--; 
return e;
}

void main() {
int i,j=0; 
char ch,ele; 

printf("Enter the infix expression: \n"); 
scanf("%s",infix);
push('#');
for(i=0;infix[i]!='\0';i++) {
ch=infix[i]; 
if(isalnum(ch)) 
postfix[j++]=ch; 
else if(ch=='(') 
push(ch);
else if(ch==')')
{
while(s[top]!='(') 
postfix[j++]=pop(); 
ele=pop();
}
else
{
while(pri (s[top]) >= pri(ch)) 
postfix[j++]=pop(); 
push(ch);
}
}

while(s[top]!='#') 
postfix[j++]=pop(); 
postfix[j]='\0';
printf("Postfix expression is %s",postfix); 
}