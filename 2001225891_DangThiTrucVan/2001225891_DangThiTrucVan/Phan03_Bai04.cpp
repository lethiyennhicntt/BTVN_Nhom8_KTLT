#include <stdio.h>
#define MAX 100

// Hàm hoán vị
void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

// 1. Sắp xếp đường chéo phụ tăng dần/giảm dần
void sapXepDuongCheoPhu(int a[MAX][MAX], int n, int tangDan) {
	int temp[MAX], k = 0;
	for (int i = 0; i < n; i++) {
		temp[k++] = a[i][n - i - 1];
	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if ((tangDan && temp[i] > temp[j]) || (!tangDan && temp[i] < temp[j])) {
				swap(&temp[i], &temp[j]);
			}
		}
	}
	k = 0;
	for (int i = 0; i < n; i++) {
		a[i][n - i - 1] = temp[k++];
	}
}

// 2. Sắp xếp ma trận sao cho: các dòng có chỉ số lẻ thì tăng dần, còn các dòng có chỉ số chẵn thì giảm dần
void sapXepDong(int a[MAX][MAX], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			for (int k = j + 1; k < n; k++) {
				if ((i % 2 == 0 && a[i][j] < a[i][k]) || (i % 2 != 0 && a[i][j] > a[i][k])) {
					swap(&a[i][j], &a[i][k]);
				}
			}
		}
	}
}

// 3. Sắp xếp ma trận sao cho: các cột có chỉ số lẻ thì giảm dần, còn các cột có chỉ số chẵn thì tăng dần
void sapXepCot(int a[MAX][MAX], int n) {
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < n - 1; i++) {
			for (int k = i + 1; k < n; k++) {
				if ((j % 2 == 0 && a[i][j] > a[k][j]) || (j % 2 != 0 && a[i][j] < a[k][j])) {
					swap(&a[i][j], &a[k][j]);
				}
			}
		}
	}
}

// 4. Sắp xếp ma trận sao cho các phần tử trên các đường chéo chính và các đường chéo song song với đường chéo chính tăng dần
void sapXepDuongCheoChinhVaSongSong(int a[MAX][MAX], int n) {
	int temp[MAX * MAX], k = 0;
	for (int d = -(n - 1); d < n; d++) {
		for (int i = 0; i < n; i++) {
			int j = i + d;
			if (j >= 0 && j < n) {
				temp[k++] = a[i][j];
			}
		}
	}
	for (int i = 0; i < k - 1; i++) {
		for (int j = i + 1; j < k; j++) {
			if (temp[i] > temp[j]) {
				swap(&temp[i], &temp[j]);
			}
		}
	}
	k = 0;
	for (int d = -(n - 1); d < n; d++) {
		for (int i = 0; i < n; i++) {
			int j = i + d;
			if (j >= 0 && j < n) {
				a[i][j] = temp[k++];
			}
		}
	}
}

// 5. Di chuyển các phần tử trong ma trận sao cho các phần tử chẵn nằm ở các dòng đầu ma trận, các phần tử lẻ nằm ở các dòng cuối ma trận
void diChuyenChanLe(int a[MAX][MAX], int n) {
	int chan[MAX * MAX], le[MAX * MAX], kChan = 0, kLe = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] % 2 == 0) {
				chan[kChan++] = a[i][j];
			}
			else {
				le[kLe++] = a[i][j];
			}
		}
	}
	int k = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i < kChan / n) {
				a[i][j] = chan[k++];
			}
			else {
				a[i][j] = le[k++];
			}
		}
	}
}

// 6. Kiểm tra các phần tử trong ma trận có đối xứng nhau qua đường chéo chính không
int kiemTraDoiXungDuongCheoChinh(int a[MAX][MAX], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (a[i][j] != a[j][i]) {
				return 0;
			}
		}
	}
	return 1;
}

int main() {
	int a[MAX][MAX], n;

	printf("Nhap cap cua ma tran vuong: ");
	scanf("%d", &n);

	printf("Nhap cac phan tu cua ma tran:\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);
		}
	}

	// Sắp xếp đường chéo phụ
	int tangDan;
	printf("Nhap 1 de sap xep tang dan, 0 de sap xep giam dan: ");
	scanf("%d", &tangDan);
	sapXepDuongCheoPhu(a, n, tangDan);
	printf("Ma tran sau khi sap xep duong cheo phu:\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}

	// Sắp xếp các dòng
	sapXepDong(a, n);
	printf("Ma tran sau khi sap xep cac dong:\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}

	// Sắp xếp các cột
	sapXepCot(a, n);
	printf("Ma tran sau khi sap xep cac cot:\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}

	// Sắp xếp các đường chéo chính và song song
	sapXepDuongCheoChinhVaSongSong(a, n);
	printf("Ma tran sau khi sap xep cac duong cheo chinh va song song:\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}

	// Di chuyển các phần tử chẵn và lẻ
	diChuyenChanLe(a, n);
	printf("Ma tran sau khi di chuyen cac phan tu chan va le:\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}

	// Kiểm tra đối xứng qua đường chéo chính
	int doiXung = kiemTraDoiXungDuongCheoChinh(a, n);
	printf("Ma tran doi xung qua duong cheo chinh: %d\n", doiXung);

	return 0;
}



