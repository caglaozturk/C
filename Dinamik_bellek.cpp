#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
int main(){
	int *pa=(int *)malloc(sizeof(int));
	printf("%p\n",pa);
	int count=1,a=4;
	int i=0;
	printf("\n1.Sayiyi Giriniz   :");scanf("%d",pa);
	
	while((*(pa+i))!=0){
		i++;
		pa=(int *)realloc(pa,sizeof(int));
		printf("%p\n",pa);
		count++;
		printf("%d.Sayiyi Giriniz   :",count);scanf("%d",(pa+i));	
	}
	
	for(int i=0;i<count-1;i++)
		printf("\n%d.Sayiniz   :%d",i+1,*(pa+i));
	free(pa);
	getch();
	return 0;
}
