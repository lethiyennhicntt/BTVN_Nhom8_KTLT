#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int Y_recursive(int n) {
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;
    if (n == 3)
        return 3;
    return Y_recursive(n - 1) + 2 * Y_recursive(n - 2) + 3 * Y_recursive(n - 3);
}

int main() {
    int n;
    printf("Nhap gia tri cua n: ");
    scanf("%d", &n);
    printf("Gia tri cua Y(%d) la: %d\n", n, Y_recursive(n));
    return 0;
}