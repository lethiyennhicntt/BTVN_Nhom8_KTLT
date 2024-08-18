/*
	Bài 10. Viết chương trình nhập vào chuỗi st (dạng con trỏ).
	a. Xuất giá trị từng ký tự của st thông qua con trỏ trỏ đến chuỗi.
	b. Chuyển các ký tự của chuỗi về dạng chữ hoa (gợi ý: thay đổi mã ASCII)
	c. Chuyển các ký tự đầu mỗi từ (đứng sau dấu cách) của chuỗi về dạng chữ hoa (gợi ý: thay
	đổi mã ASCII)
	Ví dụ: “truong dai hoc CNTP TPHCM” -> “Truong Dai Hoc CNTP TPHCM”
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Hàm xuất giá trị từng ký tự của chuỗi thông qua con trỏ
void xuatKyTu(const char* str) {
	const char* ptr = str;
	while (*ptr != '\0') {
		printf("%c ", *ptr);
		ptr++;
	}
	printf("\n");
}

// Hàm chuyển các ký tự của chuỗi về dạng chữ hoa
void chuyenChuHoa(char* str) {
	char* ptr = str;
	while (*ptr != '\0') {
		*ptr = toupper(*ptr);
		ptr++;
	}
}

// Hàm chuyển các ký tự đầu mỗi từ về dạng chữ hoa
void chuyenKyTuDauChuHoa(char* str) {
	char* ptr = str;
	int isStartOfWord = 1;

	while (*ptr != '\0') {
		if (isStartOfWord && isalpha(*ptr)) {
			*ptr = toupper(*ptr);
			isStartOfWord = 0;
		}
		else if (isspace(*ptr)) {
			isStartOfWord = 1;
		}
		ptr++;
	}
}

int main() {
	char st[100];

	// Nhập chuỗi từ bàn phím
	printf("Nhap chuoi: ");
	fgets(st, sizeof(st), stdin);

	// Loại bỏ ký tự xuống dòng cuối chuỗi (nếu có)
	st[strcspn(st, "\n")] = 0;

	// Xuất giá trị từng ký tự của chuỗi thông qua con trỏ
	printf("\nGia tri tung ky tu cua chuoi: ");
	xuatKyTu(st);

	// Chuyển các ký tự của chuỗi về dạng chữ hoa
	chuyenChuHoa(st);
	printf("\nChuoi sau khi chuyen thanh chu hoa: %s\n", st);

	// Khôi phục lại chuỗi ban đầu
	fgets(st, sizeof(st), stdin);
	st[strcspn(st, "\n")] = 0;

	// Chuyển các ký tự đầu mỗi từ về dạng chữ hoa
	chuyenKyTuDauChuHoa(st);
	printf("\nChuoi sau khi chuyen ky tu dau moi tu thanh chu hoa: %s\n", st);

	// Dùng system("pause") để xem kết quả trên console (Windows)
	system("pause");

	return 0;
}
