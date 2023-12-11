#include <stdio.h>
#include <stdlib.h>
#define N 5
void qinsert();
void qdelete();
void qdisplay();

int front=0;
int rear=-1;
int q[N];

void qinsert() {
    int item;
    if(rear==N-1)
    printf("Queue is full\n");
    else {
        printf("Enter the item:\n");
        scanf("%d", &item);
        rear++;
        q[rear]=item;
    }
}

void qdelete() {
    if(front>rear) {
        printf("The queue is empty\n");
        front=0;
        rear=-1;
    }
    else {
        printf("The last item deleted is %d\n", q[front]);
        front++;
    }
}

void qdisplay() {
    int i;
    if(front>rear) {
        printf("Queue is empty\n"); 
        }
        else {
            for (i=front; i<=rear; i++) {
                printf("%d\n", q[i]);
            }
                printf("Front element of queue is %d\n", q[front]);
                printf("Rear element of queue is %d\n", q[rear]);
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
case 1: qinsert();
break;

case 2: qdelete();
break;

case 3:
qdisplay(); 
break;

case 4:
exit(0);
break;

default: printf("Invalid choice\n");
}
}while(ch!=4);
return 0;
}