#include <stdio.h>
#include<conio.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL,"TURKISH");
	char aylar[][10] = {"","Ocak", "Subat", "Mart", "Nisan","Mayýs", "Haziran", "Temmuz", "Aðustos","Eylül", "Ekim", "Kasým", "Aralýk"};
	//char *aylar[] = {"","Ocak", "Subat", "Mart", "Nisan","Mayýs", "Haziran", "Temmuz", "Aðustos","Eylül", "Ekim", "Kasým", "Aralýk"};
	int i;
	
	printf("Ayýn sýrasýný gir "); scanf("%d", &i);
	
	printf("%s\n", (aylar[i]));
	
	getch();
	return 0;
}

