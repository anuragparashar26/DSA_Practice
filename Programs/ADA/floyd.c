#include<stdio.h>
int nV;

void printMatrix(int matrix[][nV]){
    for(int i=0; i<nV; i++){
        for(int j=0; j<nV; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

void floyd(int graph[][nV]) {
    int i,j,k,matrix[nV][nV];
    for(i=0; i<nV; i++)
    for(j=0; j<nV; j++) 
    matrix[i][j] = graph[i][j];

    for(int k=0; k<nV; k++) {
        for(int i=0; i<nV; i++) {
            for(int j=0; j<nV; j++) {
                if(matrix[i][k]+matrix[k][j]<matrix[i][j]) 
                    matrix[i][j]=matrix[i][k]+matrix[k][j];              
            }
        }
    }
    printMatrix(matrix);
}

int main() {
    printf("Enter the value of nV:\n");
    scanf("%d", &nV);
    int graph[nV][nV];

    printf("Enter cost adjacency matrix:\n");
    for(int i=0; i<nV; i++) {
        for(int j=0; j<nV; j++) {
        scanf("%d", &graph[i][j]);
        }
    }
    floyd(graph);
}