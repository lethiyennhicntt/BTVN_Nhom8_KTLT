#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int X_recursive(int n) {
	if (n == 1)
		return 1;
	if (n == 2)
		return 1;
	return X_recursive(n - 1) + (n - 1) * X_recursive(n - 2);
}

int main() {
	int n;
	printf("Nhap gia tri cua n: ");
	scanf("%d", &n);
	printf("Gia tri cua X(%d) la: %d\n", n, X_recursive(n));
	return 0;
}