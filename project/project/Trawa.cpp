#include "Trawa.h"
#include "Swiat.h"

Trawa::Trawa(Swiat& sw) : Roslina(0, 0, 177, 2, 0, "TRAWA", sw) {};

Trawa::Trawa(Swiat& sw, int x, int y) : Roslina(0, 0, 177, 2, 0, "TRAWA", sw) {
	this->pos.x = x;
	this->pos.y = y;
}

void Trawa::rozmnazanie() {
		Organizm *child = new Trawa(swiat, pos.x, pos.y);
		swiat.lista.push_back(child);
		swiat.sortujInicjatywa();
		child->reallocate();
}

void Trawa::kolizja(Organizm& other) {

}