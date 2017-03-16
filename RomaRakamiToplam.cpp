#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

int ktos(char s1)
{
int sayi;

switch (s1)
{
case 'M': sayi = 1000; break;
case 'm': sayi = 1000; break;
case 'D': sayi = 500; break;
case 'd': sayi = 500; break;
case 'C': sayi = 100; break;
case 'c': sayi = 100; break;
case 'L': sayi = 50; break;
case 'l': sayi = 50; break;
case 'X': sayi = 10; break;
case 'x': sayi = 10; break;
case 'V': sayi = 5; break;
case 'v': sayi = 5; break;
case 'I': sayi = 1; break;
case 'i': sayi = 1; break;
default: sayi = 0; break;
}
return sayi;
}

int romaToInt(char *s)
{
int toplamdeger=0,ssayi=0,ondeger=0;
int i;
toplamdeger=ktos(s[0]);
ondeger=toplamdeger;
for(i=1;i<20;i++)
{
	ssayi=ktos(s[i]);
	if(ssayi==0)
	return toplamdeger;

	if(ondeger>=ssayi)
	toplamdeger+=ssayi;
	else
	toplamdeger+=ssayi-(2*ondeger);
	ondeger=ssayi;
}
}
int main()
{
char s1[20],s2[20];
int i,sonuc;
cout<<"1.roma rakamini gir"<<endl;
gets(s1);
cout<<"2.roma rakamini gir"<<endl;
gets(s2);
sonuc = romaToInt(s1)+romaToInt(s2);
cout<<sonuc<<endl;
}

