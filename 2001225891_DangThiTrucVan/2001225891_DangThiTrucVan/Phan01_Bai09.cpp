#include <stdio.h>

void tinhToan(int *pa, int *pb, int *tong, int *hieu, int *tich, float *thuong) {
	*tong = *pa + *pb;
	*hieu = *pa - *pb;
	*tich = *pa * *pb;
	if (*pb != 0)
		*thuong = (float)*pa / *pb;
}

int main() {
	int a, b;
	int tong, hieu, tich;
	float thuong;

	printf("Nhap vao so a: ");
	scanf("%d", &a);
	printf("Nhap vao so b: ");
	scanf("%d", &b);

	tinhToan(&a, &b, &tong, &hieu, &tich, &thuong);

	printf("Tong: %d, Dia chi: %p\n", tong, (void*)&tong);
	printf("Hieu: %d, Dia chi: %p\n", hieu, (void*)&hieu);
	printf("Tich: %d, Dia chi: %p\n", tich, (void*)&tich);
	if (b != 0)
		printf("Thuong: %.2f, Dia chi: %p\n", thuong, (void*)&thuong);
	else
		printf("Thuong: Khong the chia cho 0\n");

	return 0;
}
