#include "Swiat.h"
#include <conio.h>
int main() {
	
	Swiat swiat;

	char zn = '1';
	do {
		
		swiat.wykonajTure();
		
		p::clrscr();
	} while (!swiat.czyKoniec);
	p::gameOver();
	Sleep(2500);
	return 0;
}