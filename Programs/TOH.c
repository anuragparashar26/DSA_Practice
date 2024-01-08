#include <stdio.h>

void TOH(int n, char S, char D, char A) {
    if(n==1) {
        printf("Move disk 1 from rod %c to rod %c\n", S, D);
        return;
    }
    TOH(n-1, S, A, D);
    printf("Move disk %d from rod %c to rod %c\n", n, S, D);
    TOH(n-1, A, D, S);
}

int main() {
    int n;
    printf("Enter number of disks: ");
    scanf("%d", &n);
    TOH(n, 'A', 'C', 'B');
    return 0;
}