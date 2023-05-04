#include <stdio.h>
#include <stdlib.h>
#include <string.h>

    struct bilgi
{	
	char isim[5];
	char soyisim[6];
	int okulno;
	
};

    int enbuyukasalbul(int * sayi , int * degerler)
{
		*sayi=212804007;
		int asalcarpan[3];
    	int i,b,a=0;
    	int max;
    		
    	for(i=2 ; *sayi>1 ; i++)
    	{	
    	  while(*sayi%i==0)
		  {
		  	asalcarpan[a]=i;
		  	a++;
			*sayi= *sayi/i;						
		  }		  
        } 
						 	 
        max=asalcarpan[0];
        for(b=1;b<3;b++)
		{	
        	if(max<asalcarpan[b])
			{
        	max=asalcarpan[b];
            }
		}
    	    
    	return max;          
}	
   
    void sezarsifrele(char isim[],int boyut)
{
	char sifrelenmishali[10];
	int anahtar=0,i=0;
	printf("sifrelenecek anahtar sayisi giriniz(okul numaranizin son hanesi):\n");
	scanf("%d",&anahtar);
	char a;	
	
	while(i<9)
	{
		a=isim[i];
		sifrelenmishali[i]=(char)(int)a+anahtar;
		i++;	
	
	}
	   	 printf("sifrelenmis isim ve soyisim:%s\n",sifrelenmishali);
		
}

    void sezarsifreac(char isim[],int boyut)
{
	char sifredenkurtul[10];
	int anahtar=0,i=0;
	int b;
	char a;
	printf("sezar sifresini cozmek icin once okul numaranizin son hanesini giriniz:\n");
	scanf("%d",&anahtar);
	printf("sezar sifresini cozmek icin okul numaranizin en buyuk asal bolenini dogru bir sekilde girin:\n");
	scanf("%d",&b);
	 
    if(b==5456513)
	  {
	while(i<9)
	 { 
		a=isim[i];
		sifredenkurtul[i]=(char)(int)a-anahtar;
		i++;
	 } 
    	printf("sifreden kurtulmus isim ve soyisim:%s\n",sifredenkurtul);
       }
  
    else
  {
    	printf("hatali bir sayi girdiniz...\n");
  }             
}
   
int main()
{    
	
	struct bilgi ogrenci;
	strcpy(ogrenci.isim,"Azim");
	strcpy(ogrenci.soyisim,"Ozkan");
	strcat(ogrenci.isim,ogrenci.soyisim);
	ogrenci.okulno=212804007;
	int a;
    printf("Sezar sifreleme metoduna hos geldiniz...\n");
	
	   /*    Adiniz ve soyadiniz sifrelenecektir.
    Sezar sifrelemede okul numaranizin son hanesi kadar saga kaydirilacaktir.
    NOT: (eger 0 varsa 0 dan onceki sayi kadar kayrdilacaktir.  
    NOT:Sezar sifresini cozebilmek icin de okul numaranýzýn en buyuk asal sayisini dogru girmeniz gerekmekte.   */
    
    printf("adiniz ve soyadiniz:%s\n",ogrenci.isim);
	printf("okul numaraniz:%d\n",ogrenci.okulno);
   
   int y,z,enbykasalsayi;
   enbykasalsayi=enbuyukasalbul(&y,&z);
   printf("okul numaranizin en buyuk asal sayisi:%d\n",enbykasalsayi);// ayni zamanda sezar sifreli metni cözmek icin gerek sifre.
   sezarsifrele(ogrenci.isim,10);
   char sifrelihali[10]="HüptVürhu";
   sezarsifreac(sifrelihali,10);
   printf("sezar sifreli ve sifreden arindirilmis halini txt dosyasina yazdirmak\n");
   printf("icin tekrardan okul hanenizin en buyuk asal carpanini giriniz:\n");
   scanf("%d",&a);
   
   FILE * dosya;
   dosya=fopen("sifrelimetin.txt","w");
    if(dosya==NULL)
	{
		printf("dosya acilamadi...");
	}
    else 
    {
        if(a==5456513)
		{
			fprintf(dosya,"sezar sifreli hali:HüptVürhu\n");
			fprintf(dosya,"sezaf sifreden arindirilmis hali:AzimOzkan");
			printf("dosyaya yazdirma islemi basarili...");
		}
    	else
    	{
    		printf("hatali sayi girdiginiz icin dosyaya yazdirma isleminiz basarisiz....");
		}
	}
	   fclose(dosya);
	   
 return 0;
}
 
