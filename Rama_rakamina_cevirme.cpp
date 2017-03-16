#include <iostream>
#include <conio.h>
#include <string>
#include <locale.h>
using namespace std;

string intToRoma(int s)
{
	
	//Roma rakamýyla en fazla 3999 sayýsý yazýlabilir.
int bolum;
string sonuc;

bolum=s/1000;
s=s%1000;
switch(bolum)
{
	case 1 : sonuc+="M"; break;
	case 2 :  sonuc+="MM"; break;
	case 3 :  sonuc +="MMM"; break;
	default: break;
}

bolum=s/100;
s=s%100;
switch(bolum)
{
	case 1 : sonuc+="C"; break;
	case 2 : sonuc+="CC"; break;
	case 3 : sonuc+="CCC"; break;
	case 4 : sonuc+="CD"; break;
	case 5 : sonuc+="D"; break;
	case 6 : sonuc+="DC"; break;
	case 7 : sonuc+="DCC"; break;
	case 8 : sonuc+="DCCC"; break;
	case 9 :  sonuc+="CM"; break;
	default: break;
}


bolum=s/10;
s=s%10;
switch(bolum)
{
	case 1 : sonuc+="X"; break;
	case 2 : sonuc+="XX"; break;
	case 3 : sonuc+="XXX"; break;
	case 4 : sonuc+="XL"; break;
	case 5 : sonuc+="L"; break;
	case 6 : sonuc+="LX"; break;
	case 7 : sonuc+="LXX"; break;
	case 8 : sonuc+="LXXX"; break;
	case 9 :  sonuc+="XC"; break;
	default: break;
}


bolum=s/1;//Gerek olmasada Gösterme Amaçlý
s=s%1;
switch(bolum)
{
	case 1 : sonuc+="I"; break;
	case 2 : sonuc+="II"; break;
	case 3 : sonuc+="III"; break;
	case 4 : sonuc+="IV"; break;
	case 5 : sonuc+="V"; break;
	case 6 : sonuc+="VI"; break;
	case 7 : sonuc+="VII"; break;
	case 8 : sonuc+="VIII"; break;
	case 9 :  sonuc+="IX"; break;
	default: break;
}
return sonuc;
}

int main()
{
char s1[10],s2[10];
int i,sayi;
setlocale(LC_ALL,"TURKISH");
cin>>sayi;
cout <<intToRoma(sayi);
}

