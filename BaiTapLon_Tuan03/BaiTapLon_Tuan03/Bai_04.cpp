/*
	Bài 4. Tiếp tục các hàm xử lý trên ma trận vuông a cấp n (bài 2)
	1. Sắp xếp đường chéo phụ tăng dần/giảm dần.
	2. Sắp xếp ma trận sao cho: các dòng có chỉ số lẻ thì tăng dần, còn các dòng có chỉ số chẵn thì
	giảm dần.
	3. Sắp xếp ma trận sao cho: các cột có chỉ số lẻ thì giảm dần, còn các cột có chỉ số chẵn thì
	tăng dần.
	4. Sắp xếp mảng sao cho các phần tử trên các đường chéo chính và các đường chéo song song
	với đường chéo chính tăng dần.
	5. Di chuyển các phần tử trong ma trận sao cho các phần tử chẵn nằm ở các dòng đầu mảng,
	các phần tử lẻ nằm ở các dòng cuối mảng.
	6. Kiểm tra các phần tử trong ma trận có đối xứng nhau qua đường chéo chính không?
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

void nhapMaTran(int a[MAX][MAX], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("Nhap a[%d][%d]: ", i, j);
			scanf("%d", &a[i][j]);
		}
	}
}

void xuatMaTran(int a[MAX][MAX], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%4d", a[i][j]);
		}
		printf("\n");
	}
}

void sapXepDuongCheoPhuTangDan(int a[MAX][MAX], int n) {
	// Thu thập các phần tử trên đường chéo phụ
	int temp[MAX];
	for (int i = 0; i < n; i++) {
		temp[i] = a[i][n - i - 1];
	}

	// Sắp xếp các phần tử này
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (temp[i] > temp[j]) {
				int t = temp[i];
				temp[i] = temp[j];
				temp[j] = t;
			}
		}
	}

	// Gán lại các phần tử đã sắp xếp vào ma trận
	for (int i = 0; i < n; i++) {
		a[i][n - i - 1] = temp[i];
	}
}

void sapXepDuongCheoPhuGiamDan(int a[MAX][MAX], int n) {
	// Thu thập các phần tử trên đường chéo phụ
	int temp[MAX];
	for (int i = 0; i < n; i++) {
		temp[i] = a[i][n - i - 1];
	}

	// Sắp xếp các phần tử này
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (temp[i] < temp[j]) {
				int t = temp[i];
				temp[i] = temp[j];
				temp[j] = t;
			}
		}
	}

	// Gán lại các phần tử đã sắp xếp vào ma trận
	for (int i = 0; i < n; i++) {
		a[i][n - i - 1] = temp[i];
	}
}

void sapXepDong(int a[MAX][MAX], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			for (int k = j + 1; k < n; k++) {
				if (i % 2 == 0) { // Dòng chẵn
					if (a[i][j] < a[i][k]) {
						int temp = a[i][j];
						a[i][j] = a[i][k];
						a[i][k] = temp;
					}
				}
				else { // Dòng lẻ
					if (a[i][j] > a[i][k]) {
						int temp = a[i][j];
						a[i][j] = a[i][k];
						a[i][k] = temp;
					}
				}
			}
		}
	}
}

void sapXepCot(int a[MAX][MAX], int n) {
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < n - 1; i++) {
			for (int k = i + 1; k < n; k++) {
				if (j % 2 == 0) { // Cột chẵn
					if (a[i][j] > a[k][j]) {
						int temp = a[i][j];
						a[i][j] = a[k][j];
						a[k][j] = temp;
					}
				}
				else { // Cột lẻ
					if (a[i][j] < a[k][j]) {
						int temp = a[i][j];
						a[i][j] = a[k][j];
						a[k][j] = temp;
					}
				}
			}
		}
	}
}

void sapXepCheoChinhVaPhu(int a[MAX][MAX], int n) {
	// Thu thập các phần tử trên các đường chéo chính và phụ
	int temp[MAX * 2];
	int k = 0;

	for (int i = 0; i < n; i++) {
		temp[k++] = a[i][i]; // Đường chéo chính
		temp[k++] = a[i][n - i - 1]; // Đường chéo phụ
	}

	// Sắp xếp các phần tử này
	for (int i = 0; i < k - 1; i++) {
		for (int j = i + 1; j < k; j++) {
			if (temp[i] > temp[j]) {
				int t = temp[i];
				temp[i] = temp[j];
				temp[j] = t;
			}
		}
	}

	// Gán lại các phần tử đã sắp xếp vào ma trận
	k = 0;
	for (int i = 0; i < n; i++) {
		a[i][i] = temp[k++];
		a[i][n - i - 1] = temp[k++];
	}
}

void diChuyenChanLe(int a[MAX][MAX], int n) {
	int chan[MAX * MAX], le[MAX * MAX];
	int chanCount = 0, leCount = 0;

	// Phân loại các phần tử chẵn và lẻ
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] % 2 == 0) {
				chan[chanCount++] = a[i][j];
			}
			else {
				le[leCount++] = a[i][j];
			}
		}
	}

	// Gán lại các phần tử chẵn vào các dòng đầu
	int k = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (k < chanCount) {
				a[i][j] = chan[k++];
			}
		}
	}

	// Gán lại các phần tử lẻ vào các dòng cuối
	k = 0;
	for (int i = chanCount / n; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (k < leCount) {
				a[i][j] = le[k++];
			}
		}
	}
}

bool kiemTraDoiXungDuongCheoChinh(int a[MAX][MAX], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (a[i][j] != a[j][i]) {
				return false;
			}
		}
	}
	return true;
}

void menu() {
	int a[MAX][MAX], n;
	int choice;

	printf("Nhap cap cua ma tran vuong: ");
	scanf("%d", &n);

	nhapMaTran(a, n);

	do {
		printf("\n--- MENU ---\n");
		printf("1. Sap xep duong cheo phu tang dan\n");
		printf("2. Sap xep duong cheo phu giam dan\n");
		printf("3. Sap xep ma tran sao cho dong le tang dan, dong chan giam dan\n");
		printf("4. Sap xep ma tran sao cho cot le giam dan, cot chan tang dan\n");
		printf("5. Sap xep cac phan tu tren cac duong cheo chinh va phu tang dan\n");
		printf("6. Di chuyen cac phan tu chan len dau ma tran, cac phan tu le xuong cuoi ma tran\n");
		printf("7. Kiem tra cac phan tu trong ma tran co doi xung qua duong cheo chinh khong\n");
		printf("0. Thoat\n");
		printf("Nhap lua chon cua ban: ");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			sapXepDuongCheoPhuTangDan(a, n);
			xuatMaTran(a, n);
			break;
		case 2:
			sapXepDuongCheoPhuGiamDan(a, n);
			xuatMaTran(a, n);
			break;
		case 3:
			sapXepDong(a, n);
			xuatMaTran(a, n);
			break;
		case 4:
			sapXepCot(a, n);
			xuatMaTran(a, n);
			break;
		case 5:
			sapXepCheoChinhVaPhu(a, n);
			xuatMaTran(a, n);
			break;
		case 6:
			diChuyenChanLe(a, n);
			xuatMaTran(a, n);
			break;
		case 7:
			if (kiemTraDoiXungDuongCheoChinh(a, n)) {
				printf("Ma tran doi xung qua duong cheo chinh\n");
			}
			else {
				printf("Ma tran khong doi xung qua duong cheo chinh\n");
			}
			break;
		case 0:
			printf("Thoat chuong trinh.\n");
			break;
		default:
			printf("Lua chon khong hop le!\n");
			break;
		}
	} while (choice != 0);
}

int main() {
	menu();
	return 0;
}
