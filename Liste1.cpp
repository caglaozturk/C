#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include<locale.h>  
typedef struct ogr_puan{
	unsigned int dkod;
	char ders[25];
	unsigned int vize, final;
	struct ogr_puan *bag;
}dugum;
dugum *liste_olustur(){
	int k, n;
	dugum *p, *head;
	printf ("\n Kaç eleman girilecek : ");
	scanf("%d", &n);
	for (k=0; k<n; k++){
		if (k == 0) {
			head = (dugum *) malloc(sizeof(dugum));
			p = head;
		}
		else {
			p->bag = (dugum *) malloc(sizeof(dugum));
			p = p->bag;
		}
		printf("%d. Ders Kodu\t: ",k+1);scanf("%d", &p->dkod);
		printf("%d. Ders Adi\t: ",k+1);scanf("%s", p->ders);
		printf("%d. Vize    \t: ", k+1);scanf("%d", &p->vize);
		printf("%d. Final   \t: ", k+1);scanf("%d", &p->final);
	}
	p->bag = head;
	return (head);
}
void ekle (dugum **listebasi){
	int no;
	dugum *p, *q, *yeni;
	yeni = (dugum *) malloc(sizeof(dugum));
	printf("\nData to be inserted: ");
	scanf("%d %s %d %d", &yeni->dkod, yeni->ders, &yeni->vize, &yeni->final);
	printf("\nHangi ders kodundan evvel eklensin ! ");
	scanf("%d", &no);
	p = *listebasi;
	if (p->dkod == no) /* At the beginning */{
		q=p;
		p=p->bag;
		while(p->bag!=q)
			p=p->bag;
		if(p->bag==q){
			yeni->bag = q;
			p->bag = yeni;
			*listebasi = yeni;
		}
	}
	else {
		while (p->dkod != no){
			q = p;
			p = p->bag;
			if(p == *listebasi)
				break;
		}
		if (p == *listebasi)/* At the end */{
			q->bag = yeni;
			yeni->bag = *listebasi;
		}
		else if (p->dkod == no)/* In the middle */{
			q->bag = yeni;
			yeni->bag = p;
		}
	}
}
void sil(dugum **listebasi){
	int no;
	dugum *p, *q;
	printf("\nSilinecek ders kodu : ");
	scanf("%d", &no);
	p = *listebasi;
	if (p->dkod == no)/* Delete the first element */{	
		q=p;
		p=p->bag;
		while(p->bag!=q)
			p=p->bag;
		if(p->bag==q){
			p ->bag = q->bag;
			*listebasi=q->bag;
			free(q);
		}
	}
	else {
		while (p->dkod != no){
			q = p;
			p = p->bag;
			if(p == *listebasi)
				break;
		}
		if (p == *listebasi)/* Element not found */
			printf("\nAranan ders kodu bulunamad?...");
		else if (p->dkod == no) /* Delete any other element */{
			q->bag = p->bag;
			free (p);
		}
	}
}
void goster(dugum *listebasi){
	int count = 1;
	dugum *p;
	p = listebasi;
	while(1)
	{
		printf("\nNode %d: %d %s %d %d %.2f", count, p->dkod, p->ders, p->vize,p->final, p->vize*0.4 +p->final *0.6);
		count++;
		if(p->bag==listebasi)
			break;
		else
			p = p->bag;
	}
	printf("\n");
	getch();
}
void bul(dugum *listebasi)
{
	dugum *p,*sonuc;
	p = listebasi;
	float EB=0.0;
	while(1)
	{
		float ort=p->vize * 0.4 + p->final *0.6;
		if(ort > EB)
		{
			EB=ort;
			sonuc=p;
		}
		if(p->bag==listebasi)
			break;
		else
			p = p->bag;
	}
	printf("\nEn yuksek puanli ders....\n %s %d %d %2.f",sonuc->ders, sonuc->vize,sonuc->final, sonuc->vize*0.4 +sonuc->final *0.6);
}
int main()
{
	setlocale(LC_ALL, "Turkish");
	dugum *listebasi=liste_olustur();
	dugum *p;
	char sec;
	do{
		system("cls");
		printf("\n\n1 - Ekle\n2 - Sil\n3- Göster\n4- En Yüksek Ders\n5- Son\n\nSec :");
		sec = getche();
		switch (sec){
			case '1':
				ekle (&listebasi);
				goster(listebasi);
			break;
			case '2':
				sil(&listebasi);
				goster(listebasi);
			break;
			case '3':
				printf("\nKayýtlar...: ");
				goster(listebasi);
			break;
			case '4':
				bul(listebasi);
				
				getch();
			break;
			case '5':
				exit(1);
			break;
		}
	} while (1);
	getch();}

