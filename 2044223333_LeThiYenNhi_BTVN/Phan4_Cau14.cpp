#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int U_recursive(int n) {
    if (n < 6)
        return n;
    return U_recursive(n - 5) + U_recursive(n - 4) + U_recursive(n - 3) + U_recursive(n - 2) + U_recursive(n - 1);
}

int main() {
    int n;
    printf("Nhap gia tri cua n: ");
    scanf("%d", &n);
    printf("Gia tri cua U(%d) la: %d\n", n, U_recursive(n));
    return 0;
}