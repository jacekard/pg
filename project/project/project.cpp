#include "Swiat.h"

int main() {
	
	int WIDTH, HEIGHT;
	cout << "Podaj wymiary swiata: \n";
	cout << "szerokosc: ";
	cin >> WIDTH;
	cout << "wysokosc: ";
	cin >> HEIGHT;

	Swiat swiat(WIDTH,HEIGHT);
	//Swiat swiat(41, 21);

	char zn = '1';
	do {
		
		swiat.wykonajTure();

	} while (!swiat.getCzyKoniec());
	string ostatni_kom;
	if (swiat.komunikaty.size() == 0)
		ostatni_kom = "Koniec";
	else
		ostatni_kom = swiat.komunikaty.back();
	Util::gameOver(swiat.getTurnCount(), swiat.lista.size(), ostatni_kom);

	Sleep(5000);
	return 0;
}
