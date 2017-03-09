#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <io.h>
#include <string.h>
struct ogrenci
{
	char k;
	int notu;
	char adsoyad[30];
	
} ogrkay;
FILE *dosya;
int i, kaysay, say;
long kayit_yer;
char cev,c;

int ksay(void)
{
	return ((filelength(fileno(dosya))/sizeof(struct ogrenci)));
}

void kayit_ekle(void)
{
	dosya = fopen("ogrenci.dat","r+b");
	if (dosya == NULL)
		dosya = fopen("ogrenci.dat","w+b");

	system("cls");
	fflush(stdin);
	printf("Adi........:");
	gets(ogrkay.adsoyad);
	printf("Notu.......:");
	scanf("%d",&ogrkay.notu);
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
void baslik(void)
{
	system("cls");
	if(dosya==NULL) printf("Dosya acilamadi");
	printf("%-25s   %-10s \n\n","AD SOYAD", "NOTU");
	say=0;
}
void listele(void)
{
      int toplam=0; float ort=0;
     
	dosya = fopen("ogrenci.dat","r+b");
	kaysay=ksay();
	printf("\n\nOkunan Veriler........:");
	for(int i=0; i<kaysay; i++)
	{
		fseek(dosya,(i*sizeof(struct ogrenci)),SEEK_SET);
		fread(&ogrkay,sizeof(struct ogrenci),1,dosya);
		if(ogrkay.k=='*')
		{	
			printf("\nOgrencinin Adi  :%s",ogrkay.adsoyad);
			printf("\tve Ogrencinin Notu   :%d",ogrkay.notu);
			toplam+=ogrkay.notu;			
		}
	}
	fclose(dosya);
}

void ortbul(){
	int toplam=0; float ort=0;
	dosya=fopen("ogrenci.dat","r+b");
	for(int i=0; i<kaysay; i++)
	{
		fseek(dosya,(i*sizeof(struct ogrenci)),SEEK_SET);
		fread(&ogrkay,sizeof(struct ogrenci),1,dosya);
		if(ogrkay.k='*')		
		    toplam=toplam+ogrkay.notu;
		
}
printf("\nNotlar toplami=%d\n",toplam);
ort=toplam/kaysay;
printf("Notlar ortalamasi=%.2f\n",ort);

}
int main()
{
	
	 kayit_ekle();
	 listele();
	 ortbul();	
	
}
