/*
	Bài 3. Tiếp tục các hàm xử lý trên mảng 2 chiều a (bài 1)
	1. Xuất các cột chỉ chứa số lẻ
	2. Tìm phần tử lớn nhất trong các phần tử trên biên của ma trận.
	3. Trong ma trận có bao nhiêu phần tử có chữ số 2 xuất hiện trong các chữ số của nó.
	4. Xuất các phần tử cực tiểu của ma trận.
	5. Sắp xếp ma trận sao cho: các dòng có chỉ số lẻ thì tăng dần, còn các dòng có chỉ số chẵn
	thì giảm dần.
	6. Sắp xếp ma trận sao cho: các cột có chỉ số lẻ thì giảm dần, còn các cột có chỉ số chẵn thì
	tăng dần.
	7. Kiểm tra các giá trị trong ma trận có giảm dần theo cột và dòng (ziczac)
	8. Liệt kê chỉ số các dòng chứa toàn giá trị chẵn
	9. Liệt kê các dòng chứa giá trị giảm dần
	10. Tìm giá trị xuất hiện nhiều nhất trong ma trận
	11. Tìm các chữ số xuất hiện nhiều nhất trong ma trận
	12. Liệt kê các cột có tổng nhỏ nhất trong ma trận
	13. Hoán vị hai cột i và j trong ma trận
	14. Hoán vị hai dòng k và l trong ma trận.

*/

#include <stdio.h>
#include <limits.h>

#define MAX_ROWS 100
#define MAX_COLS 100

// Hàm nhập ma trận
void nhapMaTran(int a[MAX_ROWS][MAX_COLS], int* rows, int* cols) {
	printf("Nhap so dong: ");
	scanf_s("%d", rows);
	printf("Nhap so cot: ");
	scanf_s("%d", cols);
	printf("Nhap cac phan tu cua ma tran:\n");
	for (int i = 0; i < *rows; i++) {
		for (int j = 0; j < *cols; j++) {
			printf("a[%d][%d] = ", i, j);
			scanf_s("%d", &a[i][j]);
		}
	}
}

// Hàm xuất ma trận
void xuatMaTran(int a[MAX_ROWS][MAX_COLS], int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}

// Hàm xuất các cột chỉ chứa số lẻ
void xuatCotChan(int a[MAX_ROWS][MAX_COLS], int rows, int cols) {
	printf("Cac cot chi chua so le:\n");
	for (int j = 0; j < cols; j++) {
		int isOddColumn = 1;
		for (int i = 0; i < rows; i++) {
			if (a[i][j] % 2 == 0) {
				isOddColumn = 0;
				break;
			}
		}
		if (isOddColumn) {
			printf("Cot %d: ", j);
			for (int i = 0; i < rows; i++) {
				printf("%d ", a[i][j]);
			}
			printf("\n");
		}
	}
}

// Hàm tìm phần tử lớn nhất trên biên của ma trận
int maxBien(int a[MAX_ROWS][MAX_COLS], int rows, int cols) {
	int max = a[0][0];
	for (int i = 0; i < rows; i++) {
		if (a[i][0] > max) max = a[i][0];
		if (a[i][cols - 1] > max) max = a[i][cols - 1];
	}
	for (int j = 0; j < cols; j++) {
		if (a[0][j] > max) max = a[0][j];
		if (a[rows - 1][j] > max) max = a[rows - 1][j];
	}
	return max;
}

// Hàm kiểm tra số chữ số 2 xuất hiện trong số
int demSo2(int num) {
	int count = 0;
	while (num > 0) {
		if (num % 10 == 2) count++;
		num /= 10;
	}
	return count;
}

// Hàm đếm số lượng phần tử có chữ số 2 trong ma trận
int demPhanTuChua2(int a[MAX_ROWS][MAX_COLS], int rows, int cols) {
	int count = 0;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (demSo2(a[i][j]) > 0) count++;
		}
	}
	return count;
}

// Hàm tìm các phần tử cực tiểu của ma trận
void xuatCucTieu(int a[MAX_ROWS][MAX_COLS], int rows, int cols) {
	printf("Cac phan tu cuc tieu:\n");
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			int isMin = 1;
			for (int k = 0; k < rows; k++) {
				if (a[k][j] < a[i][j]) {
					isMin = 0;
					break;
				}
			}
			for (int k = 0; k < cols; k++) {
				if (a[i][k] < a[i][j]) {
					isMin = 0;
					break;
				}
			}
			if (isMin) {
				printf("%d ", a[i][j]);
			}
		}
	}
	printf("\n");
}

// Hàm sắp xếp các dòng của ma trận
void sapXepDong(int a[MAX_ROWS][MAX_COLS], int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols - 1; j++) {
			for (int k = j + 1; k < cols; k++) {
				if ((i % 2 == 0 && a[i][j] < a[i][k]) || (i % 2 != 0 && a[i][j] > a[i][k])) {
					int temp = a[i][j];
					a[i][j] = a[i][k];
					a[i][k] = temp;
				}
			}
		}
	}
}

// Hàm sắp xếp các cột của ma trận
void sapXepCot(int a[MAX_ROWS][MAX_COLS], int rows, int cols) {
	for (int j = 0; j < cols; j++) {
		for (int i = 0; i < rows - 1; i++) {
			for (int k = i + 1; k < rows; k++) {
				if ((j % 2 == 0 && a[i][j] > a[k][j]) || (j % 2 != 0 && a[i][j] < a[k][j])) {
					int temp = a[i][j];
					a[i][j] = a[k][j];
					a[k][j] = temp;
				}
			}
		}
	}
}

// Hàm kiểm tra ma trận có giảm dần theo cả cột và dòng (ziczac)
int kiemTraZiczac(int a[MAX_ROWS][MAX_COLS], int rows, int cols) {
	for (int i = 0; i < rows - 1; i++) {
		for (int j = 0; j < cols - 1; j++) {
			if (a[i][j] <= a[i + 1][j] || a[i][j] <= a[i][j + 1]) {
				return 0; // Không giảm dần
			}
		}
	}
	return 1; // Giảm dần
}

// Hàm liệt kê chỉ số các dòng chứa toàn giá trị chẵn
void xuatDongChan(int a[MAX_ROWS][MAX_COLS], int rows, int cols) {
	printf("Cac dong chua toan gia tri chan:\n");
	for (int i = 0; i < rows; i++) {
		int allEven = 1;
		for (int j = 0; j < cols; j++) {
			if (a[i][j] % 2 != 0) {
				allEven = 0;
				break;
			}
		}
		if (allEven) {
			printf("Dong %d\n", i);
		}
	}
}

// Hàm liệt kê các dòng chứa giá trị giảm dần
void xuatDongGiamDan(int a[MAX_ROWS][MAX_COLS], int rows, int cols) {
	printf("Cac dong chua gia tri giam dan:\n");
	for (int i = 0; i < rows; i++) {
		int decreasing = 1;
		for (int j = 0; j < cols - 1; j++) {
			if (a[i][j] <= a[i][j + 1]) {
				decreasing = 0;
				break;
			}
		}
		if (decreasing) {
			printf("Dong %d\n", i);
		}
	}
}

// Hàm tìm giá trị xuất hiện nhiều nhất
int timGiaTriXuatHienNhieuNhat(int a[MAX_ROWS][MAX_COLS], int rows, int cols) {
	int count[MAX_ROWS * MAX_COLS] = { 0 };
	int mostFrequent = a[0][0];
	int maxCount = 0;
	int numElements = rows * cols;

	for (int i = 0; i < numElements; i++) {
		for (int j = 0; j < i; j++) {
			if (a[i / cols][i % cols] == a[j / cols][j % cols]) {
				count[i]++;
			}
		}
		if (count[i] > maxCount) {
			maxCount = count[i];
			mostFrequent = a[i / cols][i % cols];
		}
	}
	return mostFrequent;
}

// Hàm tìm các chữ số xuất hiện nhiều nhất
void timChuSoXuatHienNhieuNhat(int a[MAX_ROWS][MAX_COLS], int rows, int cols) {
	int digitCount[10] = { 0 };
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			int num = a[i][j];
			while (num > 0) {
				digitCount[num % 10]++;
				num /= 10;
			}
		}
	}
	int maxCount = 0;
	for (int i = 0; i < 10; i++) {
		if (digitCount[i] > maxCount) {
			maxCount = digitCount[i];
		}
	}
	printf("Cac chu so xuat hien nhieu nhat:\n");
	for (int i = 0; i < 10; i++) {
		if (digitCount[i] == maxCount) {
			printf("%d ", i);
		}
	}
	printf("\n");
}

// Hàm liệt kê các cột có tổng nhỏ nhất
void xuatCotTongNhoNhat(int a[MAX_ROWS][MAX_COLS], int rows, int cols) {
	int colSum[MAX_COLS] = { 0 };
	for (int j = 0; j < cols; j++) {
		for (int i = 0; i < rows; i++) {
			colSum[j] += a[i][j];
		}
	}
	int minSum = INT_MAX;
	for (int j = 0; j < cols; j++) {
		if (colSum[j] < minSum) {
			minSum = colSum[j];
		}
	}
	printf("Cac cot co tong nho nhat:\n");
	for (int j = 0; j < cols; j++) {
		if (colSum[j] == minSum) {
			printf("Cot %d\n", j);
		}
	}
}

// Hàm hoán vị hai cột i và j
void hoanViCot(int a[MAX_ROWS][MAX_COLS], int rows, int cols, int i, int j) {
	for (int k = 0; k < rows; k++) {
		int temp = a[k][i];
		a[k][i] = a[k][j];
		a[k][j] = temp;
	}
}

// Hàm hoán vị hai dòng k và l
void hoanViDong(int a[MAX_ROWS][MAX_COLS], int rows, int cols, int k, int l) {
	for (int j = 0; j < cols; j++) {
		int temp = a[k][j];
		a[k][j] = a[l][j];
		a[l][j] = temp;
	}
}

int main() {
	int a[MAX_ROWS][MAX_COLS];
	int rows, cols;
	int choice;

	nhapMaTran(a, &rows, &cols);

	do {
		printf("\nMenu:\n");
		printf("1. Xuat cac cot chi chua so le\n");
		printf("2. Tim phan tu lon nhat tren bien\n");
		printf("3. Dem so phan tu co chu so 2\n");
		printf("4. Xuat cac phan tu cuc tieu\n");
		printf("5. Sap xep cac dong (dong le tang, dong chan giam)\n");
		printf("6. Sap xep cac cot (cot le giam, cot chan tang)\n");
		printf("7. Kiem tra gia tri giam dan ziczac\n");
		printf("8. Liet ke cac dong chua toan gia tri chan\n");
		printf("9. Liet ke cac dong chua gia tri giam dan\n");
		printf("10. Tim gia tri xuat hien nhieu nhat\n");
		printf("11. Tim cac chu so xuat hien nhieu nhat\n");
		printf("12. Liet ke cac cot co tong nho nhat\n");
		printf("13. Hoan vi hai cot\n");
		printf("14. Hoan vi hai dong\n");
		printf("0. Thoat\n");
		printf("Chon chuc nang: ");
		scanf_s("%d", &choice);

		switch (choice) {
		case 1:
			xuatCotChan(a, rows, cols);
			break;
		case 2:
			printf("Phan tu lon nhat tren bien: %d\n", maxBien(a, rows, cols));
			break;
		case 3:
			printf("So phan tu co chu so 2: %d\n", demPhanTuChua2(a, rows, cols));
			break;
		case 4:
			xuatCucTieu(a, rows, cols);
			break;
		case 5:
			sapXepDong(a, rows, cols);
			xuatMaTran(a, rows, cols);
			break;
		case 6:
			sapXepCot(a, rows, cols);
			xuatMaTran(a, rows, cols);
			break;
		case 7:
			if (kiemTraZiczac(a, rows, cols)) {
				printf("Ma tran giam dan ziczac\n");
			}
			else {
				printf("Ma tran khong giam dan ziczac\n");
			}
			break;
		case 8:
			xuatDongChan(a, rows, cols);
			break;
		case 9:
			xuatDongGiamDan(a, rows, cols);
			break;
		case 10:
			printf("Gia tri xuat hien nhieu nhat: %d\n", timGiaTriXuatHienNhieuNhat(a, rows, cols));
			break;
		case 11:
			timChuSoXuatHienNhieuNhat(a, rows, cols);
			break;
		case 12:
			xuatCotTongNhoNhat(a, rows, cols);
			break;
		case 13: {
			int i, j;
			printf("Nhap chi so cot i va j: ");
			scanf_s("%d %d", &i, &j);
			hoanViCot(a, rows, cols, i, j);
			xuatMaTran(a, rows, cols);
			break;
		}
		case 14: {
			int k, l;
			printf("Nhap chi so dong k va l: ");
			scanf_s("%d %d", &k, &l);
			hoanViDong(a, rows, cols, k, l);
			xuatMaTran(a, rows, cols);
			break;
		}
		case 0:
			printf("Thoat chuong trinh.\n");
			break;
		default:
			printf("Chuc nang khong ton tai.\n");
			break;
		}
	} while (choice != 0);

	return 0;
}
