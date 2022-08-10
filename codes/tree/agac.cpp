#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

struct agac{
	int veri;
	agac* sol;
	agac* sag;
};

agac* agac_ekle(agac* root , int deger)
{
	if(root == NULL)
	{
		agac* temp = (agac*)malloc(sizeof(agac));	
		temp->sag = NULL;
		temp->sol = NULL;
		temp->veri = deger;
		return temp;
	}
	
	if(root->veri < deger)
	{
		root->sag = agac_ekle(root->sag , deger);
		return root;
	}
	
	root->sol = agac_ekle(root->sol , deger);
	return root;
}

void agac_yazdir(agac* AGAC_)
{
//	L N R
	if(AGAC_ == NULL)
	{
		return; 

	}	 
	agac_yazdir(AGAC_->sol);
	cout << AGAC_->veri << " ";
	agac_yazdir(AGAC_->sag);	
}


int veri_ara(agac* AGAC_ , int aranan)
{
	
	if(AGAC_ == NULL)
	{
		return -1; 
	}
	if(AGAC_->veri == aranan)
	{
		return 1;
	}
	if(veri_ara(AGAC_->sag,aranan) == 1)
	{
		return 1;
	}
	if(veri_ara(AGAC_->sol,aranan) == 1)
	{
		return 1;
	}
	return -1;
}

int max(agac* AGAC)
{
	
	while(AGAC->sag != NULL)
	{
		AGAC = AGAC->sag;
	}
	
	return AGAC->veri;	
}

int min(agac* AGAC)
{
	
	while(AGAC->sol != NULL)
	{
		AGAC = AGAC->sol;
	}
	
	return AGAC->veri;	
}

agac* sil(agac* AGAC , int deger)
{
	if(AGAC == NULL)
			return NULL;
	if(AGAC->veri == deger)
	{
		if(AGAC->sol == NULL && AGAC->sag == NULL)
			return NULL;
		
		if(AGAC->sag != NULL)
		{
			AGAC->veri = min(AGAC->sag);
			AGAC->sag = sil(AGAC->sag,min(AGAC->sag));
			return AGAC;
		}
		AGAC->veri = max(AGAC->sol);
		AGAC->sol = sil(AGAC->sol,max(AGAC->sol));
		return AGAC;	
	}
	
	if(AGAC->veri < deger)
	{
		AGAC->sag = sil(AGAC->sag,deger);
		return AGAC;
	}
	AGAC->sol = sil(AGAC->sol,deger);
	return AGAC;
}

int main(){
	agac* AGAC = NULL;
	
	AGAC = agac_ekle(AGAC , 12);
	AGAC = agac_ekle(AGAC , 200);
	AGAC = agac_ekle(AGAC , 190);
	AGAC = agac_ekle(AGAC , 213);
	AGAC = agac_ekle(AGAC , 56);
	AGAC = agac_ekle(AGAC , 24);
	AGAC = agac_ekle(AGAC , 18);
	AGAC = agac_ekle(AGAC , 27);
	AGAC = agac_ekle(AGAC , 28);
	

	agac_yazdir(AGAC);
	
	cout << endl;
	
	veri_ara(AGAC,200);
	
	cout << "\nMAX = " << max(AGAC);
	cout << "\nMIN = " << min(AGAC);
	
	cout << "\nLNR = "; agac_yazdir(AGAC);
	
	return 0;
}
