/*
Viết chương trình thực hiện các công việc sau:
Một kiểu dữ liệu cấu trúc Sinhvien gồm các trường:
mã sinh viên: kiểu số nguyên dương
tên sinh viên: kiểu xâu <= 100 ký tự
điểm: kiểu số thực từ 0 tới 10
- Tạo 1 menu gồm các chức năng sau:
1. Nhập thông tin 1 sinh viên
2. Tìm kiếm và hiển thị thông tin sinh viên theo mã sinh viên
3. Hiển thị toàn bộ sinh viên
4. Hiển thị các sinh viên có điểm > n(n nhập từ bàn phím, n từ 0 tới 10)
5. Sắp xếp theo tên các sinh viên
Yêu cầu:
Sử dụng ngôn ngữ C để viết
Sử dụng file để lưu danh sách sinh viên
Sử dụng hàm void Menu() để hiển thị các chọn lựa cho người dùng
Các yêu cầu từ 1 tới 5 đều viết dưới dạng hàm
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#define MAX_SV 100
#define KHONG 0

int dem = 0;
struct Sinhvien{
    int MSSV;
    char HoVaTen[100];
    float Diem;
    char Ten[10];
} ds[MAX_SV];

void chon1() {
    int kt, i;

    USE1:
    system("cls");
    printf("MSSV: "); scanf("%d", &ds[dem].MSSV);

    for (i=0; i<dem; i++)
        if (ds[i].MSSV == ds[dem].MSSV){
            printf("MSSV da co tren he thong moi ban nhap lai\nAn Enter de vao giao dien nhap lai");
            getch();
            goto USE1;
        }

    fflush(stdin);

    printf("Ho va ten: ");
    gets(ds[dem].HoVaTen);

    SAIDIEM: printf("Diem: ");
    scanf("%f", &ds[dem].Diem);

    if ((ds[dem].Diem<0)||(ds[dem].Diem>10)) {
            printf("Diem ban nhap khong hop le, moi ban nhap lai diem:\n");
            goto SAIDIEM;
    }

    dem++;

    printf("\nBan muon tiep tuc nhap thong tin sinh vien?\nNhap 1 neu muon tiep tuc\nNhap 0 de thoat khoi phan nay!\nChon:");
    scanf("%d", &kt);

    if (kt == 1) goto USE1;
    return 0;
}

void chon2() {
    int MS_Search, i, kiemtra;
    USE2: kiemtra = KHONG;

    system("cls");
    printf("Moi ban nhap MSSV can tim kiem: ");
    scanf("%d", &MS_Search);

    for(i = 0; i<dem; i++)
    if (ds[i].MSSV == MS_Search)
    {
        printf("MSSV: %d\tHo Va Ten: %s\tDiem: %.2f\n", ds[i].MSSV, ds[i].HoVaTen, ds[i].Diem);
        kiemtra = 1;
        break;
    }

    if (kiemtra == KHONG) printf("Khong ton tai sinh vien co MSSV la %d tren he thong!\n", MS_Search);

    getch();

    printf("\nBan muon tiep tuc tim kiem?\n0. Khong\n1. Co\nBan Chon: "); scanf("%d", &kiemtra);

    if (kiemtra == 1) goto USE2;
    return 0;
}

void chon3() {
    int i;
    system("cls");
    printf("Danh sach toan bo sinh vien:\n");
    for(i=0; i<dem; i++)
        printf("\nMSSV: %8d\tHo Va Ten: %25s\tDiem: %.2f", ds[i].MSSV, ds[i].HoVaTen, ds[i].Diem);

    getch();
    system("cls");
    return 0;
}

void chon4() {
    float diem;
    int i;

    system("cls");

    printf("Nhap so diem ma ban muon tra cuu: ");
    scanf("%f", &diem);

    for(i=0; i<dem; i++)
    {
        if(ds[i].Diem > diem)
        printf("\nMSSV: %8d\tHo Va Ten: %25s\tDiem: %.2f", ds[i].MSSV, ds[i].HoVaTen, ds[i].Diem);
    }
    getch();
    return 0;
}

void TaoTen(void){
    int i,j, dau, cuoi, size;

    for(i=0; i<dem; i++){
        cuoi = strlen(ds[i].HoVaTen) - 1;

        while (ds[i].HoVaTen[cuoi] == ' ') {
                cuoi--;
                if(cuoi == 0) break;
        }

        dau = cuoi;

        while (ds[i].HoVaTen[dau] != ' '){
            if(dau == 0) break;
            dau--;
        }

        size = 0;
        for(j = dau; j <= cuoi; j++)
        {
            if(ds[i].HoVaTen[j] != ' ')
            {
            ds[i].Ten[size] = ds[i].HoVaTen[j];
            size++;
            }
        }
        ds[i].Ten[size]='\0';
    }
    return 0;
}
void chon5() {

    int i, j;
    struct Sinhvien hoandoi;

    TaoTen();
    for(i=0; i< (dem-1) ; i++)
        for(j=i+1; j<dem; j++){
            if (strcmp(ds[i].Ten, ds[j].Ten) > 0) {
                    hoandoi = ds[i];
                    ds[i] = ds[j];
                    ds[j] = hoandoi;
               }
            if (strcmp(ds[i].Ten, ds[j].Ten) == 0) {
                   if (ds[i].MSSV > ds[j].MSSV) {
                        ds[dem] = ds[i];
                        ds[i] = ds[j];
                        ds[j] = ds[dem];
                   }
               }
            }
    for(i=0; i<dem; i++)
        printf("\nMSSV: %8d\tHo Va Ten: %25s\tDiem: %.2f", ds[i].MSSV, ds[i].HoVaTen, ds[i].Diem);

    getch();
    return 0;
}

void menu(){
    int chon, tieptuc;

    Tiep_tuc:
    system("cls");
    printf("Menu:\n");
    printf("1. Nhap thong tin 1 sinh vien\n");
    printf("2. Tim kiem va hien thi thong tin sinh vien theo ma sinh vien\n");
    printf("3. Hien thi toan bo sinh vien\n");
    printf("4. Hien thi cac sinh vien co diem > n\n");
    printf("5. Sap xep theo ten cac sinh vien\n");

    Nhap: printf("Ban chon so: "); scanf("%d", &chon);
    if ((chon < 1)||(chon > 5))
    {
        printf("\nSo khong hop le\nmoi nhap lai!\n");
        goto Nhap;
    }
    else
    switch(chon){
        case 1: chon1();
                    break;
        case 2: chon2();
                    break;
        case 3: chon3();
                    break;
        case 4: chon4();
                    break;
        case 5: chon5();
                    break;
    };

    system("cls");
    do  {
    printf("\nBan muon tiep tuc su dung menu?\n0. khong\n1. co\nMoi ban chon: ");
    scanf("%d", &tieptuc);
    }
    while ((tieptuc != 0) && (tieptuc != 1));

    if (tieptuc == 1) goto Tiep_tuc;

    printf("\nMenu ket thuc! Nhan Enter!");
    return 0;
}

int main() {
    FILE* F;
    int i;
    menu();

    F = fopen("DS_SinhVien.txt", "w");

    fprintf(F, "Danh Sach Sinh Vien\n");
    for(i=0; i<dem; i++) {
        fprintf(F, "MSSV: %8d\tHo Va Ten: %25s\tDiem: %.2f\n", ds[i].MSSV, ds[i].HoVaTen, ds[i].Diem);
    }
    fclose(F);

    getch();
    return 0;
}
