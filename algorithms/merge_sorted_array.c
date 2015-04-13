#include <stdio.h>
#include <memory.h>

void merge(int A[], int m, int B[], int n) {
    int curA = m - 1;
    int curB = n - 1;
    
    // insert cursor (init postion is tail of A)
    int i = m + n - 1;

    while (curB >= 0) {
        // A is empty, or B less than A.
        if (curA < 0 || B[curB] > A[curA]) {
            A[i] = B[curB];
            curB--;
        } else {
            A[i] = A[curA];
            curA--;
        }
        i--;
    }
}

int main() {
    int a[] = {1, 5, 7, 8, 9};
    int b[] = {2, 3, 4, 6};
    
    int m = sizeof(a) / sizeof(*a);
    int n = sizeof(b) / sizeof(*b);

    // assume that A has enough space (size that is greater or equal to m + n)
    int enoughA[m + n];
    memset(enoughA, 0, (m + n) * sizeof(int));

    // copy values from 'a' to 'enough a'
    for (int i = 0; i < m; i++) {
        enoughA[i] = a[i];
    }

    merge(enoughA, m, b, n);

    // result
    for (int i = 0; i < m + n; i++) {
        printf("%d\n", enoughA[i]);
    }
}