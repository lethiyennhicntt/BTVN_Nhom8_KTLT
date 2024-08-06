#include <stdio.h>
#define MAX 100

// 1. Xuất các cột chỉ chứa số lẻ
void xuatCotLe(int a[MAX][MAX], int dong, int cot) {
	for (int j = 0; j < cot; j++) {
		int coLe = 1;
		for (int i = 0; i < dong; i++) {
			if (a[i][j] % 2 == 0) {
				coLe = 0;
				break;
			}
		}
		if (coLe) {
			printf("Cot %d chi chua so le:\n", j);
			for (int i = 0; i < dong; i++) {
				printf("%d ", a[i][j]);
			}
			printf("\n");
		}
	}
}

// 2. Tìm phần từ lớn nhất trong các phần tử trên biên của ma trận.
int timMaxBien(int a[MAX][MAX], int dong, int cot) {
	int max = a[0][0];
	for (int i = 0; i < dong; i++) {
		if (a[i][0] > max) max = a[i][0];
		if (a[i][cot - 1] > max) max = a[i][cot - 1];
	}
	for (int j = 0; j < cot; j++) {
		if (a[0][j] > max) max = a[0][j];
		if (a[dong - 1][j] > max) max = a[dong - 1][j];
	}
	return max;
}

// 3. Trong ma trận có bao nhiêu phần tử có chữ số 2 xuất hiện trong các chữ số của nó.
int demChuSo2(int a[MAX][MAX], int dong, int cot) {
	int count = 0;
	for (int i = 0; i < dong; i++) {
		for (int j = 0; j < cot; j++) {
			int num = a[i][j];
			while (num > 0) {
				if (num % 10 == 2) {
					count++;
					break;
				}
				num /= 10;
			}
		}
	}
	return count;
}

// 4. Xuất các phần tử cực tiểu của ma trận.
void xuatCucTieu(int a[MAX][MAX], int dong, int cot) {
	for (int i = 1; i < dong - 1; i++) {
		for (int j = 1; j < cot - 1; j++) {
			if (a[i][j] < a[i - 1][j] && a[i][j] < a[i + 1][j] && a[i][j] < a[i][j - 1] && a[i][j] < a[i][j + 1]) {
				printf("Phan tu cuc tieu: a[%d][%d] = %d\n", i, j, a[i][j]);
			}
		}
	}
}

// 5. Sắp xếp ma trận sao cho: các dòng có chỉ số lẻ thì tăng dần, còn các dòng có chỉ số chẵn thì giảm dần.
void sapXepDong(int a[MAX][MAX], int dong, int cot) {
	for (int i = 0; i < dong; i++) {
		for (int j = 0; j < cot - 1; j++) {
			for (int k = j + 1; k < cot; k++) {
				if ((i % 2 == 0 && a[i][j] < a[i][k]) || (i % 2 != 0 && a[i][j] > a[i][k])) {
					int temp = a[i][j];
					a[i][j] = a[i][k];
					a[i][k] = temp;
				}
			}
		}
	}
}

// 6. Sắp xếp ma trận sao cho: các cột có chỉ số lẻ thì giảm dần, còn các cột có chỉ số chẵn thì tăng dần.
void sapXepCot(int a[MAX][MAX], int dong, int cot) {
	for (int j = 0; j < cot; j++) {
		for (int i = 0; i < dong - 1; i++) {
			for (int k = i + 1; k < dong; k++) {
				if ((j % 2 == 0 && a[i][j] > a[k][j]) || (j % 2 != 0 && a[i][j] < a[k][j])) {
					int temp = a[i][j];
					a[i][j] = a[k][j];
					a[k][j] = temp;
				}
			}
		}
	}
}

// 7. Kiểm tra các giá trị trong ma trận có giảm dần theo cột và dòng (ziczac)
int kiemTraGiamDanZiczac(int a[MAX][MAX], int dong, int cot) {
	for (int i = 0; i < dong; i++) {
		for (int j = 0; j < cot; j++) {
			if (i > 0 && a[i][j] >= a[i - 1][j]) return 0;
			if (j > 0 && a[i][j] >= a[i][j - 1]) return 0;
		}
	}
	return 1;
}

// 8. Liệt kê chỉ số các dòng chứa toàn giá trị chẵn
void lietKeDongChan(int a[MAX][MAX], int dong, int cot) {
	for (int i = 0; i < dong; i++) {
		int toanChan = 1;
		for (int j = 0; j < cot; j++) {
			if (a[i][j] % 2 != 0) {
				toanChan = 0;
				break;
			}
		}
		if (toanChan) {
			printf("Dong %d chua toan gia tri chan.\n", i);
		}
	}
}

// 9. Liệt kê các dòng chứa giá trị giảm dần
void lietKeDongGiamDan(int a[MAX][MAX], int dong, int cot) {
	for (int i = 0; i < dong; i++) {
		int giamDan = 1;
		for (int j = 0; j < cot - 1; j++) {
			if (a[i][j] < a[i][j + 1]) {
				giamDan = 0;
				break;
			}
		}
		if (giamDan) {
			printf("Dong %d chua gia tri giam dan.\n", i);
		}
	}
}

// 10. Tìm giá trị xuất hiện nhiều nhất trong ma trận
int timGiaTriXuatHienNhieuNhat(int a[MAX][MAX], int dong, int cot) {
	int maxCount = 0, value = a[0][0];
	for (int i = 0; i < dong; i++) {
		for (int j = 0; j < cot; j++) {
			int count = 0;
			for (int x = 0; x < dong; x++) {
				for (int y = 0; y < cot; y++) {
					if (a[i][j] == a[x][y]) {
						count++;
					}
				}
			}
			if (count > maxCount) {
				maxCount = count;
				value = a[i][j];
			}
		}
	}
	return value;
}

// 11. Tìm các chữ số xuất hiện nhiều nhất trong ma trận
int timChuSoXuatHienNhieuNhat(int a[MAX][MAX], int dong, int cot) {
	int count[10] = { 0 };
	for (int i = 0; i < dong; i++) {
		for (int j = 0; j < cot; j++) {
			int num = a[i][j];
			while (num > 0) {
				count[num % 10]++;
				num /= 10;
			}
		}
	}
	int maxCount = 0, digit = 0;
	for (int i = 0; i < 10; i++) {
		if (count[i] > maxCount) {
			maxCount = count[i];
			digit = i;
		}
	}
	return digit;
}

// 12. Liệt kê các cột có tổng nhỏ nhất trong ma trận
void lietKeCotTongNhoNhat(int a[MAX][MAX], int dong, int cot) {
	int minSum = 0;
	for (int i = 0; i < dong; i++) {
		minSum += a[i][0];
	}
	for (int j = 1; j < cot; j++) {
		int sum = 0;
		for (int i = 0; i < dong; i++) {
			sum += a[i][j];
		}
		if (sum < minSum) {
			minSum = sum;
		}
	}
	for (int j = 0; j < cot; j++) {
		int sum = 0;
		for (int i = 0; i < dong; i++) {
			sum += a[i][j];
		}
		if (sum == minSum) {
			printf("Cot %d co tong nho nhat.\n", j);
		}
	}
}

// 13. Hoán vị hai cột i và j trong ma trận
void hoanViCot(int a[MAX][MAX], int dong, int cot, int i, int j) {
	for (int k = 0; k < dong; k++) {
		int temp = a[k][i];
		a[k][i] = a[k][j];
		a[k][j] = temp;
	}
}

// 14. Hoán vị hai dòng k và l trong ma trận
void hoanViDong(int a[MAX][MAX], int dong, int cot, int k, int l) {
	for (int j = 0; j < cot; j++) {
		int temp = a[k][j];
		a[k][j] = a[l][j];
		a[l][j] = temp;
	}
}

int main() {
	int a[MAX][MAX], dong, cot, i, j, k, l;

	printf("Nhap so dong cua ma tran: ");
	scanf("%d", &dong);
	printf("Nhap so cot cua ma tran: ");
	scanf("%d", &cot);

	printf("Nhap cac phan tu cua ma tran:\n");
	for (int x = 0; x < dong; x++) {
		for (int y = 0; y < cot; y++) {
			scanf("%d", &a[x][y]);
		}
	}

	// Xuất các cột chỉ chứa số lẻ
	xuatCotLe(a, dong, cot);

	// Tìm phần từ lớn nhất trong các phần tử trên biên của ma trận
	printf("Phan tu lon nhat tren bien: %d\n", timMaxBien(a, dong, cot));

	// Trong ma trận có bao nhiêu phần tử có chữ số 2 xuất hiện trong các chữ số của nó
	printf("So luong phan tu co chu so 2: %d\n", demChuSo2(a, dong, cot));

	// Xuất các phần tử cực tiểu của ma trận
	xuatCucTieu(a, dong, cot);

	// Sắp xếp ma trận sao cho: các dòng có chỉ số lẻ thì tăng dần, còn các dòng có chỉ số chẵn thì giảm dần
	sapXepDong(a, dong, cot);
	printf("Ma tran sau khi sap xep cac dong:\n");
	for (int x = 0; x < dong; x++) {
		for (int y = 0; y < cot; y++) {
			printf("%d ", a[x][y]);
		}
		printf("\n");
	}

	// Sắp xếp ma trận sao cho: các cột có chỉ số lẻ thì giảm dần, còn các cột có chỉ số chẵn thì tăng dần
	sapXepCot(a, dong, cot);
	printf("Ma tran sau khi sap xep cac cot:\n");
	for (int x = 0; x < dong; x++) {
		for (int y = 0; y < cot; y++) {
			printf("%d ", a[x][y]);
		}
		printf("\n");
	}

	// Kiểm tra các giá trị trong ma trận có giảm dần theo cột và dòng (ziczac)
	printf("Ma tran giam dan theo ziczac: %d\n", kiemTraGiamDanZiczac(a, dong, cot));

	// Liệt kê chỉ số các dòng chứa toàn giá trị chẵn
	lietKeDongChan(a, dong, cot);

	// Liệt kê các dòng chứa giá trị giảm dần
	lietKeDongGiamDan(a, dong, cot);

	// Tìm giá trị xuất hiện nhiều nhất trong ma trận
	printf("Gia tri xuat hien nhieu nhat trong ma tran: %d\n", timGiaTriXuatHienNhieuNhat(a, dong, cot));

	// Tìm các chữ số xuất hiện nhiều nhất trong ma trận
	printf("Chu so xuat hien nhieu nhat trong ma tran: %d\n", timChuSoXuatHienNhieuNhat(a, dong, cot));

	// Liệt kê các cột có tổng nhỏ nhất trong ma trận
	lietKeCotTongNhoNhat(a, dong, cot);

	// Hoán vị hai cột i và j trong ma trận
	printf("Nhap chi so hai cot can hoan vi: ");
	scanf("%d %d", &i, &j);
	hoanViCot(a, dong, cot, i, j);
	printf("Ma tran sau khi hoan vi hai cot:\n");
	for (int x = 0; x < dong; x++) {
		for (int y = 0; y < cot; y++) {
			printf("%d ", a[x][y]);
		}
		printf("\n");
	}

	// Hoán vị hai dòng k và l trong ma trận
	printf("Nhap chi so hai dong can hoan vi: ");
	scanf("%d %d", &k, &l);
	hoanViDong(a, dong, cot, k, l);
	printf("Ma tran sau khi hoan vi hai dong:\n");
	for (int x = 0; x < dong; x++) {
		for (int y = 0; y < cot; y++) {
			printf("%d ", a[x][y]);
		}
		printf("\n");
	}

	return 0;
}
