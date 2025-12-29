#include <stdio.h>

#define URUN_SAYISI 5
#define MAX_AD 30

void menu_goster(char urun_adi[URUN_SAYISI][MAX_AD],float urun_fiyat[URUN_SAYISI]){

	printf("\n--MENU--\n");

	for(int i=0 ; i<URUN_SAYISI ; i++){
		printf("%d - %s - %.2f\n", i+1 , urun_adi[i] , urun_fiyat[i] );
	}
	printf("\n");
}

void sepete_ekle(char urun_adi[URUN_SAYISI][MAX_AD],float urun_fiyat[URUN_SAYISI],int sepet_adet[]){

	int secim,adet;

	menu_goster(urun_adi,urun_fiyat);

	printf("Urun secin:");
	scanf("%d",&secim);

	if(secim<=URUN_SAYISI && secim>0)
	{
		printf("Kac adet:");
		scanf("%d",&adet);

		if (adet <= 0)
		{	
    		printf("Adet 1 veya daha buyuk olmali.\n");
    		return;
		}

		sepet_adet[secim-1] += adet;

		printf("%d numarali urunden %d adet eklendi.\n", secim, adet);
	}
	else
		printf("Gecersiz sayi");
	
	printf("\n");	
}

float sepet_toplam(char urun_adi[URUN_SAYISI][MAX_AD],float urun_fiyat[],int sepet_adet[]){

	float toplam=0;

	for(int i=0 ; i<URUN_SAYISI ; i++)
	{
		if (sepet_adet[i]>0)
		{
			float tutar = sepet_adet[i] * urun_fiyat[i];
			printf("%s * %d = %.2f\n", urun_adi[i], sepet_adet[i], tutar);
			toplam += tutar;
		}
	}

	return toplam;

}

void sepeti_goster(char urun_adi[URUN_SAYISI][MAX_AD],float urun_fiyat[],int sepet_adet[]){

	printf("\n--SEPET--\n");

	float toplam = sepet_toplam(urun_adi,urun_fiyat,sepet_adet);

	if(toplam == 0)
		printf("\nSepet bos. \n\n");

	else
		printf("\nToplam tutar:%.2f\n\n",toplam);
}

void sepet_odeme(char urun_adi[URUN_SAYISI][MAX_AD],float urun_fiyat[],int sepet_adet[]){

	float ver_tutar,geriver_tutar;

	printf("\n--ODEME--\n\n");

	float toplam = sepet_toplam(urun_adi,urun_fiyat,sepet_adet);

	if(toplam==0)
	{
		printf("Sepet bos.\n\n");
		return;
	}

	printf("\nToplam tutar:%.2f\n\n",toplam);

	printf("\nVerilen tutar:");
	scanf("%f",&ver_tutar);
	printf("\n");

	if (ver_tutar < 0)
    {
   		 printf("Verilen tutar negatif olamaz.\n\n");
   		 return;
	}

	if(ver_tutar >= toplam )
	{
		geriver_tutar = ver_tutar - toplam;
		printf("\n%.2f TL para ustu verilmeli.\n",geriver_tutar);
		for(int i = 0 ; i < URUN_SAYISI ; i++)
		{
			sepet_adet[i]=0;
		}
		printf("\nOdeme basarili.\nSepet sifirlandi.\n\n");

	}
	else
		printf("Odeme yetersiz\n\n");
}

void sepeti_bosalt(int sepet_adet[])
{
    for (int i = 0; i < URUN_SAYISI; i++)
        sepet_adet[i] = 0;

    printf("\nSepet bosaltildi.\n\n");
}

int main(){
 
	int secim;
	char urun_adi[URUN_SAYISI][MAX_AD]={"pizza","hamburger","ayran","tatli","su"};
	float urun_fiyat[URUN_SAYISI]={70,80,15,45,5};
	int sepet_adet[URUN_SAYISI] = {0};

	while(1){
		printf("--------------\n");
		printf("---Ana Menu---\n");
		printf("--------------\n");
        printf("1.menu goster\n");
		printf("2.sepete ekle\n");
		printf("3.sepeti goster\n");
		printf("4.sepeti bosalt\n");
		printf("5.sepet odeme\n");
		printf("0.cikis\n\n");
		printf("Secim:");

		scanf("%d",&secim);

		switch(secim){
			case 1:
				menu_goster(urun_adi,urun_fiyat);
				break;
			case 2:
				sepete_ekle(urun_adi,urun_fiyat,sepet_adet);
				break;
			case 3:
				sepeti_goster(urun_adi,urun_fiyat,sepet_adet);
				break;
			case 4:
				sepeti_bosalt(sepet_adet);
				break;
			case 5:
				sepet_odeme(urun_adi,urun_fiyat,sepet_adet);
				break;
			case 0:
				return 0;
			default:
				printf("Gecersiz secim.");
		}

	}
	return 0;
}
