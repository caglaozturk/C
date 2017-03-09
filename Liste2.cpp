#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct node{
		int data;
		struct node *next;
};
typedef struct node Node;
int main(){
	Node *p,*head;
	int count=1;
	head=(Node *)malloc(sizeof(Node));
	p=head;	
	printf("1.Sayi Gir :");
	scanf("%d",&head->data);
	
	while(p->data!=0){
		p->next=(Node *)malloc(sizeof(Node));
		p=p->next;
		count++;
		printf("%d.Sayi Gir :",count);
		scanf("%d",&p->data);
	}

	for(int i=0;i<count-1;i++){
		printf("%d.Sayi :%d\n",i+1,head->data);
		head=head->next;
	}
	getch();
	return 0;
}
