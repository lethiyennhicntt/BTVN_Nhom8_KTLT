#include <stdio.h>

double S_iterative(int n) {
	double S = 0.0;
	for (int i = 1; i <= n; i++) {
		S += 1.0 / (i * (i + 1) * (i + 2));
	}
	return S;
}

int main() {
	int n;
	printf("Nhap n: ");
	scanf("%d", &n);
	printf("S(n) = %lf\n", S_iterative(n));
	return 0;
}
