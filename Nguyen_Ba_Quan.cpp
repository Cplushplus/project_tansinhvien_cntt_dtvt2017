#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

#define TEN_FILE "D://BTL/DSSV.txt"

struct SinhVien 
{
	int maSV;
	char strTen[100];
	float diem;
	
};
void Menu()
{
	printf("Menu:  \n");
	printf("1. Nhap thong tin 1 sinh vien\n");
	printf("2. Tim kiem va hien thi thong tin sinh vien theo ma sinh vien\n");
	printf("3. Hien thi toan bo sinh vien\n");
	printf("4. Hien thi cac sinh vien co diem > n\n");
	printf("5. Sap xep theo ten cac sinh vien\n");
	printf("6. Thoat chuong trinh\n");
	printf("Moi ban chon:  ");
}
int chonMenu()
{
	int chon;
	scanf("%d", &chon);
	return chon;
}
void nhapThongTin()
{
	struct SinhVien sv;
	FILE *fp;
	    printf("Nhap ma so sinh vien:  ");
	    scanf("%d", &sv.maSV);
	
        fflush(stdin);
	
	    printf("Nhap ten sinh vien:  ");
	    gets(sv.strTen);
	
        printf("Nhap diem cua sinh vien:  ");
	    scanf("%f", &sv.diem);
	    fp = fopen(TEN_FILE, "a");
	
	    if (fp != NULL) {
		fprintf(fp, "Ma so sinh vien:  %d\n", sv.maSV);
		fprintf(fp, "Ho ten sinh vien:  %s\n", sv.strTen);
		fprintf(fp, "Diem cua sinh vien:  %f\n", sv.diem);
		fclose(fp);
	    printf("Moi ban chon muc trong Menu:  ");}
}
void timKiem()
{
	
	struct SinhVien sv[100];
	FILE *fp;
	int ma, i;
	printf("Nhap ma sinh vien can tim:  ");
	scanf("%d", &ma);
	for (i = 0; i < 100; i++)
	{
		if (sv[i].maSV == ma)
	 {
		fp = fopen(TEN_FILE, "r");
	    char buff[255];

        fgets(buff, 255, (FILE*)fp);
        printf("1: %s\n", buff );

        fgets(buff, 255, (FILE*)fp);
        printf("2: %s\n", buff );
   
        fgets(buff, 255, (FILE*)fp);
        printf("3: %s\n", buff );
       fclose(fp);
       printf("Moi ban chon muc trong Menu:  ");
	 }
	}
	
}
char* tachTen(const char* hoVaTen)
{
	char* ten;
	int i, j, k = 0;
	
	
	for (i = strlen(hoVaTen); i >= 0; i--)
	{
		if (hoVaTen[i] == ' ')
		{
			ten = (char*) malloc(sizeof(char) * (strlen(hoVaTen) - i));
			for (j = i + 1; j <= strlen(hoVaTen); j++)
			{
				ten[k] = hoVaTen[j];
				k++;
			} 
			ten[k] = '\0';
			break;
		}
	}
	
return ten;
}

void hienThiToanBo()
{
	int sl, i;
	FILE *fp;
     	fp = fopen(TEN_FILE, "r");
	    char buff[255];
	    printf("So luong sinh vien ban da nhap vao:  ");
	    scanf("%d", &sl);
	    for (i = 0; i < (sl * 3); i++)
	    {
    		fgets(buff, 255, (FILE*)fp);
            printf(" %s\n", buff );
    	}
    	   fclose(fp);
    	   printf("Moi ban chon muc trong Menu:  ");
}
void hienThi()
{
	struct SinhVien sv[100];
	int i, n, tong;
	FILE *fp;
	fp = fopen(TEN_FILE, "r");
	    char buff[255];
        printf("Nhap n:  ");
	    scanf("%d", &n);
	    
	   for (i = 0; i < 100; i++)
	    {
    		if(sv[i].diem > n)
    		{
		    	tong = tong + 1;
		    }
    	} 
	    for (i = 0; i < 100; i++)
	    {
    		if(sv[i].diem > n)
    		{
		    	fgets(buff, 255, (FILE*)fp);
                printf("1: %s\n", buff );

                fgets(buff, 255, (FILE*)fp);
                printf("2: %s\n", buff );
   
                fgets(buff, 255, (FILE*)fp);
                printf("3: %s\n", buff );
		    }
    	}
    	printf("Moi ban chon muc trong Menu:  ");
}
void sapXep(SinhVien a[],int n)
{
	int i, j, k;
	for(i = 0 ;i < n - 1; i++)
	{
		for(j = i + 1 ;j < n; j++)
		{
		   if(strcmp(tachTen(a[i].strTen), tachTen(a[j].strTen)) == 1);
		  {
			SinhVien k = a[i];
            a[i] = a[j];
            a[j] = k;
		  }
		}
	} 
	printf("Moi ban chon muc trong Menu:  ");
}
int main()
{
	struct SinhVien sv[100];
	FILE *fp;
	Menu();
	int chon, i, sl, n, tong = 0;

    do
    {
    	chon = chonMenu();
        if (chon == 1)
     {
    	nhapThongTin();
     }
     else if (chon == 2)
     {
       timKiem();	
     }
     else if (chon == 3)
     {
     	hienThiToanBo();
     }
     else if (chon == 4)
     {
     	hienThi();
     }
     else if (chon == 5)
     {
     	sapXep(sv, 5);
     }
    } while (chon != 6);
   
	
}