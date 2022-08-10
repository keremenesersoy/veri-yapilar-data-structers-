#include <iostream>
#include <cstdlib>

using namespace std;

struct kuyruk
{
	int veri;
	kuyruk* next;
};

kuyruk* KUYRUK = NULL;

void enque(int deger)
{
	if(KUYRUK == NULL)
	{
		KUYRUK = new kuyruk;
		KUYRUK->veri = deger;
		KUYRUK->next = NULL;
		return;
	}	
	kuyruk* temp = KUYRUK;
	
	while(temp->next != NULL)
	{
		temp = temp->next;
	}
	kuyruk* eklenecek = new kuyruk;
	eklenecek->veri = deger;
	eklenecek->next = NULL;	
	temp->next = eklenecek;
	
}

void deque()

{
	if(KUYRUK == NULL)
	{
		cout << "Liste Bos" << endl;
		return;
	}
	kuyruk* temp = KUYRUK;
	KUYRUK = KUYRUK->next;
	free(temp);
}

void yazdir(kuyruk* liste)
{
	while(liste->next != NULL)
	{
		cout << liste->veri << " ";
		liste = liste->next;
	}
	
	cout << liste->veri << endl;
}

int main()
{
	cout << "1-Ekle\n2-Sil\n3-Yazdir\n4-Cikis" << endl;
	int secim;
	while(true)
	{
		cout << "Secim Giriniz = ";	cin >> secim;
		
		switch(secim)
		{
			case 1:
			{
				cout << "Eklenecek Degeri Giriniz = ";
				int x; cin >> x;
				enque(x);
				break;
			}
			
			case 2:
			{		
				cout << KUYRUK->veri <<" Elemani Silindi!" << endl;
				deque();
				break;
			}
			case 3:
			{
				yazdir(KUYRUK);
				break;
			}
			case 4:
			{
				cout << "\nCikis Yapildi !!" << endl;
				return 0;
				break;
			}
			default:
				cout << "Yanlis Secim Yaptiniz" << endl;
		}
	}
	return 0;
}
