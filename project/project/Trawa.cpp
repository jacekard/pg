#include "Trawa.h"
#include "Swiat.h"

Trawa::Trawa(Swiat& sw) : Roslina(0, 0, 176, 10, 0, "TRAWA", sw) {
	allocate();
	maxZakresLosowania = 60;
};

Trawa::Trawa(Swiat& sw, int x, int y) : Roslina(0, 0, 176, 10, 0, "TRAWA", sw) {
	maxZakresLosowania = 60;
	this->pos.x = x;
	this->pos.y = y;
	allocate();
}

void Trawa::rozmnazanie() {
	Organizm *child = new Trawa(swiat, pos.x, pos.y);
	swiat.lista.push_back(child);
	swiat.sortujInicjatywa();
}

void Trawa::akcja() {
	Roslina::akcja();
	if (this->wiek == 100) {
		this->color = 2;
		this->symbol = 177;
	}
	if (this->wiek == 200) {
		this->color = 6;
		this->symbol = 178;
	}
}