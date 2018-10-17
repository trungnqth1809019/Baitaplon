//https://github.com/trungnqth1809019/Baitaplon.git
#include <stdio.h>
#include <stdlib.h>
#include <mem.h>

int imax = 10, idem = 0, iluachon = 0, iluutru = 0;
char tmp[90];
FILE *sv;
//struct
typedef struct {
    char maSV[20];
    char tenSV[50];
    char sdtSV[20];
} sinhvien;
sinhvien tsv[10];

//HAM CHINH
void menu();

void luachon(int *ilc);

void nhapSV();

void hienthiSV();

void luuSV();

void docSV();

//HAM CHUC NANG
void trolaimenu();

//ham tro lai menu
void trolaimenu() {
    char trolai = 0;
    printf("Nhan 'ENTER' de tro lai MENU");
    fflush(stdin);
    scanf("%c", &trolai);
}

//0. Ham menu
void menu() {
    sv = fopen("danhsachsv.txt", "w+");
    fprintf(sv, "%-39cDANH SACH SINH VIEN\n", ' ');
    fprintf(sv, "| %-20s | %-50s | %-20s |\n", "Ma sinh vien", "Ten", "So dien thoai");
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
            default:
                docSV();
                trolaimenu();
                break;
        }
    } while (iluachon != 5);
    printf("Thoat chuong trinh.");
}

//0. Ham lua chon
void luachon(int *ilc) {
    printf("----------------MENU----------------\n");
    printf("1. Them sinh vien moi.\n");
    printf("2. Hien thi danh sach sinh vien.\n");
    printf("3. Luu danh sach sinh vien ra file.\n");
    printf("4. Doc danh sach sinh vien tu file.\n");
    printf("5. Thoat chuong trinh.\n");
    printf("------------------------------------\n");
    scanf("%d", ilc);
    while (!(*ilc == 1 || *ilc == 2 || *ilc == 3 || *ilc == 4 || *ilc == 5)) {
        printf("Lua chon sai.\n");
        printf("Nhap lua chon lai <1/2/3/4/5>.\n");
        scanf("%d", ilc);
    }
}

// 1. ham them sinh vien moi
void nhapSV() {
    char choice = 'y';
    printf("------------------------------------\n");
    printf("%6c1.Them sinh vien moi.\n", ' ');
    printf("------------------------------------");
    while (idem < imax && (choice == 'Y' || choice == 'y')) {
        printf("\nNhap vao thong tin sinh vien thu %d:\n", idem + 1);
        fflush(stdin);
        printf("- Nhap ma sinh vien: ");
        fgets(tsv[idem].maSV, 20, stdin);
        while (strlen(tsv[idem].maSV) != 6) {
            printf("** LOI: Ma sinh vien phai co 5 ki tu **\n");
            printf("- Nhap lai ma sinh vien: ");
            fflush(stdin);
            fgets(tsv[idem].maSV, 20, stdin);
        }
        tsv[idem].maSV[strlen(tsv[idem].maSV) - 1] = ' ';
        fflush(stdin);
        printf("- Nhap ho ten sinh vien: ");
        fgets(tsv[idem].tenSV, 50, stdin);
        tsv[idem].tenSV[strlen(tsv[idem].tenSV) - 1] = ' ';
        fflush(stdin);
        printf("- Nhap so dien thoai: ");
        fgets(tsv[idem].sdtSV, 20, stdin);
        tsv[idem].sdtSV[strlen(tsv[idem].sdtSV) - 1] = ' ';
        idem++;
        if (idem == imax) {
            printf("***** Danh sach sinh vien day! ****\n\n");
            trolaimenu();
            break;
        }
        fflush(stdin);
        printf("Ban co muon nhap tiep ?\n");
        printf("<<Nhap Y/y de tiep tuc / Nhan 'ENTER' de tro lai menu>>\n");
        scanf("%c", &choice);
    }
}

// 2. Hien thi danh sach sinh vien.
void hienthiSV() {
    printf("------------------------------------\n");
    printf("  2. Hien thi danh sach sinh vien.\n");
    printf("------------------------------------\n\n");
    printf("%-40cDANH SACH SINH VIEN\n", ' ');
    printf("| %-20s | %-50s | %-20s |\n", "Ma sv", "Ten", "So dien thoai");
    for (int j = 0; j < idem; j++) {
        printf("| %-20s | %-50s | %-20s |\n", tsv[j].maSV, tsv[j].tenSV, tsv[j].sdtSV);
    }
}

// 3. Luu danh sach sinh vien ra file
void luuSV() {
    printf("------------------------------------\n");
    printf("3. Luu danh sach sinh vien ra file.\n");
    printf("------------------------------------\n");
    sv = fopen("danhsachsv.txt", "a+");
    while (iluutru < idem) {
        fprintf(sv, "| %-20s | %-50s | %-20s |\n", tsv[iluutru].maSV, tsv[iluutru].tenSV, tsv[iluutru].sdtSV);
        iluutru++;
    }
    fclose(sv);
    iluutru = idem;
    printf("Da luu danh sach moi nhap\n");
}

// 4. Doc danh sach sinh vien tu file
void docSV() {
    printf("------------------------------------\n");
    printf("4. Doc danh sach sinh vien tu file.\n");
    printf("------------------------------------\n");
    sv = fopen("danhsachsv.txt", "r+");
    while (fgets(tmp, sizeof(tmp) * sizeof(char), sv) != NULL) {
        printf("%s", tmp);
    }
    fclose(sv);
}

int main() {
    menu();
    return 0;
}
