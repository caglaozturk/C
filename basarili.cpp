#include <stdio.h>
#include <conio.h>

int main()
{
		int ogrenci[5],sayac=0;
		for(int i=0;i<5;i++){
			printf("%d.kisinin notunu gir  :",i+1);
			scanf("%d",&ogrenci[i]);
			if(ogrenci[i]>=60)
				sayac++;
		}
		printf("Basarili ogrenci sayisi=====%d",sayac);
		getch();
		return 0;
}
