#include <stdio.h>

int max(int a, int b){
    if(a>b) return(a);
    else return(b);
}

int knapsack(int W, int wt[], int val[], int n) {
    int i,w;
    int K[n+1][W+1];

    for(i=0; i<=n; i++) {
        for(w=0; w<=W; w++) {
            if(i==0 || w==0)
            K[i][w]=0;
            else if(wt[i-1]<=w)
            K[i][w]=max(val[i-1]+K[i-1][w-wt[i-1]],K[i-1][w]);
            else
            K[i][w]=K[i-1][w];
        }
    }
    return K[n][W];
}

int main() {
    int val[100], wt[100];
    int W, n;
    printf("Enter the number of items: ");
    scanf("%d",&n);
    for(int i=0; i<n; i++) {
        printf("Enter values and weights for item %d: ", i+1);
        scanf("%d %d", &val[i], &wt[i]);
    }
    printf("Enter the knsapsack capacity: ");
    scanf("%d", &W);
    printf("Max value that can be obtained: %d\n", knapsack(W,wt,val,n));
    return 0;
}