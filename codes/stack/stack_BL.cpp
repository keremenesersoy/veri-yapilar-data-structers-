#include <iostream>
#include <cstdlib>

using namespace std;

struct enes{
	int data;
	enes* next;
};


enes* liste = NULL;

void push(int veri)
{	
	
	if(liste == NULL)
	{
		liste = (enes*)malloc(sizeof(enes));
		liste->data = veri;
		liste->next = NULL;
		return;
	}
	
	enes* temp = (enes*)malloc(sizeof(enes));
	temp->data = veri;
	temp->next = liste;
	liste = temp;
	
}

enes* pop()
{
	if(liste == NULL)
	{
		return liste;		
	}
	enes* temp = liste;
	liste = liste->next;
	free(temp);
}

void yazdir(enes* liste)
{
	if(liste == NULL)
	{
		return;
	}
	enes* temp = liste;
	
	while(temp->next != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << temp->data << endl;
}

int main(){
	
	push(10);
	push(20);
	push(30);
	push(35);
	push(34);
	push(33);
	push(32);
	push(31);

	yazdir(liste);
	
	pop();
	pop();
	pop();
	
	yazdir(liste);
	
	
	return 0;
}
