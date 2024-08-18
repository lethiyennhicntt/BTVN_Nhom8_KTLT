#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

double geometric_recursive(int n, double a, double q) {
    if (n == 1)
        return a;
    return q * geometric_recursive(n - 1, a, q);
}

int main() {
    int n;
    double a, q;
    printf("Nhap gia tri cua n: ");
    scanf("%d", &n);
    printf("Nhap gia tri cua a: ");
    scanf("%lf", &a);
    printf("Nhap gia tri cua q: ");
    scanf("%lf", &q);
    printf("Phan tu thu %d cua cap so nhan la: %lf\n", n, geometric_recursive(n, a, q));
    return 0;
}