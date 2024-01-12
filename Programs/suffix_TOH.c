#include<stdio.h> 
#include<math.h>
#include <ctype.h>

int op1,op2,res,i,top=-1,s[10],ele,n; 

void push(int ele) {
top++; 
s[top]=ele;
}

int pop() {
int ele; 
ele=s[top]; 
top--; 
return(ele);
}

void eval() {
int e;
char postfix[20],ch;
printf("Enter the postfix exp: "); 
scanf("%s",postfix);
for(i=0;postfix[i]!='\0';i++) {
ch=postfix[i];
if(isdigit(ch)) 
push(ch-'0');
else
{
op2=pop(); 
op1=pop();

switch(ch)
{
case '+': res=op1+op2;
break; 
case '-': res=op1-op2;
break; 
case '*': res=op1*op2;
break;
case '/': res=op1/op2;
break;
case '^': res=pow(op1,op2); 
break;
}
push(res);
}
}
printf("Result of postfix exp: %d\n",res);
}

void tow(int n, char S, char D, char A) {
    if(n==1) {
        printf("Move disk 1 from rod %c to rod %c\n", S, D);
        return;
    }
    tow(n-1, S, A, D);
    printf("Move disk %d from rod %c to rod %c\n", n, S, D);
    tow(n-1, A, D, S);
}

void main() {
    int ch;
    do {
        printf("1. Evaluation of postfix expression: \t 2. Tower of Hanoi\n");
        printf("Enter your choice:\n");
        scanf("%d", &ch);

        switch(ch) {
            case 1: eval();
            break;

            case 2: printf("Enter the number of disks:\n");
                    scanf("%d", &n);
                    tow(n, 'A', 'C', 'B');
                    break;
        }
    }while(ch<=2);
}