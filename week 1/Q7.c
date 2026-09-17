//Write a C program to rotate an array to the right by K positions without using another array. 
//Array: 1 2 3 4 5 6 K = 2 Output: 5 6 1 2 3 4

#include <stdio.h>

int main() {
    int a[] = {1, 2, 3, 4, 5, 6};
    int n = 6, k = 2;
    int i, temp;

    for (i = 0; i < k; i++) {
        temp = a[n - 1];

        for (int j = n - 1; j > 0; j--)
            a[j] = a[j - 1];

        a[0] = temp;
    }

    printf("Rotated array: ");

    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}
