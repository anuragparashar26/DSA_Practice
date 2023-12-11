#include <stdio.h>
#include <stdlib.h>
#define N 5
void cqinsert();
void cqdelete();
void cqdisplay();

int front=-1;
int rear=-1;
int cq[N];

void cqinsert() {
    int item;
    if(front==(rear+1)%N)
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
        rear=(rear+1)%N;
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
    else front=(front+1)%N;
}}

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
            for (i = front; i < N; i++) {
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
printf("1.Insert\t2.Delete\t3.Display\t 4.Exit\n");
printf("Enter your choice\n");
scanf("%d",&ch);
switch(ch)
{
case 1: cqinsert();
break;

case 2: cqdelete();
break;

case 3: cqdisplay(); 
break;

case 4: exit(0);
break;

default: printf("Invalid choice\n");
}
}while(ch!=4);
return 0;
}