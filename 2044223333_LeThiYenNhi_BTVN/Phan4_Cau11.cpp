#include <stdio.h>

int Fibonacci(int n) {
	if (n <= 2)
		return 1;
	return Fibonacci(n - 1) + Fibonacci(n - 2);
}

void printFibonacciInRange(int m, int n) {
	for (int i = 1;; i++) {
		int fib = Fibonacci(i);
		if (fib > n)
			break;
		if (fib >= m)
			printf("%d ", fib);
	}
}

int main() {
	int m, n;
	printf("Nhap m: ");
	scanf("%d", &m);
	printf("Nhap n: ");
	scanf("%d", &n);
	printf("Day so Fibonacci trong doan [%d, %d]: ", m, n);
	printFibonacciInRange(m, n);
	return 0;
}
