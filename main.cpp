#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <iostream>

using namespace std;
float factoriel(int number){
      if(number==0 || number ==1)
        return 1;
      else
         return number*factoriel(number-1);
}
int main(int argc, char *argv[])
{
    
    float x;
    float ref_error;
    float analitic_value;
    printf("x'in sayisal degerini giriniz\n");
    scanf("%f",&x);// x float f kulland�k
    //x double olsayd� long float = lf kullanacakt�k
    printf("Referans bagil hata de�erini giriniz\n");    
    scanf("%f",&ref_error);
    
    // analitic de�eri hesaplayal�m
    analitic_value = exp(x); //e ustu x de�erini exp hesaplar
    
    int i=0;
    float error= 1000000.0;
    // �ok b�y�k bir de�er veriyoruz ki while her durumda girsin
    // do while kullsnsak sorunu cozeriz asl�nda
    float result=0;
    while(error >= ref_error ){
         result+=pow(x,i)/factoriel(i);
         error= fabs(analitic_value-result)/fabs(analitic_value) ;
         // abs mutlak de�er fabs float i�in mutlak de�er.yani |x|.
         i++;
         printf("%d. iterasyonda sonuc=%0.8f\t Bagil hata=%f\n",i,result,error); 
            
    }
    
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
