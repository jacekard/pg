#include "Swiat.h"
#include <conio.h>
int main() {
	
	Swiat swiat;

	char zn = '1';
	do {
		
		swiat.wykonajTure();
		
		p::clrscr();
	} while (!swiat.czyKoniec);
	p::gameOver(swiat.turnCount, swiat.lista.size());
	Sleep(6000);
	return 0;
}