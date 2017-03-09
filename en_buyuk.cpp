#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
int main()
{
	int *ptr,i,max=-1000;
	ptr=(int*)malloc(sizeof(int));
	for(i=0;i<5;i++){
        printf("%d.sayiyi gir",i+1);
        scanf("%d",ptr+i);

        if(*(ptr+i)>max)
            max=*(ptr+i);
	}
        printf("Max Sayi-> %d",max);
	getch();
	return 0;
}
