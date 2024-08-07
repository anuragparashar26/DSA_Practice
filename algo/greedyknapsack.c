#include <stdio.h>

int main() {
    float weight[50], profit[50], ratio[50];
    float totalvalue=0, temp, capacity;
    int n,i,j;

    printf("Enter number of items: ");
    scanf("%d", &n);

    for(i=0; i<n; i++) {
        printf("Enter weight and profit for item[%d]\n", i+1);
        scanf("%f%f", &weight[i], &profit[i]);
    }

    printf("Enter knapsack capacity:\n");
    scanf("%f", &capacity);

    for(i=0; i<n; i++)
    ratio[i]=profit[i]/weight[i];

    for(i=0; i<n; i++){
        for(j=i+1; j<n; j++) {
            if(ratio[i]<ratio[j]){
                temp = ratio[j];
                ratio[j] = ratio[i];
                ratio[i] = temp;

                temp = weight[j];
                weight[j] = weight[i];
                weight[i] = temp;

                temp = profit[j];
                profit[j] = profit[i];
                profit[i] = temp;
            }
        }
    }

    printf("Knapsack problem using Greedy Algo:\n");
    for(i=0; i<n; i++) {
        if(weight[i]>capacity)
        break;
        else {
            totalvalue=totalvalue+profit[i];
            capacity=capacity-weight[i];
        }
    }

    if(i<n)
    totalvalue=totalvalue+(ratio[i]*capacity);

    printf("The max value is: %f\n", totalvalue);

    return 0;
}