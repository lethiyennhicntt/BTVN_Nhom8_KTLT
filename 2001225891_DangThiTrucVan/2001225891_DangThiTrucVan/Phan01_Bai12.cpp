#include <stdio.h>

typedef struct {
	int tu;
	int mau;
} PhanSo;

PhanSo timPhanSoLonNhat(PhanSo ps[], int n) {
	PhanSo max = ps[0];
	for (int i = 1; i < n; i++) {
		if ((float)ps[i].tu / ps[i].mau >(float)max.tu / max.mau) {
			max = ps[i];
		}
	}
	return max;
}

PhanSo timPhanSoNhoNhat(PhanSo ps[], int n) {
	PhanSo min = ps[0];
	for (int i = 1; i < n; i++) {
		if ((float)ps[i].tu / ps[i].mau < (float)min.tu / min.mau) {
			min = ps[i];
		}
	}
	return min;
}

void xoaPhanSo(PhanSo ps[], int *n, int k) {
	if (k < 0 || k >= *n) {
		printf("Vi tri k khong hop le.\n");
		return;
	}
	for (int i = k; i < *n - 1; i++) {
		ps[i] = ps[i + 1];
	}
	(*n)--;
}

void themPhanSo(PhanSo ps[], int *n, int k, PhanSo x) {
	if (k < 0 || k > *n) {
		printf("Vi tri k khong hop le.\n");
		return;
	}
	for (int i = *n; i > k; i--) {
		ps[i] = ps[i - 1];
	}
	ps[k] = x;
	(*n)++;
}

int main() {
	PhanSo ps[100];
	int n, k;
	PhanSo x;

	printf("Nhap so luong phan so: ");
	scanf("%d", &n);
	printf("Nhap cac phan so (tu mau):\n");
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &ps[i].tu, &ps[i].mau);
	}

	// Tìm phân số lớn nhất
	PhanSo max = timPhanSoLonNhat(ps, n);
	printf("Phan so lon nhat: %d/%d\n", max.tu, max.mau);

	// Tìm phân số nhỏ nhất
	PhanSo min = timPhanSoNhoNhat(ps, n);
	printf("Phan so nho nhat: %d/%d\n", min.tu, min.mau);

	// Xóa phân số tại vị trí k
	printf("Nhap vi tri can xoa: ");
	scanf("%d", &k);
	xoaPhanSo(ps, &n, k);
	printf("Danh sach phan so sau khi xoa: ");
	for (int i = 0; i < n; i++) {
		printf("%d/%d ", ps[i].tu, ps[i].mau);
	}
	printf("\n");

	// Thêm phân số x tại vị trí k
	printf("Nhap vi tri va phan so can them (k tu mau): ");
	scanf("%d %d %d", &k, &x.tu, &x.mau);
	themPhanSo(ps, &n, k, x);
	printf("Danh sach phan so sau khi them: ");
	for (int i = 0; i < n; i++) {
		printf("%d/%d ", ps[i].tu, ps[i].mau);
	}
	printf("\n");

	return 0;
}
