#include "Swiat.h"

int main() {
	
	Swiat swiat;

	//ZROBIC FABRYKE ZWIERZAT!

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
