#include <stdio.h>

int main() {
	int n;
	printf("Nhap n: ");
	scanf("%d", &n);

	int x = 1, y = 0;
	for (int i = 1; i <= n; i++) {
		int new_x = x + y;
		int new_y = 3 * x + 2 * y;
		x = new_x;
		y = new_y;
	}

	printf("x_%d = %d\n", n, x);
	printf("y_%d = %d\n", n, y);

	return 0;
}
