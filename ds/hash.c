#include<stdio.h>
#define MAX 10
void display(int a[MAX]) {
    int i,ch;
    do {
        printf("\n1.Display All 2.Filtered Display\n");
        printf("Enter your choice: \n"); 
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("\nThe hash table is:\n");
                for(i=0; i<MAX; i++) 
                    printf("\n %d %d ", i, a[i]); 
                break;
            case 2:
                printf("\nThe hash table is:\n");
                for(i=0; i<MAX; i++)
                    if(a[i]!=-1){
                    printf("\n %d %d ", i, a[i]);
                    continue;
                    }
                break;

            default: printf("Invalid Choice.\n");
        }
    } while(ch<=2);
}

int create(int num) {
    int key; 
    key=num%10;
    return key;
}


void linearprob(int a[MAX], int key, int num){
    int flag=0, i, c=0; 
    if(a[key] == -1) 
        a[key] = num; 
    else {
        printf("\nCollision Detected...!!!\n"); 
        for(i=0;i<MAX;i++) {
            if (a[i]!=-1) 
            c++;
        }
        if(c==MAX){
            printf("Hash table is full.\n"); 
            return;
        }
        printf("Collision avoided successfully using LINEAR PROBING\n"); 
        for(i=key+1; i<MAX; i++)
        if(a[i] == -1) {
            a[i] = num; 
            flag=1; 
            break;
        }
        i=0;
        while((i<key) && (flag==0)) {
            if(a[i] == -1) {
                a[i] = num; 
                flag=1;
                break;
            }
            i++;
        }
    }
}


void main() {
    int a[MAX],num,key,i; 
    int ch;
    printf("Collision handling by linear probing\n"); 
    for (i=0;i<MAX;i++)
        a[i] = -1;
    do {
        printf("\nEnter the value: "); 
        scanf("%d", &num); 
        key=create(num);
        linearprob(a,key,num);
        printf("\nDo you wish to continue? (1/0)\n"); 
        scanf("%d",&ch);
    } while(ch);
    display(a);
}