#include "Roslina.h"
#include "Swiat.h"

Roslina::Roslina(int s, int i, char sy, int c, int w, string r, Swiat& sw)
: Organizm(s, i, sy, c, w, r, sw) {
}

void Roslina::akcja() {
	if (swiat.losuj(1, 150) == 1)
		rozmnazanie();


	grow();
}


Roslina::~Roslina() {

}