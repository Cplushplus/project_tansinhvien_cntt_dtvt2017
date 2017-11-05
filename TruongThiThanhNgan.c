#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void NhapThongTin();
void TimKiem();
void HienThi();
void DiemHon7();
void SapXep();

struct SinhVien
{
    int MaSV;
    char strHoTen[100];
    float Diem;
     char* ten;
};

long size = sizeof(struct SinhVien);
struct SinhVien sv [100];
FILE *fp;
int n,i;
char chon;
int dem = 0;

void main()
{

    menu();
    getch();
}


void menu()
{
    do
    {
        printf("\n\nMENU\n");
        printf("1. Nhap Thong Tin Sinh Vien\n");
        printf("2. Tim Kiem Theo Ma So Sinh Vien\n");
        printf("3. Hien Thi Danh Sach\n");
        printf("4. Hien Thi Sinh Vien Diem > N\n");
        printf("5. Sap Xep Sinh Vien\n");
        printf("6. Ket Thuc\n");
        printf("Moi chon chuc nang: \n");
        chon = getch();
        switch(chon)
        {
            case '1': NhapThongTin();   break;
            case '2': TimKiem();        break;
            case '3': HienThi();        break;
            case '4': DiemHonN();       break;
            case '5': SapXep();         break;
        }
    }
    while(chon != '6');
    getch();
}


void NhapThongTin()
{
    printf("\nNhap so luong SV : ");
    scanf("%d",&n);

    fp = fopen("sv.txt", "w+");
    for(i = 1 ; i <= n ; i++)
    {
        printf("Nhap ma sinh vien thu %d: ",i);
        scanf("%d",&sv[i].MaSV);
        fflush(stdin);

        printf("Nhap ho va ten: ");
        gets(sv[i].strHoTen);

        printf("Nhap diem: ");
        scanf("%f",&sv[i].Diem);
         do
                {
                if((sv[i].Diem < 0)||(sv[i].Diem > 10))
                printf("\n Ban chi co the nhap diem tu 0 den 10\n");
                }
        while((sv[i].Diem < 0)||(sv[i].Diem > 10));

        fwrite(&sv, size, 1, fp);
    }

    fclose(fp);
    printf("\nBan da nhap xong thong tin sinh vien, moi ban tro ve menu chinh\n");

}

void TimKiem()
{
    int k;

    fp = fopen("sv.txt", "r");


    if(n != 0)
    {
        printf("Nhap ma SV can tim kiem: \n");
        scanf("%d",&k);
        printf("Thong tin Sinh vien: \n");
        for(i = 1; i <= n ; i++ )
        {
            if(sv[i].MaSV == k)
            {
                printf("Ma sinh vien: %d\n", sv[i].MaSV);
                printf("Ten sinh vien: %s\n", sv[i].strHoTen);
                printf("Diem: %.2f\n", sv[i].Diem);
                dem++;
            }
        }
        if(dem==0)
            printf("Khong co sinh vien co ma %d\n",k);

        printf("\nBan da thuc hien tim kiem xong, moi ban tro ve menu chinh\n");
    }
    else
    {
        printf("\nBan can nhap thong tin sinh vien truoc\n");
         void menu();
    }

    fclose(fp);


}

void HienThi()
{
    fp = fopen("sv.txt", "rb");

    if(n != 0)
    {
        printf("DANH SACH SINH VIEN\n");
        printf("\n|---MaSV---|-------------Hoten-----------------|--Diem--|");
        for(i = 1; i <= n; i++)
        {
            printf("\n|%9d|%35s|%9.2f|",sv[i].MaSV, sv[i].strHoTen, sv[i].Diem);
        }

        printf("\n|---------|-----------------------------------|----------|");

         printf("\nDanh sach sinh vien da duoc hien thi, moi ban tro ve menu chinh\n");
    }
    else
    {
        printf("\nBan can nhap thong tin sinh vien truoc\n");
         void menu();
    }

    fclose(fp);


}
void DiemHonN()
{
    float d;
    fp = fopen("sv.txt", "rb");

    if(n != 0)
    {
        printf("Nhap diem: ");
        scanf("%f",&d);
        do
        {
            if((d < 0)|| (d > 10))
            printf("\n Ban chi co the nhap diem tu 0 den 10.\n");
        }
        while((d < 0)||(d > 10));
        for (i = 1; i <= n; i++)
            {
                if (sv[i].Diem > d)
                {
                     printf("\n Sinh vien %s co diem %f\n",sv[i].strHoTen,sv[i].Diem);
                    dem ++;
                }
            }
        if (dem == 0)
            printf("\nKhong co sinh vien co diem > %d", d);

        printf("\nBan da hoan thanh xong tim kiem sinh vien co diem lon hon %f, moi ban tro ve menu chinh\n",d);
    }
    else
    {
        printf("\nBan can nhap thong tin sinh vien truoc\n");
        void menu();
    }
     fclose(fp);

}
void SapXep()
{
     fp = fopen("sv.txt", "rb");
     if(n != 0)
    {
        char* tachTen(const char* strHoTen)
        {
            char* ten;
            int i, j, index;

            for (i = strlen(strHoTen) - 1 ; i >= 0 ; i--)
            {
                if (strHoTen[i] == ' ')
                    {
                        ten = (char*) malloc(sizeof(char) * (strlen(strHoTen) - i + 1));

                        for(j = i + 1; j < strlen(strHoTen); j++)
                        {
                            ten[index] = strHoTen[j];
                            index++;
                        }

                        ten[index] = '\0';

                        break;
                    }
            }
            return ten;
        }
        int ch, j;

        for (i = 1; i <= n-1;i++)
                for (j = i+1; j <= n; j++)
                {
                    ch = strcmpi(sv[i].ten,sv[j].ten);
                    if (ch > 0)
                        {
                            struct SinhVien temp;
                            temp=sv[i];
                            sv[i]=sv[j];
                            sv[j]=temp;
                        }
                }
        printf("DANH SACH SINH VIEN\n");
        printf("\n|---MaSV--|-------------Hoten-----------------|--Diem--|");
        for(i = 1; i <= n; i++)
        {
            printf("\n|%9d|%35s|%9.2f|",sv[i].MaSV, sv[i].strHoTen, sv[i].Diem);
        }

        printf("\n|---------|-----------------------------------|----------|\n");

        printf("\nBan da sap xep sinh vien theo thu tu, moi ban tro ve menu chinh\n");
    }
    else
    {
        printf("\nBan can nhap thong tin sinh vien truoc\n");
        void menu();
    }
     fclose(fp);


}
/*Viết chương trình thực hiện các công việc sau:
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
Bảo vệ vào chiều chủ nhật tuần sau.*/
