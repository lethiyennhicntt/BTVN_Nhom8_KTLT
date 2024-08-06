#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int A_recursive(int n);

// tinh tong tu a -> a(n)
int sum_recursive(int n) {
    if (n == 1)
        return 1;
    return A_recursive(n - 1) + sum_recursive(n - 1);
}

// de quy tinh a(n)
int A_recursive(int n) {
    if (n == 1)
        return 1;
    return n * sum_recursive(n);
}

int main() {
    int n;
    printf("Nhap gia tri cua n: ");
    scanf("%d", &n);
    printf("Gia tri cua A(%d) la: %d\n", n, A_recursive(n));
    return 0;
}