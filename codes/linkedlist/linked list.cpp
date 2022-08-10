#include <iostream>
#include <cstring>
#include <cctype>
#include <string>
#include <cstdlib>
#include <cmath>

using namespace std;

 struct enes {
    int x;
    enes* next;         // kendini �a��ran yap� 
};

void yazdir(enes* str) {

     while (str->next != NULL )  
     {
         cout << str->x << " ";
         str = str->next;
     }

     if (str->next == NULL) {
     	
         cout << str->x << " ";
     }

 }

int liste_uzunluk(enes* str){
	
	int sayac = 1;
	
	while(str->next != NULL)
	{
		str = str->next;
		sayac++;
	}

	return sayac;
} 

enes* basa_ekle(enes* str, int sayi) {

     enes* temp = (enes*)malloc(sizeof(enes));

     temp->x = sayi;

     temp->next = str;

     str = temp;

     return str;
 }

void ekle(enes* str, int boyut) {
   
     enes* temp = str;

     if (str == NULL) {

         str = (enes*)malloc(sizeof(enes));

         str->x = boyut;

         str->next = NULL;

     }

     else {

         while (temp->next != NULL) {

             temp = temp->next;

         }
         temp->next = (enes*)malloc(sizeof(enes));
         temp->next->x = boyut;
         temp->next->next = NULL;
        
     }
     
 }
 
void araya_ekle(enes*str , int veri , int sira){
	
	if(sira == 1 || sira == 0)
	{
		basa_ekle(str , veri);
	}
	else
	{
		for(int i = 0 ; i < sira - 2 ; i++)
		{
			str = str->next;
		}
		enes *temp = (enes*)malloc(sizeof(enes));
		temp->x = veri;
		temp->next = str->next;
		str->next = temp;
		
		
	}
	
}

enes* sondan_sil(enes* str) {
	

    enes* iter = str;

    enes* temp;

    while (iter->next->next != NULL) {

        iter = iter->next;


    }

    temp = iter->next;

    iter->next = NULL;

    free(temp);


    return str;


}

enes* eleman_sil(enes* str, int sayi) {

     enes* temp;                   // temp olsuturduk

     enes* iter = str;              // listede gezmesi i�in iter olusturduk

     if (str->x == sayi) {   // silecegimiz eleman listenin ba��ndaysa

         temp = str;

         str = str->next;

         free(temp);

         return str;

     }


     while(iter->next != NULL && iter->next->x != sayi){   // silecegimiz eleman listenin sonunda yada aras�ndaysa silinecek elemandan �nceki listeyi bulmaya �al�s�yoruz
     
     
         iter = iter->next;
     
     }

     if (iter->next == NULL) {          // eger silinicek eleman bulunmad�ysa iter en son elemana gelir ve durur

         cout << "\nsayi bulunamadi" << endl;

         return str;

     }

     temp = iter->next;                  //   silincek elemandan �nceki elemana geldigimizde tempimizi silincek elemana at�yoruz

     iter->next = iter->next->next;   // silincek olan elemandan �nceki listeyi silinecek olan eleman�n listesinden sonraki listeye bal�yoruz
                                        // b�ylelikle aradaki ba�lant�y� k�rmam�s oluyoruz
         free(temp);  // arada kalan kullan�lmayan ��p eleman� temizliyoruz

         return str;

 }

void eleman_bul(enes* str , int veri){
	
	while(str->x != veri && str->next != NULL)
	{
		str = str->next;
	}
	
	if(str->x == veri)
	{
		cout << "\nListenizde " << str->x << " elemani bulunmaktadir !!" << endl;	
	}
	else
	{
		cout << "\nAradiginiz eleman bulunamadi !!" << endl;
	}
	
	
}

void liste_birlestir(enes* dizi_1 , enes* dizi_2){
		
	enes* temp = dizi_1;
	
	while(temp->next != NULL)
	{
		temp = temp->next;
	}
	
	temp->next = dizi_2;	
}

int main()
{
    cout << "----------------------------------------------------\n\n";

    enes* dugum;

    dugum = (enes*)malloc(sizeof(enes));  // haf�zada yer ay�rma

    dugum->x = 5;             // ilk kutunun i�indeki int degerine 5 atand�

    cout << "ilk listedeki x degeri = " << dugum->x << endl;

    dugum->next = (enes*)malloc(sizeof(enes));      // next ile ikinci kutunun yeri ayr�ld�

    dugum->next->x = 10;            // ikinci kutunun int degerine 10 atand�

    dugum->next->next = NULL;        //  ikinci kutunun next degerine NULL eklendi

    cout << "ikinci listedeki x degeri = " << dugum->next->x << endl;

    enes* iter = dugum;                

    cout << "iter ile x degiskeni yazdirma = " << iter->x << endl;

    iter = iter->next;           // iteri ikinci listeye atad�k

    cout << "yeni iter ile x degiskeni yazdirma = " << iter->x << endl;

    cout << "\n\n------------------------------------------------------------------\n\n";

    iter = dugum;     // iter ilk kutucuga atand�

    // DONG�LER �LE YAZDIRMA  VE FONKS�YONLAR

    while (iter->next != NULL) {

        cout << iter->x << " ";       // iterin x degeri yaz�ld�

        iter = iter->next;      // iter bi sonraki kutucuga atand�
        

        //sayac += 1;

    }
	cout << "\n";
    for (int i = 0; i < 2; i++) {

        iter->next = (enes*)malloc(sizeof(enes));        // yeni kutu i�in yer ay�rt�ld� 

        iter = iter->next;         // iter bir sonraki kutuya atand� 

        iter->x = i * 10;         

        iter->next = NULL;        // yeni kutunun sonuna NULL  eklendi

    }

    yazdir(dugum);
  
    ekle(dugum, 7);   // SONUNA ELEMAN EKLEME

    cout << "\nyazdir fonksiyonu = ";
    yazdir(dugum);

    cout << "\n\n----------------------------------------------------\n";

    // ARAYA  ELEMAN EKLEME

    enes* yeni_iter = dugum;

    for(int i = 0 ; i<2 ; i++){
    
        yeni_iter = yeni_iter->next;   // ilk listeye e�it olan iteri d�ng� ile 3.listeye atad�k
    
    }


    enes* yeni_dugum = (enes*)malloc(sizeof(enes));     // araya eklemek istedi�imiz d�g�m i�in haf�zada yer ay�rtt�k

    yeni_dugum->next = yeni_iter->next;

    yeni_iter->next = yeni_dugum;

    yeni_dugum->x = 25;

    yazdir(dugum);

    cout << "\n silinmis fonksiyon = ";

    dugum = eleman_sil(dugum, 0);

    yazdir(dugum);

    cout << "\n basa eleman ekle = ";

    dugum =  basa_ekle(dugum, 20);

    yazdir(dugum);       

    cout << "\n sondan eleman sil = ";

    dugum = sondan_sil(dugum);

    yazdir(dugum);

    cout << "\n\n----------------------------------------------------\n";

    dugum = eleman_sil(dugum, 200);
  
    yazdir(dugum);

    cout << "\n";

    ekle(dugum, 270);
    
    yazdir(dugum);

    ekle(dugum, 290);

    cout << endl;

    dugum = eleman_sil(dugum, 270);

    yazdir(dugum);
    
    araya_ekle(dugum , 31 , 3);
    
    cout << endl;
    
    yazdir(dugum);
    
    cout << "\nlistenin uzunlugu = " << liste_uzunluk(dugum) << endl;
    
    enes* dugum_2 = (enes*)malloc(sizeof(enes));
    
    dugum_2->x = 142;
    dugum_2->next = NULL;
    
    for(int i = 0 ; i < 3 ; i++)
	{
		ekle(dugum_2 , pow(i+1,3));
	}
    
	cout << "dugum = ";		    yazdir(dugum);
	cout << "\ndugum_2 = ";		yazdir(dugum_2);
	
	liste_birlestir(dugum,dugum_2);
	
	cout << "\nbirlestirilmis dugum = ";	yazdir(dugum);
	
    cout << "\n\n----------------------------------------------------\n";

	return 0;
}
