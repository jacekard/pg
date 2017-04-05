#include "Swiat.h"
#include <conio.h>
int main() {
	
	Swiat swiat;

	//co jest do zrobienia:
	//1. specyfika metody akcja() obiektu LIS
	//2. specyfika metody kolizja() obiektu ZOLW
	//3. specyfika metody kolizja() obiektu BARSZCZ
	//4. przepisz cala funkcje kolizja
	//5. ponazywaj inaczej klase p (np. na point) wywal te funkcje rysujace z niej do nowej klasy Util
	char zn = '1';
	do {
		
		swiat.wykonajTure();

	} while (!swiat.czyKoniec);


	p::gameOver(swiat.turnCount, swiat.lista.size(), swiat.ostatni_komunikat);

	Sleep(5000);
	return 0;
}