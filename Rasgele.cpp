#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int main(){
	int n,dizi[100];
	printf("Kac adet sayi girmek istersiniz :");
	scanf("%d",&n);
	int *ptr=(int *)malloc(n*sizeof(int));
	
	for(int i=0;i<n;i++){
		dizi[i]=rand()%100+1;
	}
	
	for(int i=0;i<n;i++){
		printf("\n%d.Sayi	:%d",i+1,dizi[i]);
	}
	
	getch();
	return 0;
}
