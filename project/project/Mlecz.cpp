#include "Mlecz.h"
#include "Swiat.h"

Mlecz::Mlecz(Swiat& sw) : Roslina(0, 0, '*', 14, 0, "MLECZ", sw) {
	maxZakresLosowania = 120;
	allocate();
};

Mlecz::Mlecz(Swiat& sw, int x, int y) : Roslina(0, 0, '*', 14, 0, "MLECZ", sw) {
	maxZakresLosowania = 120;
	this->pos.x = x;
	this->pos.y = y;
	allocate();
}

void Mlecz::akcja() {
	Roslina::akcja();
	if (this->wiek == 150) {
		this->color = 6;
	}
	if (this->wiek == 120) {
		this->color = 5;
	}
}

void Mlecz::rozmnazanie() {
	Organizm *child = new Mlecz(swiat, pos.x, pos.y);
	swiat.lista.push_back(child);
	swiat.sortujInicjatywa();
}

