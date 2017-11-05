#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "D:\\baitaplonzent.txt"

struct Sinhvien
{
	char hoTen[100];
	char ten[100];
	int maSinhVien;
	float diem;
};

struct Sinhvien sv[100];
char *p, s[100][100], dem, ten[5][100];
int soLuongSinhVien;
float diemCheck, IDCheck;
int i, j;

void Menu()
{
	printf("\n******************************************************************************");
	printf("\n**********************************---MENU---**********************************");
	printf("\n******************************************************************************");
	printf("\n**---------------Chon 1: Nhap them thong tin 1 sinh vien--------------------**");
	printf("\n**---------------Chon 2: Tim kiem sinh vien theo ma sinh vien---------------**");
	printf("\n**---------------Chon 3: Hien thi toan bo sinh vien da nhap-----------------**");
	printf("\n**---------------Chon 4: Hien thi cac sinh vien co diem lon hon n-----------**");
	printf("\n**---------------Chon 5: Sap xep theo ten cac sinh vien---------------------**");
	printf("\n******************************************************************************");
	printf("\n******************************************************************************");
}

void Nhap()
{

	for (i = 0; i < soLuongSinhVien; ++i)
	{
		printf("\nThong tin sinh vien %d", i + 1);

		printf("\nHo va ten sinh vien : ");
		fflush(stdin);
		gets(sv[i].hoTen);

		printf("\nMa sinh vien: ");
		scanf("%d", &sv[i].maSinhVien);
		while(sv[i].maSinhVien < 0)
		{
			printf("\nNhap sai roi! hay nhap lai: ");
			scanf("%d", &sv[i].maSinhVien);
		}

		printf("\nDiem: ");
		scanf("%f", &sv[i].diem);
		while(sv[i].diem < 0 || sv[i].diem > 10)
		{
			printf("\nNhap sai roi! hay nhap lai: ");
			scanf("%f", &sv[i].diem);
		}
	}
}


void Nhapthemsinhvien()
{
	int them;
	soLuongSinhVien++;
	them = soLuongSinhVien - 1;
	printf("\nThong tin sinh vien %d", them + 1);

	printf("\nHo va ten sinh vien : ");
	fflush(stdin);
	gets(sv[them].hoTen);

	printf("\nMa sinh vien: ");
	scanf("%d", &sv[them].maSinhVien);
	while(sv[them].maSinhVien < 0)
	{
		printf("\nNhap sai roi! hay nhap lai: ");
		scanf("%d", &sv[them].maSinhVien);
	}

	printf("\nDiem: ");
	scanf("%f", &sv[them].diem);
	while(sv[them].diem < 0 || sv[them].diem > 10)
	{
		printf("\nNhap sai roi! hay nhap lai: ");
		scanf("%d", &sv[them].diem);
	}
}

void TimkiemtheoID()
{
	printf("\nNhap vao ma sinh vien de kiem tra: ");
	scanf("%f", &IDCheck);

	for (i = 0; i < soLuongSinhVien; ++i)
	{
		if (IDCheck == sv[i].maSinhVien)
		{
			printf("\nThong Tin Sinh Vien:");
			printf("\nHo va ten: %s", sv[i].hoTen);
			printf("\nDiem: %.2f", sv[i].diem);
		}
	}
}

void Hienthifull()
{
	for (i = 0; i < soLuongSinhVien; ++i)
	{
		printf("\nSinh vien %d:", i + 1);
		printf("\nHo va ten : %s", sv[i].hoTen);
		printf("\nMa sinh vien: %d", sv[i].maSinhVien);
		printf("\nDiem: %.2f\n\n", sv[i].diem);
	}
}

void Hienthidiem()
{
	printf("\nNhap diem de kiem tra: ");
	scanf("%f", &diemCheck);
	
	while(diemCheck < 0 || diemCheck > 10)
	{
		printf("\nNhap sai roi! hay nhap lai: ");
		scanf("%f", &diemCheck);
	}
	printf("\nNhung sinh vien co diem lon hon %f la: ", diemCheck);
	for (i = 0; i < soLuongSinhVien; ++i)
	{
		if (sv[i].diem >= diemCheck)
		{
			printf("\nHo Ten: %s", sv[i].hoTen);
			printf("\nMa sinh vien: %d", sv[i].maSinhVien);
			printf("\nDiem: %.2f\n\n", sv[i].diem);
		}
	}
}

void Tachten()
{
	for (i = 0; i < soLuongSinhVien; ++i)
	{
		//tach chuoi ho ten tai vi tri co space
		char *p = strtok(sv[i].hoTen, " ");
		j = 0;
		char str1[5][100];

		while(p != NULL)
		{
			strcpy(str1[j], p);
			j++;
			p = strtok('\0', " ");
		}
		//copy gia tri cho sv[i].ten
		strcpy(sv[i].ten, str1[j - 1]);
		// strcpy(sv[i].msv, sv[j - 1].maSinhVien);
		// strcpy(sv[i].d, sv[j - 1]).diem;
	}
}

void Sosanh()
{
	for (i = 0; i < soLuongSinhVien; ++i)
	{
		for (j = i; j < soLuongSinhVien; ++j)
		{
			//so sanh hieu vi tri cua hai chu trong bang ma ASCII
			//neu lon hon 0 ta thuc hien dao vi tri
			if (strcmp(sv[i].ten, sv[j].ten) > 0)
			{
				char doiChoTen[100];
				//luu gia tri cua sv[j].ten
				strcpy(doiChoTen, sv[i].ten);
				//gan gia tri cua sv[i].ten cho s[j]
				strcpy(sv[i].ten, sv[j].ten);
				//gan gia tri cua s[j] cho doiCho
				strcpy(sv[j].ten, doiChoTen);
			}
		}
	}
}
void Sapxep()
{
	for (i = 0; i < soLuongSinhVien; ++i)
	{
		printf("\nHo Ten: %s", sv[i].ten);
		printf("\nMa sinh vien: %d", sv[i].maSinhVien);
		printf("\nDiem: %.2f\n\n", sv[i].diem);
	}
}

void choose1()
{
	int choose;
	Menu();

	printf("\nBan chon: ");
	scanf("%d", &choose);

	while (choose < 1 || choose > 5)
	{
		printf("\nNhap sai!, hay nhap lai: ");
		scanf("%d", &choose);
	}
	if(choose == 1)
	{
		Nhapthemsinhvien();
	}
	if (choose == 2)
	{
		TimkiemtheoID();
	}
	if (choose == 3)
	{
		Hienthifull();
	}
	if (choose == 4)
	{
		Hienthidiem();
	}
	if (choose == 5)
	{
		Tachten();
		Sosanh();
		Sapxep();
	}
}


int main()
{

	printf("\nNhap vao so luong sinh vien: ");
	scanf("%d", &soLuongSinhVien);

	while(soLuongSinhVien < 0)
	{
		printf("\nNhap sai roi! Hay  nhap lai: ");
		scanf("%d", &soLuongSinhVien);
	}

	Nhap();
	int choose;
	Menu();

	printf("\nBan chon: ");
	scanf("%d", &choose);

	while (choose < 1 || choose > 5)
	{
		printf("\nNhap sai!, hay nhap lai: ");
		scanf("%d", &choose);
	}
	if(choose == 1)
	{
		Nhapthemsinhvien();
		choose1();
	}
	if (choose == 2)
	{
		TimkiemtheoID();
	}
	if (choose == 3)
	{
		Hienthifull();
	}
	if (choose == 4)
	{
		Hienthidiem();
	}
	if (choose == 5)
	{
		Tachten();
		Sosanh();
		Sapxep();
	}

	FILE *fp;

	//open to write
	fp = fopen("D:\\baitaplonzent.txt", "w+");

	if (fp != NULL)
	{
		for (i = 0; i < soLuongSinhVien; ++i)
		{
			fprintf(fp, "\nSinh vien %d:", i + 1);
			fprintf(fp, "\nHo va ten : %s", sv[i].hoTen);
			fprintf(fp, "\nMa sinh vien: %d", sv[i].maSinhVien);
			fprintf(fp, "\nDiem: %.2f\n\n", sv[i].diem);
		}
		fclose(fp);
		printf("\nwrited file");
	}
	else
	{
		printf("\nCan't open file!");
	}
}