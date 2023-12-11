#include <stdio.h>
#include <stdlib.h>
int a[20],ele,pos,n,i;
void create();
void display();
void insert();
void delete();

void create() {
    printf("Enter the size of array elements: \n");
    scanf("%d", &n);
    printf("Enter array elements: ");
    for (i=0;i<n;i++) {
    scanf("%d", &a[i]);
    }
}

void display() {
    printf("The array elements are:\n");
    for(i=0; i<n;i++) {
        printf("%d\t", a[i]);
    }
}

void insert() {
    printf("Enter the position to insert: \n");
    scanf("%d",&pos);
    printf("\nEnter the element to insert: \t");
    scanf("%d", &ele);

    if(pos > n+1 || pos<=0) {
        printf("Invalid position: ");
        return;
    }

    for(i=n-1;i>=pos-1;i--) {
        a[i+1]=a[i];
    }
        a[pos-1]=ele;
        n++;
}

void delete() {
    printf("Enter the position of element to be deleted: \n");
    scanf("%d",&pos);
    if(pos>=(n+1) || pos<=0) {
        printf("Invalid Position");
        return;
    }
    printf("element deleted is %d", a[pos-1]); 
    for(i=pos-1; i<n-1; i++)
        a[i]=a[i+1]; 
        n--;
}

void main () {
    int ch;
    do
    {
        printf("\nChoose:\n 1. Create\t2. Display\t3. Insert\t4. Delete\n");
        printf("Enter your choice:\n");
        scanf("%d",&ch);
        switch(ch) {
            case 1: create();
            break;

            case 2: display();
            break;

            case 3: insert();
            break;

            case 4: delete();
            break;

            case 5: exit(0);
            break;

            default: printf("Invalid choice.");
            break;
        }
    } while (ch<=4);
    
}
