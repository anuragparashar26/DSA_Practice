#include <stdio.h>
#include <malloc.h>
typedef struct node {
    char usn[11];
    char name[20];
    char sem[10];
    char branch[10];
    char phno[10];
    struct node *link;
}NODE;

NODE *first=NULL;

void create() {
    int i, n;
    NODE *nn;
    printf("\nEnter value of n:\n"); 
    scanf("%d",&n);
    for(i=1;i<=n;i++) {
        nn=(NODE*)malloc(sizeof(NODE)); 
        printf("Enter Details:\n");
        printf("Enter USN: Name: Branch: Sem: Phone:\n"); 
        scanf("%s%s%s%s%s",nn->usn,nn->name,nn->branch,nn->sem,nn->phno); 
        nn->link=first;
        first=nn;
    }
}

void insert_front() {
    NODE *nn; 
    nn=(NODE*)malloc(sizeof(NODE));
    printf("\nEnter Details");
    printf("\nEnter USN: Name: Branch: Sem: Phone:\n"); 
    scanf("%s%s%s%s%s",nn->usn,nn->name,nn->branch,nn->sem,nn->phno);
    nn->link=first; 
    first=nn;
}

void delete_front() {
    NODE *temp;
    if(first==NULL) {
        printf("\nList is empty.");
        return;
    }
    temp=first;
    first=first->link;
    free(temp);
}

void display() {
    int c=0;
    NODE *temp;
    if(first==NULL) {
        printf("\nList is Empty.");
        return;
    }
    temp=first;
    printf("\nContents are:\n");
    while(temp!=NULL){
        printf("%s\t%s\t%s\t%s\t%s\t\n",temp->usn,temp->name,temp->branch,temp->sem,temp->phno); 
        temp=temp->link; 
        c++;
    }
    printf("No. of nodes=%d\n", c);
}

void stack() {
    int ch;
    do {
        printf("\n1. Push 2. Pop 3. Display\n");
        printf("Enter your choice:\n");
        scanf("%d", &ch);
        switch(ch) {
            case 1: insert_front();
            break;
            case 2: delete_front();
            break;
            case 3: display();
            break;
            default: printf("Invalid Choice.\n");
        }
    }while(ch<=3);
}

void main() {
    int ch;
    do {
        printf("1.Create 2.Display 3.Stack\n"); 
        printf("Enter your choice:\n"); 
        scanf("%d",&ch);
        switch(ch) {
            case 1:create(); 
            break;
            case 2:display(); 
            break;
            case 3:stack();
            break;
            default: printf("Invalid Choice.\n");
        }
    }while(ch<=3);
}