#include <stdio.h>
#include <stdlib.h>
#define MAX 5
void cqinsert();
void cqdelete();
void cqstatus();
void cqdisplay();

int front=-1;
int rear=-1;
int cq[MAX];

void cqinsert() {
    int item;
    if(front==(rear+1)%MAX)
    {
    printf("Queue Overflow\n");
    }
    else {
        printf("Enter the item to be inserted:\n");
        scanf("%d", &item);
        if(front==-1) {
        front=rear=0;
        }
        else {
        rear=(rear+1)%MAX;
    }
    cq[rear]=item;
    }}

void cqdelete() {
    if(front==-1) {
        printf("The queue is empty\n");
    }
    else {
        printf("The last item deleted is %d\n", cq[front]);
    if (front==rear) {
        front=rear=-1;
    }
    else front=(front+1)%MAX;
}}

void cqstatus() {
    if (front==(rear+1)%MAX) {
        printf("Queue Overflow\n");
    }
    else if (front==-1) {
        printf("Queue underflow\n");
    }
    else {
        printf("Queue is neither underflowed nor overflowed.\n");
    }
}

void cqdisplay() {
    int i;
    if (front == -1) {
        printf("Queue is empty\n");
    } else {
        printf("Items in the queue are:\n");
        if (front <= rear) {
            for (i = front; i <= rear; i++) {
                printf("%d ", cq[i]);
            }
        } else {
            for (i = front; i < MAX; i++) {
                printf("%d ", cq[i]);
            }
            for (i = 0; i <= rear; i++) {
                printf("%d ", cq[i]);
            }
        }
        printf("\nFront element of queue is %d\n", cq[front]);
        printf("Rear element of queue is %d\n", cq[rear]);
    }
}

int main()
{
int ch; 
do
{
printf("1.Insert\t2.Delete\t3.Underflow/Overflow\t 4.Display\t5.Exit\n");
printf("Enter your choice\n");
scanf("%d",&ch);
switch(ch)
{
case 1: cqinsert();
break;

case 2: cqdelete();
break;

case 3: cqstatus();
break;

case 4: cqdisplay(); 
break;

case 5: exit(0);
break;

default: printf("Invalid choice\n");
}
}while(ch<=5);
}