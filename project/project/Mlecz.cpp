#include "Mlecz.h"
#include "Swiat.h"

Mlecz::Mlecz(Swiat& sw) : Roslina(0, 0, '*', 14, 0, "MLECZ", sw) {};

Mlecz::Mlecz(Swiat& sw, int x, int y) : Roslina(0, 0, '*', 14, 0, "MLECZ", sw) {
	this->pos.x = x;
	this->pos.y = y;
}

void Mlecz::akcja() {
	for (int i = 0; i < 3; i++) {
		if (swiat.losuj(1, 200) == 1)
			rozmnazanie();
	}

	grow();
}

void Mlecz::rozmnazanie() {
	Organizm *child = new Mlecz(swiat, pos.x, pos.y);
	swiat.lista.push_back(child);
	swiat.sortujInicjatywa();
	child->reallocate();
}

void Mlecz::kolizja(Organizm& other) {

}

