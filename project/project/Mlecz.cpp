#include "Mlecz.h"
#include "Swiat.h"

Mlecz::Mlecz(Swiat& sw) : Roslina(0, 0, '*', 14, 0, "MLECZ", sw) {
	allocate();
};

Mlecz::Mlecz(Swiat& sw, int x, int y) : Roslina(0, 0, '*', 14, 0, "MLECZ", sw) {
	this->pos.x = x;
	this->pos.y = y;
	allocate();
}

void Mlecz::akcja() {
	grow();
	if (this->wiek == 150) {
		this->color = 6;
	}

	for (int i = 0; i < 3; i++) {
		if (Util::los(1, 150) == 1) {
			if (rozsiewanie()) 
				rozmnazanie();
		}
	}
}

void Mlecz::rozmnazanie() {
	Organizm *child = new Mlecz(swiat, pos.x, pos.y);
	swiat.lista.push_back(child);
	swiat.sortujInicjatywa();
}

