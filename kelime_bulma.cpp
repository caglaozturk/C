#include <stdio.h>
#include <conio.h>

int main()
{
		char dizi[20];
		int i,sayac=0;
		printf("isim giriniz   ::::");
		scanf("%s",dizi);
		for(i=0;dizi[i]!='\0';i++){
			if(dizi[i]=='y' && dizi[i+1]=='a')
				sayac++;
		}
		printf("%d adet ya var.....",sayac);
		getch();
		return 0;
}
