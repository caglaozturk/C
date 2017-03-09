#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <io.h>
#include <string.h>
struct ogrenci
{
	char k;
	char num[10];
	char adsoyad[30];
	char tel[16];
} ogrkay;
FILE *dosya;
int i, kaysay, say;
long kayit_yer;
char cev,c;

int ksay(void)
{
	return ((filelength(fileno(dosya))/sizeof(struct ogrenci)));
}void kayit_ekle(void)
{
	dosya = fopen("ogrenci.dat","r+b");
	if (dosya == NULL)
		dosya = fopen("ogrenci.dat","w+b");

	system("cls");
	fflush(stdin);
	printf("Numara.....:");
	gets(ogrkay.num);
	printf("Ad Soyad ..:");
	gets(ogrkay.adsoyad);

	printf("Girilen Bilgiler Dogru mu? [E/H]");
	cev=getche();
	if(cev=='E' || cev=='e')
	{
		ogrkay.k='*';
		fseek(dosya,filelength(fileno(dosya)),SEEK_SET);
		fwrite(&ogrkay,sizeof(struct ogrenci),1,dosya);
	}

	fclose(dosya);
}

void listele(void)
{
	dosya = fopen("ogrenci.dat","rb");
	
	kaysay=ksay();
	for(int i=0; i<kaysay; i++)
	{
		fseek(dosya,(i*sizeof(struct ogrenci)),SEEK_SET);
		fread(&ogrkay,sizeof(struct ogrenci),1,dosya);
		if(ogrkay.k=='*')
		{
			say++;
			printf("\n%-10s",ogrkay.num);
			printf("%-30s",ogrkay.adsoyad);
		
		
		}
	}
	printf("\nToplam Kayit Sayisi= %d",kaysay);
	printf("\n\nListelenecek kayitlar bitti...");
	fclose(dosya);
}
void ara(void)
{
	dosya = fopen("ogrenci.dat","rb");
	char enuzun[30]="";
	kaysay=ksay();
	for(int i=0; i<kaysay; i++)
	{
		fseek(dosya,(i*sizeof(struct ogrenci)),SEEK_SET);
		fread(&ogrkay,sizeof(struct ogrenci),1,dosya);
		if(ogrkay.k=='*' && strlen(ogrkay.adsoyad)>strlen(enuzun))
		{
			strcpy(enuzun,ogrkay.adsoyad);
		}
	}
	printf("\n\nEn son girilen ogrenci: \n%-10s",ogrkay.num);	printf("%-30s",ogrkay.adsoyad);
	fclose(dosya);
	getch();
}
int main(){
	kayit_ekle();
	listele();
	ara();
	return 0;
}
