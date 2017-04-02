#include "Swiat.h"
#include <conio.h>
int main() {
	
	Swiat swiat;

	char zn = '1';
	do {
		
		swiat.wykonajTure();

	} while (!swiat.czyKoniec);


	p::gameOver(swiat.turnCount, swiat.lista.size(), swiat.ostatni_komunikat);
	p::setColor(14);
	cout << swiat.ostatni_komunikat;
	Sleep(5000);
	return 0;
}