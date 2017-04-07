#include "Swiat.h"

int main() {
	
	Swiat swiat;

	//co jest do zrobienia:
	//1. specyfika metody akcja() obiektu LIS
	//3. specyfika metody kolizja() obiektu BARSZCZ

	char zn = '1';
	do {
		
		swiat.wykonajTure();

	} while (!swiat.czyKoniec);
	string ostatni_kom;
	if (swiat.komunikaty.size() == 0)
		ostatni_kom = "Koniec";
	else
		ostatni_kom = swiat.komunikaty.back();
	Util::gameOver(swiat.turnCount, swiat.lista.size(), ostatni_kom);

	Sleep(5000);
	return 0;
}

//void operator=(p& other) {
//	this->pos.x += other.x;
//	this->pos.y += other.y;
//}