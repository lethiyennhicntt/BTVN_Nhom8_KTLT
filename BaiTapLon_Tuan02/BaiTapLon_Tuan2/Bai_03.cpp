/*
	Bài 03: Xây dựng chương trình quản lý thông tin đặt vé của khách hàng trong một rạp chiếu
	phim. Mỗi khách hàng đặt vé cần cung cấp các thông tin thích hợp.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 100
#define MAX_PHONE_LEN 15
#define MAX_MOVIE_LEN 100
#define MAX_ROOM_LEN 10
#define MAX_SHOWTIME_LEN 20
#define MAX_CUSTOMERS 100

typedef struct {
	char hoTen[MAX_NAME_LEN];
	char soDienThoai[MAX_PHONE_LEN];
	int soVeNguoiLon;
	int soVeTreEm;
	char tenPhim[MAX_MOVIE_LEN];
	char phongChieu[MAX_ROOM_LEN];
	char xuatChieu[MAX_SHOWTIME_LEN];
	int tienPhaiTra;
} KhachHang;

KhachHang dskh[MAX_CUSTOMERS];
int soLuongKhach = 0;

// Hàm tính tiền phải trả cho mỗi khách hàng
#define TIEN_VE_TRE_EM 20000
#define TIEN_VE_NGUOI_LON 40000

void tinhTienPhaiTra(KhachHang* kh) {
	kh->tienPhaiTra = kh->soVeNguoiLon * TIEN_VE_NGUOI_LON + kh->soVeTreEm * TIEN_VE_TRE_EM;
}

// Hàm đọc dữ liệu từ file
void docDuLieuTuFile(const char* filename) {
	FILE* file = fopen(filename, "r");
	if (file == NULL) {
		printf("Khong the mo file.\n");
		return;
	}
	while (fscanf(file, "%s %s %d %d %s %s %s",
		dskh[soLuongKhach].hoTen,
		dskh[soLuongKhach].soDienThoai,
		&dskh[soLuongKhach].soVeNguoiLon,
		&dskh[soLuongKhach].soVeTreEm,
		dskh[soLuongKhach].tenPhim,
		dskh[soLuongKhach].phongChieu,
		dskh[soLuongKhach].xuatChieu) != EOF) {
		tinhTienPhaiTra(&dskh[soLuongKhach]);
		soLuongKhach++;
	}
	fclose(file);
}

// Hàm xuất danh sách khách hàng ra màn hình
void xuatDanhSachKhachHang() {
	for (int i = 0; i < soLuongKhach; i++) {
		printf("Ho Ten: %s\n", dskh[i].hoTen);
		printf("So Dien Thoai: %s\n", dskh[i].soDienThoai);
		printf("So Ve Nguoi Lon: %d\n", dskh[i].soVeNguoiLon);
		printf("So Ve Tre Em: %d\n", dskh[i].soVeTreEm);
		printf("Ten Phim: %s\n", dskh[i].tenPhim);
		printf("Phong Chieu: %s\n", dskh[i].phongChieu);
		printf("Xuat Chieu: %s\n", dskh[i].xuatChieu);
		printf("Tien Phai Tra: %d\n\n", dskh[i].tienPhaiTra);
	}
}

// Hàm tính tổng doanh thu
int tinhTongDoanhThu() {
	int tongDoanhThu = 0;
	for (int i = 0; i < soLuongKhach; i++) {
		tongDoanhThu += dskh[i].tienPhaiTra;
	}
	return tongDoanhThu;
}

// Hàm tính doanh thu theo từng phim
void tinhDoanhThuTheoPhim() {
	char tenPhim[MAX_MOVIE_LEN];
	printf("Nhap ten phim: ");
	scanf("%s", tenPhim);
	int tongDoanhThu = 0;
	for (int i = 0; i < soLuongKhach; i++) {
		if (strcmp(dskh[i].tenPhim, tenPhim) == 0) {
			tongDoanhThu += dskh[i].tienPhaiTra;
		}
	}
	printf("Doanh thu cua phim %s: %d\n", tenPhim, tongDoanhThu);
}

// Hàm xuất thông tin khách hàng theo phòng chiếu và xuất chiếu
void xuatThongTinTheoPhongVaXuatChieu() {
	char phongChieu[MAX_ROOM_LEN];
	char xuatChieu[MAX_SHOWTIME_LEN];
	printf("Nhap phong chieu: ");
	scanf("%s", phongChieu);
	printf("Nhap xuat chieu: ");
	scanf("%s", xuatChieu);
	for (int i = 0; i < soLuongKhach; i++) {
		if (strcmp(dskh[i].phongChieu, phongChieu) == 0 &&
			strcmp(dskh[i].xuatChieu, xuatChieu) == 0) {
			printf("Ho Ten: %s\n", dskh[i].hoTen);
			printf("So Dien Thoai: %s\n", dskh[i].soDienThoai);
			printf("So Ve Nguoi Lon: %d\n", dskh[i].soVeNguoiLon);
			printf("So Ve Tre Em: %d\n", dskh[i].soVeTreEm);
			printf("Ten Phim: %s\n", dskh[i].tenPhim);
			printf("Phong Chieu: %s\n", dskh[i].phongChieu);
			printf("Xuat Chieu: %s\n", dskh[i].xuatChieu);
			printf("Tien Phai Tra: %d\n\n", dskh[i].tienPhaiTra);
		}
	}
}



// Hàm tìm kiếm khách hàng theo tên bằng Binary Search
int timKiemKhachHang(const char* ten) {
	int left = 0, right = soLuongKhach - 1;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		int cmp = strcmp(dskh[mid].hoTen, ten);
		if (cmp == 0) {
			return mid;
		}
		else if (cmp < 0) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	return -1;
}




// Hàm so sánh để sắp xếp theo tiền phải trả
int compareByTienPhaiTra(const void* a, const void* b) {
	return ((KhachHang*)a)->tienPhaiTra - ((KhachHang*)b)->tienPhaiTra;
}

// Hàm so sánh để sắp xếp theo tên
int compareByName(const void* a, const void* b) {
	return strcmp(((KhachHang*)a)->hoTen, ((KhachHang*)b)->hoTen);
}

// Hàm sắp xếp danh sách khách hàng theo số tiền phải trả
void sapXepTheoTienPhaiTra() {
	qsort(dskh, soLuongKhach, sizeof(KhachHang), compareByTienPhaiTra);
}

// Hàm sắp xếp danh sách khách hàng theo họ tên
void sapXepTheoTen() {
	qsort(dskh, soLuongKhach, sizeof(KhachHang), compareByName);
}

int main() {
	// Đọc dữ liệu từ file
	docDuLieuTuFile("C:\\Users\\MSII\\Desktop\\upload\\BaiTapLon\\Week_02\\Week_02\\khachhang.txt");

	// Menu chính
	int luaChon;
	do {
		printf("1. Xuat danh sach khach hang\n");
		printf("2. Tinh tong doanh thu\n");
		printf("3. Tinh doanh thu theo phim\n");
		printf("4. Xuat thong tin theo phong chieu va xuat chieu\n");
		printf("5. Sap xep theo tien phai tra\n");
		printf("6. Sap xep theo ten\n");
		printf("7. Tim kiem khach hang theo ten\n");
		printf("0. Thoat\n");
		printf("Chon chuc nang: ");
		scanf("%d", &luaChon);

		switch (luaChon) {
		case 1:
			xuatDanhSachKhachHang();
			break;
		case 2:
			printf("Tong doanh thu: %d\n", tinhTongDoanhThu());
			break;
		case 3:
			tinhDoanhThuTheoPhim();
			break;
		case 4:
			xuatThongTinTheoPhongVaXuatChieu();
			break;

		case 5:
			sapXepTheoTienPhaiTra();
			xuatDanhSachKhachHang();
			break;
		case 6:
			sapXepTheoTen();
			xuatDanhSachKhachHang();
			break;
		case 7: {
			char ten[MAX_NAME_LEN];
			printf("Nhap ten khach hang: ");
			scanf(" %[^\n]", ten);
			int index = timKiemKhachHang(ten);
			if (index != -1) {
				printf("Khach hang %s duoc tim thay.\n", ten);
				printf("Ho Ten: %s\n", dskh[index].hoTen);
				printf("So Dien Thoai: %s\n", dskh[index].soDienThoai);
				printf("So Ve Nguoi Lon: %d\n", dskh[index].soVeNguoiLon);
				printf("So Ve Tre Em: %d\n", dskh[index].soVeTreEm);
				printf("Ten Phim: %s\n", dskh[index].tenPhim);
				printf("Phong Chieu: %s\n", dskh[index].phongChieu);
				printf("Xuat Chieu: %s\n", dskh[index].xuatChieu);
				printf("Tien Phai Tra: %d\n", dskh[index].tienPhaiTra);
			}
			else {
				printf("Khach hang %s khong tim thay.\n", ten);
			}
			break;
		}
		case 0:
			printf("Thoat chuong trinh.\n");
			break;
		default:
			printf("Lua chon khong hop le.\n");
			break;
		}
	} while (luaChon != 0);

	return 0;
}
