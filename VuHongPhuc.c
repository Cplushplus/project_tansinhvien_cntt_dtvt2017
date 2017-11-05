#include<stdio.h>
#include<conio.h>
#define TEN_FILE "baitaplon.txt"

struct Sinhvien 
{
	unsigned maSV;
 	char tenSV[100];
 	float diem;
};

int Menu()
{
	
	int luachon;
	printf("Chon mot muc bang cach mhap so thu tu cua muc do \n");
	printf("1. Nhap thong tin sinh vien \n");
	printf("2. Tim kiem sinh vien theo ma so SV \n");
	printf("3. Danh sach sinh vien \n");
	printf("4. Tim kiem sinh vien co diem lon hon n nhap tu ban phim \n");
	printf("5. Sap xep ten sinh vien \n");
	do
	{
		printf("Moi chon 1 muc: ");
		scanf("%d", &luachon);
	}
	while(luachon > 5 || luachon < 1);
 return luachon;
}	


struct Sinhvien nhapThongTin()
{           
	struct Sinhvien sv1;
	
	printf("Nhap ma so sinh vien: ");
	scanf("%d", &sv1.maSV);
	fflush(stdin);
	
	printf("Nhap ho ten sinh vien: ");
	gets(sv1.tenSV);
	fflush(stdin);
	
	printf("Nhap diem sinh vien: ");
	scanf("%f", &sv1.diem);
	return sv1;
}


void timKiemSinhVien(int n, struct Sinhvien sv[])
{
	system("cls");
	int i, dem = 0, mssv;
	
	printf("Nhap ma so sinh vien can tim kiem: ");
	scanf("%d", &mssv);
	
	for(i = 0; i < n; i++)
	{
		if(mssv == sv[i].maSV)
		{
			dem = dem + 1;
			printf("Sinh vien can tim la: %s \n", sv[i].tenSV);
			printf("Diem cua sinh vien la: %f \n", sv[i].diem);
		}	
	}
	if(dem == 0)
		printf("Sinh vien khong thuoc danh sach");
}


void danhSachSV(int n, struct Sinhvien sv[])
{
	system("cls");
	int i;
	printf("DANH SACH SINH VIEN \n");
	
	for(i = 0; i < n; i++)
	{
		printf("MSSV: %d \t", sv[i].maSV);
		printf("Ho va ten: %s \t", sv[i].tenSV);
		printf("Diem: %f \n", sv[i].diem);
	}
}


void diemSV(int n, struct Sinhvien sv[])
{
	system("cls");
	float diem;
	int i, dem = 0;
	
	do
	{
		printf("Nhap diem so can loc: ");
		scanf("%f", &diem);
	} while(diem < 0 || diem > 10);
	
	printf("Nhung sinh vien co diem lon hon %3.3f la: \n", diem);
	
	for(i = 0; i < n; i++)
		if(sv[i].diem > diem)
		{
			dem = dem + 1;
			printf("MSSV: %d \t", sv[i].maSV);
			printf("Ho va ten: %s \t", sv[i].tenSV);
			printf("Diem: %3.3f \n", sv[i].diem);
		}
	if(dem == 0) 
		printf("Khong co sinh vien nao co diem tren %3.3f", diem);			
}	


void sapXepSinhVien(int n, struct Sinhvien sv[100])
{
	system("cls");
	int i, j, k, chisohang = 0, chisocot = 0;
	struct Sinhvien sv2;
	char ten[n][20];

	for(i = 0; i < n; i++)
	{
		k = strlen(sv[i].tenSV) - 1;
		do k--;
		while (sv[i].tenSV[k] == " ");
	}
	for(j = k + 1;j < strlen(sv[i].tenSV); j++)
	{
		ten[chisocot][chisohang] = sv[i].tenSV[j];
		chisohang++;
		chisocot++;
	}
	
	printf("Danh sach sinh vien sau khi sap xep \n");
	for(i = 0; i < n; i++)
	{
			if(strcmp(ten[i], ten[i + 1]) < 0)
			{
				sv2 = sv[i];
				sv[i] = sv[i + 1];
				sv[i + 1] = sv2;
			}
		printf("MSSV: %d \t", sv[i].maSV);
		printf("Ho va ten: %s \t", sv[i].tenSV);
		printf("Diem: %3.3f \n", sv[i].diem);
	}
}		

	
int main()
{
	FILE *danhsach;
	int i, n, chon;
	
	printf("Nhap si so cua lop: ");
	scanf("%d", &n);
	struct Sinhvien sv1[n];
	
	danhsach = fopen(TEN_FILE, "a+");
	fprintf(danhsach, "DANH SACH SINH VIEN \n");
	for(i = 0; i < n; i++)
	{
		sv1[i] = nhapThongTin();
		fprintf(danhsach, "MSSV: %d \t", sv1[i].maSV);
		fprintf(danhsach, "Ho va ten: %s \t", sv1[i].tenSV);
		fprintf(danhsach, "Diem: %f \n", sv1[i].diem);
	}
	system("cls");
	chon = Menu();
	switch (chon)
	{
		case 1: {
			system("cls");
			n = n + 1;
			sv1[n] = nhapThongTin();
			fprintf(danhsach, "MSSV: %d \t", sv1[n].maSV);
			fprintf(danhsach, "Ho va ten: %s \t", sv1[n].tenSV);
			fprintf(danhsach, "Diem: %f \n", sv1[n].diem);
			}; break;
		case 2: timKiemSinhVien(n, sv1); break;
		case 3: danhSachSV(n, sv1); break;
		case 4: diemSV(n, sv1); break;
		case 5: sapXepSinhVien(n, sv1); break;
	}
	
	fclose(danhsach);
	
	/*int dieukhien;
	printf("Nhap 1 de tro ve menu chinh: ");
	scanf("%d", &dieukhien);
	if(dieukhien == 1)
	{
		system("cls");
		Menu();
	}*/
	return 0;
}
		
	

	
	 		
	