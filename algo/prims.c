#include <stdio.h>

int i,j,a,b,u,v,n,ne=1;
int min, mincost=0, visited[10] = {0}, cost[10][10];

int main() {
    printf("Prim's Algorithm");
    printf("\nEnter number of nodes: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for(i = 0; i <n; i++) {
        for(j = 0; j <n; j++) {
            scanf("%d", &cost[i][j]);
            if(cost[i][j] == 0) {
                cost[i][j] = 999;
            }
        }
    }
    printf("The edges of the min cost spanning tree are:\n");
    visited[0] = 1; 
    while(ne < n) {
        for(i = 0, min=999; i <n; i++) {
            if(visited[i]) {
                for(j = 0; j <n; j++) {
                    if(!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        a = u = i;
                        b = v = j;
                    }
                }
            }
        }
        printf("\n Edge %d: (%d - %d) cost: %d", ne++, a, b, min);
        mincost += min;
        visited[b] = 1;
        cost[a][b] = cost[b][a] = 999; 
    }
    printf("\n\nMinimum cost = %d\n", mincost);
    return 0;
}
