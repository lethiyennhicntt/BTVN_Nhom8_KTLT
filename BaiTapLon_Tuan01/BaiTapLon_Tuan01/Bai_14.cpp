/*
	Bài 14: viết chương trình nhập họ tên, ngày sinh và giới tính của người lao động.
	Hãy tính thời gian người lao động được nghỉ hưu dựa theo quy định của Bộ luật lao động Việt
	Nam 2019
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void tinhThoiGianNghiHuu(int namSinh, int thangSinh, char gioiTinh[]) {
	int namHuu, thangHuu;

	if (strcmp(gioiTinh, "nam") == 0) {
		if (namSinh >= 1961 && namSinh <= 1963) {
			if (namSinh == 1961 && thangSinh <= 9) {
				namHuu = 2021;
				thangHuu = 3;
			}
			else if (namSinh == 1961 && thangSinh >= 10 || namSinh == 1962) {
				namHuu = 2022;
				thangHuu = 6;
			}
			else if (namSinh == 1962 && thangSinh >= 7 || namSinh == 1963 && thangSinh <= 3) {
				namHuu = 2023;
				thangHuu = 9;
			}
			else if (namSinh == 1963 && thangSinh >= 4) {
				namHuu = 2024;
				thangHuu = 0;
			}
			else if (namSinh >= 1964 && namSinh <= 1966) {
				if (namSinh == 1964 && thangSinh <= 9) {
					namHuu = 2025;
					thangHuu = 3;
				}
				else if (namSinh == 1964 && thangSinh >= 10 || namSinh == 1965) {
					namHuu = 2026;
					thangHuu = 6;
				}
				else if (namSinh == 1965 && thangSinh >= 7 || namSinh == 1966 && thangSinh <= 3) {
					namHuu = 2027;
					thangHuu = 9;
				}
				else if (namSinh >= 1966) {
					namHuu = 2028;
					thangHuu = 0;
				}
			}
		}
	}
	else if (strcmp(gioiTinh, "nu") == 0) {
		if (namSinh >= 1966 && namSinh <= 1968) {
			if (namSinh == 1966 && thangSinh <= 8) {
				namHuu = 2021;
				thangHuu = 4;
			}
			else if (namSinh == 1966 && thangSinh >= 9 || namSinh == 1967) {
				namHuu = 2022;
				thangHuu = 8;
			}
			else if (namSinh == 1967 && thangSinh >= 5 || namSinh == 1968 && thangSinh <= 8) {
				namHuu = 2023;
				thangHuu = 0;
			}
			else if (namSinh >= 1968) {
				namHuu = 2024;
				thangHuu = 4;
			}
		}
		else if (namSinh >= 1968 && namSinh <= 1971) {
			if (namSinh == 1968 && thangSinh >= 9 || namSinh == 1969) {
				namHuu = 2025;
				thangHuu = 8;
			}
			else if (namSinh == 1969 && thangSinh >= 6 || namSinh == 1970) {
				namHuu = 2026;
				thangHuu = 0;
			}
			else if (namSinh == 1970 && thangSinh >= 1 || namSinh == 1971 && thangSinh <= 4) {
				namHuu = 2027;
				thangHuu = 4;
			}
			else if (namSinh >= 1971) {
				namHuu = 2028;
				thangHuu = 8;
			}
		}
		else if (namSinh >= 1971 && namSinh <= 1974) {
			if (namSinh == 1971 && thangSinh >= 5 || namSinh == 1972) {
				namHuu = 2029;
				thangHuu = 0;
			}
			else if (namSinh == 1972 && thangSinh >= 9 || namSinh == 1973) {
				namHuu = 2030;
				thangHuu = 4;
			}
			else if (namSinh == 1973 && thangSinh >= 5 || namSinh == 1974) {
				namHuu = 2031;
				thangHuu = 8;
			}
			else if (namSinh >= 1974) {
				namHuu = 2032;
				thangHuu = 0;
			}
		}
		else if (namSinh >= 1974) {
			namHuu = 2033;
			thangHuu = 4;
		}
	}

	printf("Thoi gian nghi huu: %d thang %d nam\n", thangHuu, namHuu);
}

int main() {
	char hoTen[100], gioiTinh[10];
	int namSinh, thangSinh;

	// Nhap thong tin
	printf("Nhap ho ten: ");
	fgets(hoTen, sizeof(hoTen), stdin);
	hoTen[strcspn(hoTen, "\n")] = 0;  // Loai bo ky tu xuong dong

	printf("Nhap nam sinh (YYYY): ");
	scanf_s("%d", &namSinh);

	printf("Nhap thang sinh (MM): ");
	scanf_s("%d", &thangSinh);

	printf("Nhap gioi tinh (nam/nu): ");
	scanf_s("%s", gioiTinh);

	// Tinh thoi gian nghi huu
	tinhThoiGianNghiHuu(namSinh, thangSinh, gioiTinh);

	system("pause");
	return 0;
}
