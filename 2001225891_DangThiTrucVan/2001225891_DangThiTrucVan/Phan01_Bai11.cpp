#include <stdio.h>

// Hàm xuất các số cực tiểu
void xuatCucTieu(int a[], int n) {
	for (int i = 1; i < n - 1; i++) {
		if (a[i] < a[i - 1] && a[i] < a[i + 1]) {
			printf("%d ", a[i]);
		}
	}
	printf("\n");
}

// Hàm xóa phần tử tại vị trí k
void xoaPhanTu(int a[], int *n, int k) {
	if (k < 0 || k >= *n) {
		printf("Vi tri k khong hop le.\n");
		return;
	}
	for (int i = k; i < *n - 1; i++) {
		a[i] = a[i + 1];
	}
	(*n)--;
}

// Hàm thêm phần tử x tại vị trí k
void themPhanTu(int a[], int *n, int k, int x) {
	if (k < 0 || k > *n) {
		printf("Vi tri k khong hop le.\n");
		return;
	}
	for (int i = *n; i > k; i--) {
		a[i] = a[i - 1];
	}
	a[k] = x;
	(*n)++;
}

// Hàm chuyển số chẵn lên đầu mảng, số lẻ xuống cuối mảng
void chuyenChanLe(int a[], int n) {
	int chan[n], le[n], c = 0, l = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] % 2 == 0) {
			chan[c++] = a[i];
		}
		else {
			le[l++] = a[i];
		}
	}
	for (int i = 0; i < c; i++) {
		a[i] = chan[i];
	}
	for (int i = 0; i < l; i++) {
		a[c + i] = le[i];
	}
}

// Hàm kiểm tra mảng có chứa chẵn lẻ xen kẽ không
int kiemTraChanLeXenKe(int a[], int n) {
	for (int i = 1; i < n; i++) {
		if ((a[i] % 2 == 0 && a[i - 1] % 2 == 0) || (a[i] % 2 != 0 && a[i - 1] % 2 != 0)) {
			return 0; // Không xen kẽ
		}
	}
	return 1; // Có xen kẽ
}

int main() {
	int a[100], n, k, x;

	printf("Nhap so luong phan tu: ");
	scanf("%d", &n);
	printf("Nhap cac phan tu:\n");
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	// Xuất các số cực tiểu
	printf("Cac so cuc tieu: ");
	xuatCucTieu(a, n);

	// Xóa phần tử tại vị trí k
	printf("Nhap vi tri can xoa: ");
	scanf("%d", &k);
	xoaPhanTu(a, &n, k);
	printf("Mang sau khi xoa: ");
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");

	// Thêm phần tử x tại vị trí k
	printf("Nhap vi tri va gia tri can them: ");
	scanf("%d %d", &k, &x);
	themPhanTu(a, &n, k, x);
	printf("Mang sau khi them: ");
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");

	// Chuyển số chẵn lên đầu mảng, số lẻ xuống cuối mảng
	chuyenChanLe(a, n);
	printf("Mang sau khi chuyen chan len dau, le xuong cuoi: ");
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");

	// Kiểm tra mảng có chứa chẵn lẻ xen kẽ không
	if (kiemTraChanLeXenKe(a, n)) {
		printf("Mang co chua chan le xen ke.\n");
	}
	else {
		printf("Mang khong chua chan le xen ke.\n");
	}

	return 0;
}
