#include <stdio.h>
#include<conio.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL,"TURKISH");
	char aylar[][10] = {"","Ocak", "Subat", "Mart", "Nisan","May�s", "Haziran", "Temmuz", "A�ustos","Eyl�l", "Ekim", "Kas�m", "Aral�k"};
	//char *aylar[] = {"","Ocak", "Subat", "Mart", "Nisan","May�s", "Haziran", "Temmuz", "A�ustos","Eyl�l", "Ekim", "Kas�m", "Aral�k"};
	int i;
	
	printf("Ay�n s�ras�n� gir "); scanf("%d", &i);
	
	printf("%s\n", (aylar[i]));
	
	getch();
	return 0;
}

