#include "Header.h"
#define ILOSC 15
int main() {
	
	Swiat swiat;

	Organizm **organizmy = new Organizm*[ILOSC];
	for (int i = 0; i < ILOSC; i++){
		organizmy[i] = new Wilk;
	}
	//Zwierze *human = new Czlowiek;
	char zn = '1';
	Czlowiek *human = new Czlowiek;
	do {
		swiat.rysujSwiat();
		
		for (int i = 0; i < ILOSC; i++){
			organizmy[i]->rysowanie();
			organizmy[i]->akcja();
		}
		human->rysowanie();
		
		
		swiat.rysujMenu();
		human->akcja();
		
		//Sleep(500);
		system("cls");
	} while (zn != 'q');
	
	
	swiat.~Swiat();
	system("pause");
}



//cin >> zn;
//if (zn == 't') {
//	//swiat.wykonajTure();

//}