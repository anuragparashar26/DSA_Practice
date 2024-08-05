#include <stdio.h>
int visited[10] = {0}, cost[10][10], min, mincost = 0;
void input(int num) {
    int i, j;
    printf("Enter adjacency matrix:\n");
    for(i = 0; i < num; i++) {
        for(j = 0; j < num; j++) {
            scanf("%d", &cost[i][j]);
        }
    }
}

void prims(int num) {
    int i, j, ne = 1, a, b, u, v;

    for(i = 0; i < num; i++) {
        for(j = 0; j < num; j++) {
            if(cost[i][j] == 0) {
                cost[i][j] = 999;
            }
        }
    }
    visited[0] = 1; 
    mincost = 0;
    while(ne < num) {
        min = 999;

        for(i = 0; i < num; i++) {
            if(visited[i]) {
                for(j = 0; j < num; j++) {
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
}

int main() {
    int num;
    printf("\n\t\tPrim's Algorithm");
    printf("\n\nEnter number of nodes: ");
    scanf("%d", &num);
    input(num);
    prims(num);
    return 0;
}
