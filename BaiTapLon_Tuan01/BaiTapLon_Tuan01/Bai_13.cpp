/*
	Xét 2 mảng 1 chiều a và b. Tính và xuất kết quả các phép chia của phần tử mảng a cho
	phần tử mảng b. Hãy xét các trường hợp ngoại lệ có thể có trong bài toán này
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

// Ham tao ngau nhien gia tri cho mang
void taoNgauNhienMang(int mang[], int kichThuoc) {
	for (int i = 0; i < kichThuoc; i++) {
		mang[i] = rand() % 10; // Gia tri ngau nhien tu 0 den 9
	}
}

// Ham xuat mang ra man hinh
void xuatMang(int mang[], int kichThuoc) {
	for (int i = 0; i < kichThuoc; i++) {
		printf("%d ", mang[i]);
	}
	printf("\n");
}

// Ham tinh va xuat ket qua cac phep chia cua phan tu mang a cho phan tu mang b
void chiaMang(int mangA[], int kichThuocA, int mangB[], int kichThuocB) {
	if (kichThuocA != kichThuocB) {
		printf("Loi: Hai mang co kich thuoc khac nhau.\n");
		return;
	}

	for (int i = 0; i < kichThuocA; i++) {
		if (mangB[i] == 0) {
			printf("Loi: Phan tu thu %d cua mang b la 0, khong the chia.\n", i);
		}
		else {
			printf("a[%d] / b[%d] = %d / %d = %.2f\n", i, i, mangA[i], mangB[i], (float)mangA[i] / mangB[i]);
		}
	}
}

int main() {
	srand(time(0)); // Dat seed cho ham rand()

	int kichThuocA, kichThuocB;
	int mangA[MAX_SIZE], mangB[MAX_SIZE];

	// Nhap kich thuoc cua mang a
	printf("Nhap kich thuoc cua mang a: ");
	scanf_s("%d", &kichThuocA);

	// Nhap kich thuoc cua mang b
	printf("Nhap kich thuoc cua mang b: ");
	scanf_s("%d", &kichThuocB);

	// Kiem tra kich thuoc co hop le khong
	if (kichThuocA > MAX_SIZE || kichThuocB > MAX_SIZE) {
		printf("Loi: Kich thuoc mang qua lon.\n");
		return 1;
	}

	// Tao ngau nhien cac phan tu cho mang a va b
	taoNgauNhienMang(mangA, kichThuocA);
	taoNgauNhienMang(mangB, kichThuocB);

	// Xuat mang a va b
	printf("Mang a: ");
	xuatMang(mangA, kichThuocA);
	printf("Mang b: ");
	xuatMang(mangB, kichThuocB);

	// Tinh va xuat ket qua cac phep chia
	chiaMang(mangA, kichThuocA, mangB, kichThuocB);

	system("pause"); // Dung man hinh de xem ket qua
	return 0;
}
