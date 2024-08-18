/*
	Viết các hàm sau:
	a. Tìm phân số lớn nhất/nhỏ nhất
	b. Xóa phần tử tại vị trí k
	c. Thêm phần tử x tại vị trí k
*/

#include <stdio.h>

#define MAX 100

typedef struct {
	int tu;
	int mau;
} PhanSo;

// Hàm nhập phân số
void nhapPhanSo(PhanSo* ps) {
	printf("Nhap tu so: ");
	scanf_s("%d", &ps->tu);
	printf("Nhap mau so: ");
	scanf_s("%d", &ps->mau);
	if (ps->mau == 0) {
		printf("Mau so phai khac 0. Nhap lai mau so: ");
		scanf_s("%d", &ps->mau);
	}
}

// Hàm in phân số
void inPhanSo(PhanSo ps) {
	printf("%d/%d\n", ps.tu, ps.mau);
}

// Hàm tìm phân số lớn nhất
PhanSo timPhanSoLonNhat(PhanSo arr[], int n) {
	PhanSo max = arr[0];
	for (int i = 1; i < n; i++) {
		if ((float)arr[i].tu / arr[i].mau > (float)max.tu / max.mau) {
			max = arr[i];
		}
	}
	return max;
}

// Hàm tìm phân số nhỏ nhất
PhanSo timPhanSoNhoNhat(PhanSo arr[], int n) {
	PhanSo min = arr[0];
	for (int i = 1; i < n; i++) {
		if ((float)arr[i].tu / arr[i].mau < (float)min.tu / min.mau) {
			min = arr[i];
		}
	}
	return min;
}

// Hàm xóa phần tử tại vị trí k
void xoaPhanSoTaiViTri(PhanSo arr[], int* n, int k) {
	if (k < 0 || k >= *n) {
		printf("Vi tri xoa khong hop le.\n");
		return;
	}
	for (int i = k; i < *n - 1; i++) {
		arr[i] = arr[i + 1];
	}
	(*n)--;
}

// Hàm thêm phần tử tại vị trí k
void themPhanSoTaiViTri(PhanSo arr[], int* n, int k, PhanSo x) {
	if (k < 0 || k > *n) {
		printf("Vi tri them khong hop le.\n");
		return;
	}
	for (int i = *n; i > k; i--) {
		arr[i] = arr[i - 1];
	}
	arr[k] = x;
	(*n)++;
}

int main() {
	PhanSo arr[MAX];
	int n, choice, k;
	PhanSo x;

	printf("Nhap so luong phan so: ");
	scanf_s("%d", &n);

	for (int i = 0; i < n; i++) {
		printf("Nhap phan so thu %d:\n", i + 1);
		nhapPhanSo(&arr[i]);
	}

	do {
		printf("\n--- MENU ---\n");
		printf("1. Tim phan so lon nhat\n");
		printf("2. Tim phan so nho nhat\n");
		printf("3. Xoa phan so tai vi tri k\n");
		printf("4. Them phan so tai vi tri k\n");
		printf("0. Thoat\n");
		printf("Nhap lua chon: ");
		scanf_s("%d", &choice);

		switch (choice) {
		case 1:
			printf("Phan so lon nhat: ");
			inPhanSo(timPhanSoLonNhat(arr, n));
			break;
		case 2:
			printf("Phan so nho nhat: ");
			inPhanSo(timPhanSoNhoNhat(arr, n));
			break;
		case 3:
			printf("Nhap vi tri can xoa: ");
			scanf_s("%d", &k);
			xoaPhanSoTaiViTri(arr, &n, k);
			break;
		case 4:
			printf("Nhap vi tri can them: ");
			scanf_s("%d", &k);
			printf("Nhap phan so can them:\n");
			nhapPhanSo(&x);
			themPhanSoTaiViTri(arr, &n, k, x);
			break;
		case 0:
			printf("Thoat chuong trinh.\n");
			break;
		default:
			printf("Lua chon khong hop le. Vui long chon lai.\n");
		}
	} while (choice != 0);

	return 0;
}
