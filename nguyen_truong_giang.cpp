#include <stdio.h>
#include <conio.h>
#include <string.h>

// Dinh nghia cau truc luu tru thong tin sinh vien.
struct SinhVien
{
   char Ma[7];
   char Ten[31];
   char Lop[7];
   float Diem;
};

// Khai bao mang de luu tru danh sach sinh vien.
struct SinhVien sv[25];
int n = 0; // Bien luu tru so sinh vien hien tai.

// Ham thuc hien in Menu.
int HienThiMenu()
{

   printf("\nCAC CHUC NANG CHINH CUA CHUONG TRINH\n");
   printf("1. Nhap danh sach thong tin sinh vien\n");
   printf("2. In danh sach thong tin sinh vien\n");
   printf("3. Tim kiem thong tin sinh vien theo id\n");
   printf("4.  danh sach sinh vien co diem lon hon diem so sanh\n");
   printf("5. Thoat khoi chuong trinh\n");
   printf("Ban chon: ");
   int chon;
   scanf("%d",&chon);
   return chon;
}

// Ham nhap danh sach sinh vien.
void NhapDanhSachSinhVien()

{

    char Tiep_tuc;

    printf("\n----------------------\n");
   printf("NHAP DANH SACH SINH VIEN\n");
   printf("=====================\n");

   // Nhap danh sach sinh vien.
   do
   {
      printf("Nguoi thu %d:\n",n+1);
      printf("\tMa: ");
      fflush(stdin);
      gets(sv[n].Ma);
      // Neu Ma la khoang trang thi dung ko nhap tiep.
      // Ma la khoang trang neu do dai cua Ma la 0.
      if (strlen(sv[n].Ma)==0)
      {
        break;
      }
      printf("\tTen: ");
      fflush(stdin);
      gets(sv[n].Ten);
      printf("\tLop: ");
      fflush(stdin);
      gets(sv[n].Lop);
      printf("\tDiem: ");
      scanf("%f",&sv[n].Diem);
      n++;
        printf("Ban co nhap nua khong ? (y/n) ");
        fflush(stdin);
        scanf("%c",&Tiep_tuc);
   }while (Tiep_tuc!='n' && Tiep_tuc!='N');;
}

// Ham in danh sach sinh vien.
void InDanhSachSinhVien()
{
    printf("\n-----------------\n");
   printf("DANH SACH SINH VIEN\n");
   printf("-------------------\n");

   printf("%-14s %-25s %-8s  Diem\n","Ma sinh vien", "Ten sinh vien", "Lop");
   for (int i=0; i<n; i++)
   {
        printf("%-14s %-25s %-8s  %.1f\n",sv[i].Ma, sv[i].Ten, sv[i].Lop, sv[i].Diem);
   }

   printf("\nBam ENTER de tiep tuc");
   getch();
}

// Ham tim kiem.
void TimKiem()
{
    printf("\n----------------\n");
   printf("TIM KIEM THONG TIN id\n");
   printf("------------------\n");

    char Ma[7];
      printf("Ma: ");
      fflush(stdin);
      gets(Ma);

      struct SinhVien svTimThay;
      int timThay = 0;
      for (int i=0; i<n; i++)
      {
        // Neu Ma nhap trung voi ma cua sinh vien thu i
         // -> Tim thay.
         if (strcmp(Ma,sv[i].Ma)==0)
            {
                svTimThay = sv[i];
            timThay = 1;
            break;
         }
      }

      printf("Ket qua tim kiem:\n");
      if (timThay==0)
      {
        printf("Khong tim thay sinh vien nao co ma la [%s]\n",Ma);
      }
      else
      {
            printf("%-14s %-25s %-8s  Diem\n","Ma sinh vien", "Ten sinh vien", "Lop");
            printf("%-14s %-25s %-8s  %.1f\n",svTimThay.Ma, svTimThay.Ten, svTimThay.Lop, svTimThay.Diem);
      }


   printf("\nBam ENTER de tiep tuc");
   getch();
}

// Ham in danh sach sinh vien thi do.
void Danh_Sach_Sinh_Vien_Co_Diem_LOn_Diem_ss()
{
    float diem;
    printf ("nhap diem so sanh ");
    scanf ("%f",&diem);
    printf("\n------------------------\n");
   printf("DANH SACH SINH VIEN CO DIEM LON %f \n",diem);
   printf("--------------------------\n");

   printf("%-14s %-25s %-8s  Diem\n","Ma sinh vien", "Ten sinh vien", "Lop");
   for (int i=0; i<n; i++)
   {
    if (sv[i].Diem>=diem)
      {
            printf("%-14s %-25s %-8s  %.1f\n",sv[i].Ma, sv[i].Ten, sv[i].Lop, sv[i].Diem);
      }
   }

   printf("\nBam ENTER de tiep tuc");
   getch();
}
void Sap_Xep(){
    char trung_gian[30];
    for (int i = 0; i<n ; i++)
    {
        for (int j =i ; j<n ; j++)
        {
            if (strcmp(sv[i].Ten , sv[j].Ten)>0 )
            {
                 trung_gian = sv[i].Ten;
                sv[i].Ten = sv[j].Ten;
                sv[j].Ten =trung_gian;
            }
        }
    }
}


int main()
{
    int chon;
   do
   {
    chon = HienThiMenu();
    switch (chon)
    {
        case 1:
            NhapDanhSachSinhVien();
            break;
        case 2:
            InDanhSachSinhVien();
            break;
        case 3:
            TimKiem();
            break;
        case 4:
            Danh_Sach_Sinh_Vien_Co_Diem_LOn_Diem_ss();
            break;
        case 5:
            Sap_Xep();
            break;
      }
    }
   while (chon!=6);
}
