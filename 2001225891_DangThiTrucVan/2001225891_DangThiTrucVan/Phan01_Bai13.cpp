#include <stdio.h>

void chiaMang(int a[], int n, int b[], int m) {
	if (n != m) {
		printf("Hai mang phai co cung kich thuoc.\n");
		return;
	}

	for (int i = 0; i < n; i++) {
		if (b[i] == 0) {
			printf("Khong the chia %d cho 0.\n", a[i]);
		}
		else {
			printf("%d / %d = %.2f\n", a[i], b[i], (float)a[i] / b[i]);
		}
	}
}

int main() {
	int a[100], b[100], n, m;

	printf("Nhap so luong phan tu mang a: ");
	scanf("%d", &n);
	printf("Nhap cac phan tu mang a:\n");
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	printf("Nhap so luong phan tu mang b: ");
	scanf("%d", &m);
	if (m != n) {
		printf("Hai mang phai co cung kich thuoc.\n");
		return 1;
	}

	printf("Nhap cac phan tu mang b:\n");
	for (int i = 0; i < m; i++) {
		scanf("%d", &b[i]);
	}

	printf("Ket qua chia cac phan tu tuong ung cua hai mang:\n");
	chiaMang(a, n, b, m);

	return 0;
}
