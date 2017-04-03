#include "Swiat.h"
#include <conio.h>
int main() {
	
	Swiat swiat;

	//co jest do zrobienia:
	//1. specyfika metody akcja() obiektu LIS
	//2. specyfika metody kolizja() obiektu ZOLW
	//3. specyfika metody kolizja() obiektu BARSZCZ

	char zn = '1';
	do {
		
		swiat.wykonajTure();

	} while (!swiat.czyKoniec);


	p::gameOver(swiat.turnCount, swiat.lista.size(), swiat.ostatni_komunikat);

	Sleep(5000);
	return 0;
}