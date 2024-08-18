/*
	Viết các hàm sau, chú ý xử ngoại lệ (nếu có)
	a. Xuất các số cực tiểu trong a. Biết rằng số cực tiểu là số nhỏ hơn các số quanh nó.
	b. Xóa phần tử tại vị trí k
	c. Thêm phần tử x tại vị trí k
	d. Chuyển số chẵn lên đầu mảng, số lẻ xuống cuối mảng.
	e. Kiểm tra mảng có chứa chẵn lẻ xen kẻ không?
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

void nhapMang(int a[], int* n) {
	printf("Nhap so luong phan tu: ");
	scanf_s("%d", n);
	for (int i = 0; i < *n; i++) {
		printf("Nhap phan tu a[%d]: ", i);
		scanf_s("%d", &a[i]);
	}
}

void xuatMang(int a[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

void xuatSoCucTieu(int a[], int n) {
	if (n < 2) {
		printf("Mang khong co so cuc tieu.\n");
		return;
	}
	bool found = false;
	for (int i = 1; i < n - 1; i++) {
		if (a[i] < a[i - 1] && a[i] < a[i + 1]) {
			printf("%d ", a[i]);
			found = true;
		}
	}
	if (!found) {
		printf("Mang khong co so cuc tieu.\n");
	}
	else {
		printf("\n");
	}
}

void xoaPhanTu(int a[], int* n, int k) {
	if (k < 0 || k >= *n) {
		printf("Vi tri xoa khong hop le.\n");
		return;
	}
	for (int i = k; i < *n - 1; i++) {
		a[i] = a[i + 1];
	}
	(*n)--;
}

void themPhanTu(int a[], int* n, int x, int k) {
	if (k < 0 || k > *n) {
		printf("Vi tri them khong hop le.\n");
		return;
	}
	for (int i = *n; i > k; i--) {
		a[i] = a[i - 1];
	}
	a[k] = x;
	(*n)++;
}

void chuyenChanLenDau(int a[], int n) {
	int chan[MAX], le[MAX];
	int cIndex = 0, lIndex = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] % 2 == 0) {
			chan[cIndex++] = a[i];
		}
		else {
			le[lIndex++] = a[i];
		}
	}
	for (int i = 0; i < cIndex; i++) {
		a[i] = chan[i];
	}
	for (int i = 0; i < lIndex; i++) {
		a[cIndex + i] = le[i];
	}
}

bool kiemTraXenKe(int a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		if ((a[i] % 2 == 0 && a[i + 1] % 2 == 0) || (a[i] % 2 != 0 && a[i + 1] % 2 != 0)) {
			return false;
		}
	}
	return true;
}

int main() {
	int a[MAX], n;
	nhapMang(a, &n);
	printf("Mang vua nhap: ");
	xuatMang(a, n);

	printf("Cac so cuc tieu trong mang: ");
	xuatSoCucTieu(a, n);

	int k, x;
	printf("Nhap vi tri can xoa: ");
	scanf_s("%d", &k);
	xoaPhanTu(a, &n, k);
	printf("Mang sau khi xoa: ");
	xuatMang(a, n);

	printf("Nhap gia tri can them: ");
	scanf_s("%d", &x);
	printf("Nhap vi tri can them: ");
	scanf_s("%d", &k);
	themPhanTu(a, &n, x, k);
	printf("Mang sau khi them: ");
	xuatMang(a, n);

	chuyenChanLenDau(a, n);
	printf("Mang sau khi chuyen so chan len dau: ");
	xuatMang(a, n);

	if (kiemTraXenKe(a, n)) {
		printf("Mang co chua chẵn lẻ xen kẽ.\n");
	}
	else {
		printf("Mang khong chua chẵn lẻ xen kẽ.\n");
	}

	system("pause");
	return 0;
}

