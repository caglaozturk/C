#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include<locale.h>  
struct stud {
	int roll;
	char name[25];
	int age;
	struct stud *next;
};
typedef struct stud node;
node *CreateList(int);
float OrtGoster(node *);
int main()
{
	setlocale(LC_ALL, "Turkish");//T�rk�e karakter kullanabilmek i�in
	node *head; int n; char isim[25];
	printf("Ka� elemanli liste olacak..:"); scanf("%d",&n);
	head = CreateList(n);
	printf("Ya� ortalamas� = %.3f", OrtGoster(head));
	getch();
	return 0;
}
node *CreateList(int n){
	node *head,*p;int k=0;
	do{
		if(k==0){
			head = (node *)malloc (sizeof(node));
			p = head;
		}
		else{
			p->next = (node *)malloc (sizeof(node));
			p = p->next;
		}
		printf("\nD���m Bilgileri..: ");
		printf("\nRoll..: "); scanf("%d", &p->roll);
		printf("Ad..: "); scanf("%s", p->name);
		printf("Ya�..: "); scanf("%d", &p->age);
		k++;
	}while(k!=n);
	p->next = NULL;
	return head;
}
float OrtGoster(node *p){
	float sum=0.0;int s=0;
	while(p!=NULL){
		printf("%d. degerler: %d %s %d\n",++s,p->roll,p->name, p->age);
		sum += p->age;
		p=p->next;
	}
	return sum/s;
}

