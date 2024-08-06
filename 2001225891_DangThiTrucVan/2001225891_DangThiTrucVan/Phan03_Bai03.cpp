#include <stdio.h>
#define MAX 100

// Hàm hoán vị
void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

// 1. Xuất các cột chỉ chứa số lẻ
void xuatCotLe(int a[MAX][MAX], int dong, int cot) {
	for (int j = 0; j < cot; j++) {
		int laCotLe = 1;
		for (int i = 0; i < dong; i++) {
			if (a[i][j] % 2 == 0) {
				laCotLe = 0;
				break;
			}
		}
		if (laCotLe) {
			printf("Cot %d chi chua so le: ", j);
			for (int i = 0; i < dong; i++) {
				printf("%d ", a[i][j]);
			}
			printf("\n");
		}
	}
}

// 2. Tìm phần tử lớn nhất trong các phần tử trên biên của ma trận
int timMaxBien(int a[MAX][MAX], int dong, int cot) {
	int max = a[0][0];
	for (int i = 0; i < dong; i++) {
		for (int j = 0; j < cot; j++) {
			if (i == 0 || i == dong - 1 || j == 0 || j == cot - 1) {
				if (a[i][j] > max) {
					max = a[i][j];
				}
			}
		}
	}
	return max;
}

// 3. Trong ma trận có bao nhiêu phần tử có chữ số 2 xuất hiện trong các chữ số của nó
int demChuSo2(int a[MAX][MAX], int dong, int cot) {
	int count = 0;
	for (int i = 0; i < dong; i++) {
		for (int j = 0; j < cot; j++) {
			int num = a[i][j];
			while (num != 0) {
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

// 4. Xuất các phần tử cực tiểu của ma trận
void xuatCucTieu(int a[MAX][MAX], int dong, int cot) {
	for (int i = 0; i < dong; i++) {
		for (int j = 0; j < cot; j++) {
			int nhoHonXungQuanh = 1;
			if (i > 0 && a[i][j] >= a[i - 1][j]) nhoHonXungQuanh = 0;
			if (i < dong - 1 && a[i][j] >= a[i + 1][j]) nhoHonXungQuanh = 0;
			if (j > 0 && a[i][j] >= a[i][j - 1]) nhoHonXungQuanh = 0;
			if (j < cot - 1 && a[i][j] >= a[i][j + 1]) nhoHonXungQuanh = 0;
			if (nhoHonXungQuanh) {
				printf("Phan tu cuc tieu: %d\n", a[i][j]);
			}
		}
	}
}

// 5. Sắp xếp ma trận sao cho: các dòng có chỉ số lẻ thì tăng dần, còn các dòng có chỉ số chẵn thì giảm dần
void sapXepDong(int a[MAX][MAX], int dong, int cot) {
	for (int i = 0; i < dong; i++) {
		for (int j = 0; j < cot - 1; j++) {
			for (int k = j + 1; k < cot; k++) {
				if ((i % 2 == 0 && a[i][j] < a[i][k]) || (i % 2 != 0 && a[i][j] > a[i][k])) {
					swap(&a[i][j], &a[i][k]);
				}
			}
		}
	}
}

// 6. Sắp xếp ma trận sao cho: các cột có chỉ số lẻ thì giảm dần, còn các cột có chỉ số chẵn thì tăng dần
void sapXepCot(int a[MAX][MAX], int dong, int cot) {
	for (int j = 0; j < cot; j++) {
		for (int i = 0; i < dong - 1; i++) {
			for (int k = i + 1; k < dong; k++) {
				if ((j % 2 == 0 && a[i][j] > a[k][j]) || (j % 2 != 0 && a[i][j] < a[k][j])) {
					swap(&a[i][j], &a[k][j]);
				}
			}
		}
	}
}

// 7. Kiểm tra các giá trị trong ma trận có giảm dần theo cột và dòng (ziczac)
int kiemTraGiamDanZiczac(int a[MAX][MAX], int dong, int cot) {
	for (int i = 0; i < dong; i++) {
		for (int j = 0; j < cot - 1; j++) {
			if (a[i][j] < a[i][j + 1]) {
				return 0;
			}
		}
	}
	for (int j = 0; j < cot; j++) {
		for (int i = 0; i < dong - 1; i++) {
			if (a[i][j] < a[i + 1][j]) {
				return 0;
			}
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
			printf("Dong %d chua toan gia tri chan\n", i);
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
			printf("Dong %d chua gia tri giam dan\n", i);
		}
	}
}

// 10. Tìm giá trị xuất hiện nhiều nhất trong ma trận
int timGiaTriXuatHienNhieuNhat(int a[MAX][MAX], int dong, int cot) {
	int maxCount = 0, res = a[0][0];
	for (int i = 0; i < dong; i++) {
		for (int j = 0; j < cot; j++) {
			int count = 1;
			for (int x = 0; x < dong; x++) {
				for (int y = 0; y < cot; y++) {
					if (a[i][j] == a[x][y] && (i != x || j != y)) {
						count++;
					}
				}
			}
			if (count > maxCount) {
				maxCount = count;
				res = a[i][j];
			}
		}
	}
	return res;
}

// 11. Tìm các chữ số xuất hiện nhiều nhất trong ma trận
int timChuSoXuatHienNhieuNhat(int a[MAX][MAX], int dong, int cot) {
	int countDigits[10] = { 0 };
	for (int i = 0; i < dong; i++) {
		for (int j = 0; j < cot; j++) {
			int num = a[i][j];
			while (num != 0) {
				countDigits[num % 10]++;
				num /= 10;
			}
		}
	}
	int maxCount = 0, res = 0;
	for (int i = 0; i < 10; i++) {
		if (countDigits[i] > maxCount) {
			maxCount = countDigits[i];
			res = i;
		}
	}
	return res;
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
			printf("Cot %d co tong nho nhat\n", j);
		}
	}
}

// 13. Hoán vị hai cột i và j trong ma trận
void hoanViCot(int a[MAX][MAX], int dong, int cot, int i, int j) {
	for (int k = 0; k < dong; k++) {
		swap(&a[k][i], &a[k][j]);
	}
}

// 14. Hoán vị hai dòng k và l trong ma trận
void hoanViDong(int a[MAX][MAX], int dong, int cot, int k, int l) {
	for (int j = 0; j < cot; j++) {
		swap(&a[k][j], &a[l][j]);
	}
}

int main() {
	int a[MAX][MAX], dong, cot;

	printf("Nhap so dong cua ma tran: ");
	scanf("%d", &dong);
	printf("Nhap so cot cua ma tran: ");
	scanf("%d", &cot);

	printf("Nhap cac phan tu cua ma tran:\n");
	for (int i = 0; i < dong; i++) {
		for (int j = 0; j < cot; j++) {
			scanf("%d", &a[i][j]);
		}
	}

	// Xuất các cột chỉ chứa số lẻ
	xuatCotLe(a, dong, cot);

	// Tìm phần tử lớn nhất trong các phần tử trên biên của ma trận
	int maxBien = timMaxBien(a, dong, cot);
	printf("Phan tu lon nhat tren bien cua ma tran: %d\n", maxBien);

	// Đếm số phần tử có chữ số 2
	int count2 = demChuSo2(a, dong, cot);
	printf("So phan tu co chu so 2: %d\n", count2);

	// Xuất các phần tử cực tiểu
	xuatCucTieu(a, dong, cot);

	// Sắp xếp các dòng
	sapXepDong(a, dong, cot);
	printf("Ma tran sau khi sap xep cac dong:\n");
	for (int i = 0; i < dong; i++) {
		for (int j = 0; j < cot; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}

	// Sắp xếp các cột
	sapXepCot(a, dong, cot);
	printf("Ma tran sau khi sap xep cac cot:\n");
	for (int i = 0; i < dong; i++) {
		for (int j = 0; j < cot; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}

	// Kiểm tra giá trị giảm dần theo cột và dòng
	int giamDanZiczac = kiemTraGiamDanZiczac(a, dong, cot);
	printf("Ma tran giam dan ziczac: %d\n", giamDanZiczac);

	// Liệt kê chỉ số các dòng chứa toàn giá trị chẵn
	lietKeDongChan(a, dong, cot);

	// Liệt kê các dòng chứa giá trị giảm dần
	lietKeDongGiamDan(a, dong, cot);

	// Tìm giá trị xuất hiện nhiều nhất
	int nhieuNhat = timGiaTriXuatHienNhieuNhat(a, dong, cot);
	printf("Gia tri xuat hien nhieu nhat: %d\n", nhieuNhat);

	// Tìm chữ số xuất hiện nhiều nhất
	int chuSoNhieuNhat = timChuSoXuatHienNhieuNhat(a, dong, cot);
	printf("Chu so xuat hien nhieu nhat: %d\n", chuSoNhieuNhat);

	// Liệt kê các cột có tổng nhỏ nhất
	lietKeCotTongNhoNhat(a, dong, cot);

	// Hoán vị hai cột
	int i, j;
	printf("Nhap hai cot can hoan vi: ");
	scanf("%d %d", &i, &j);
	hoanViCot(a, dong, cot, i, j);
	printf("Ma tran sau khi hoan vi hai cot %d va %d:\n", i, j);
	for (int i = 0; i < dong; i++) {
		for (int j = 0; j < cot; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}

	// Hoán vị hai dòng
	int k, l;
	printf("Nhap hai dong can hoan vi: ");
	scanf("%d %d", &k, &l);
	hoanViDong(a, dong, cot, k, l);
	printf("Ma tran sau khi hoan vi hai dong %d va %d:\n", k, l);
	for (int i = 0; i < dong; i++) {
		for (int j = 0; j < cot; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}

	return 0;
}
