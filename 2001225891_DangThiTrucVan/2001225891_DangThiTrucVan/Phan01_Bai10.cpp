#include <stdio.h>
#include <ctype.h>
#include <string.h>

void xuatKyTu(char *st) {
	while (*st != '\0') {
		printf("%c ", *st);
		st++;
	}
	printf("\n");
}

void chuyenChuHoa(char *st) {
	while (*st != '\0') {
		*st = toupper(*st);
		st++;
	}
}

void chuyenChuHoaDauMoiTu(char *st) {
	int dauTu = 1;
	while (*st != '\0') {
		if (isspace(*st)) {
			dauTu = 1;
		}
		else if (dauTu && isalpha(*st)) {
			*st = toupper(*st);
			dauTu = 0;
		}
		st++;
	}
}

int main() {
	char st[100];

	printf("Nhap vao chuoi: ");
	fgets(st, sizeof(st), stdin);

	// Loai bo ky tu newline neu co
	st[strcspn(st, "\n")] = '\0';

	printf("Xuat ky tu: ");
	xuatKyTu(st);

	chuyenChuHoa(st);
	printf("Chuoi chu hoa: %s\n", st);

	// Chuyen chuoi ve dang goc de tiep tuc
	printf("Nhap lai chuoi: ");
	fgets(st, sizeof(st), stdin);
	st[strcspn(st, "\n")] = '\0';

	chuyenChuHoaDauMoiTu(st);
	printf("Chuoi chu hoa dau moi tu: %s\n", st);

	return 0;
}
