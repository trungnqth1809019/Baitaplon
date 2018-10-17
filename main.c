//https://github.com/trungnqth1809019/Baitaplon.git
#include <stdio.h>
#include <stdlib.h>
#include <mem.h>

int imax = 10, idem = 0, iluachon = 0, iluutru = 0;
char tmp[75];
FILE *sv;
//struct
typedef struct {
    char maSV[12];
    char tenSV[40];
    char sdtSV[15];
} sinhvien;
sinhvien tsv[10];

//1. HAM CHINH
void menu();

void luachon(int *ilc);

void nhapSV();

void hienthiSV();

void luuSV();

void docSV();

//2. HAM CHUC NANG
void trolaimenu();

void indaugach();

void boxuongdong(char *mang);

void kiemtramasv(char *mang);

//ham main
int main() {
    menu();
    return 0;
}

//1.0.0. Ham menu
void menu() {
    sv = fopen("danhsachsv.txt", "w+");
    fprintf(sv, "%-29cDANH SACH SINH VIEN\n", ' ');
    fprintf(sv, "| %-12s | %-19c%-21s | %-15s |\n", "Ma sinh vien", ' ', "Ten", "So dien thoai");
    fclose(sv);
    do {
        luachon(&iluachon);
        switch (iluachon) {
            case 1:
                nhapSV();
                break;
            case 2:
                hienthiSV();
                trolaimenu();
                break;
            case 3:
                luuSV();
                trolaimenu();
                break;
            case 4:
                docSV();
                trolaimenu();
                break;
            default :
                break;
        }
    } while (iluachon != 5);
    printf("*** Da thoat chuong trinh. ***");
}

// 1.0. Ham lua chon
void luachon(int *ilc) {
    printf("----------------MENU----------------\n");
    printf("1. Them sinh vien moi.\n");
    printf("2. Hien thi danh sach sinh vien.\n");
    printf("3. Luu danh sach sinh vien ra file.\n");
    printf("4. Doc danh sach sinh vien tu file.\n");
    printf("5. Thoat chuong trinh.\n");
    indaugach();
    scanf("%d", ilc);
    while (!(*ilc == 1 || *ilc == 2 || *ilc == 3 || *ilc == 4 || *ilc == 5)) {
        printf("Lua chon sai.\n");
        printf("Nhap lua chon lai <1/2/3/4/5>.\n");
        scanf("%d", ilc);
    }
}

// 1.1. Ham them sinh vien moi
void nhapSV() {
    indaugach();
    printf("%6c1.Them sinh vien moi.\n", ' ');
    indaugach();
    if (idem < imax) {
        printf("\nNhap vao thong tin sinh vien thu %d:\n", idem + 1);
        printf("- Nhap ma sinh vien: ");
        fflush(stdin);
        fgets(tsv[idem].maSV, 12, stdin);
        kiemtramasv(tsv[idem].maSV);
        boxuongdong(tsv[idem].maSV);
        printf("- Nhap ho ten sinh vien: ");
        fflush(stdin);
        fgets(tsv[idem].tenSV, 40, stdin);
        boxuongdong(tsv[idem].tenSV);
        printf("- Nhap so dien thoai: ");
        fflush(stdin);
        fgets(tsv[idem].sdtSV, 15, stdin);
        boxuongdong(tsv[idem].sdtSV);
        idem++;
    }
    if (idem == imax) {
        printf("***** Danh sach sinh vien day! ****\n\n");
    }
}

// 1.2. Hien thi danh sach sinh vien.
void hienthiSV() {
    indaugach();
    printf("  2. Hien thi danh sach sinh vien.\n");
    indaugach();
    printf("%-29cDANH SACH SINH VIEN\n", ' ');
    printf("| %-12s | %-19c%-21s | %-15s |\n", "Ma sv", ' ', "Ten", "So dien thoai");
    for (int j = 0; j < idem; j++) {
        printf("| %-12s | %-40s | %-15s |\n", tsv[j].maSV, tsv[j].tenSV, tsv[j].sdtSV);
    }
}

// 1.3. Luu danh sach sinh vien ra file
void luuSV() {
    indaugach();
    printf("3. Luu danh sach sinh vien ra file.\n");
    indaugach();
    sv = fopen("danhsachsv.txt", "a+");
    while (iluutru < idem) {
        fprintf(sv, "| %-12s | %-40s | %-15s |\n", tsv[iluutru].maSV, tsv[iluutru].tenSV, tsv[iluutru].sdtSV);
        iluutru++;
    }
    fclose(sv);
    printf("*** Da luu danh sach moi nhap ***\n");
}

// 1.4. Doc danh sach sinh vien tu file
void docSV() {
    indaugach();
    printf("4. Doc danh sach sinh vien tu file.\n");
    indaugach();
    sv = fopen("danhsachsv.txt", "r+");
    while (fgets(tmp, sizeof(tmp) * sizeof(char), sv) != NULL) {
        printf("%s", tmp);
    }
    fclose(sv);
}

//2.1. Ham tro lai menu
void trolaimenu() {
    char trolai = 0;
    printf("*** Nhan 'ENTER' de tro lai MENU ***");
    fflush(stdin);
    scanf("%c", &trolai);
}

//2.2. ham in ra day ky tu '-'
void indaugach() {
    printf("------------------------------------\n");
}

//2.3. Ham thay the \n
void boxuongdong(char *mang) {
    mang[strlen(mang) - 1] = ' ';
}

//2.4. Ham kiem tra ma sinh vien
void kiemtramasv(char *mang) {
    while (strlen(mang) != 6) {
        printf("** LOI: Ma sinh vien phai co 5 ki tu **\n");
        printf("- Nhap lai ma sinh vien: ");
        fflush(stdin);
        fgets(mang, 12, stdin);
    }
}