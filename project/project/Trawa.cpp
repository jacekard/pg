#include "Trawa.h"
#include "Swiat.h"

Trawa::Trawa(Swiat& sw) : Roslina(0, 0, 177, 2, 0, "TRAWA", sw) {};

Trawa::Trawa(Swiat& sw, p poz) : Roslina(0, 0, 177, 2, 0, "TRAWA", sw) {
	this->pos = poz;
}

void Trawa::rozmnazanie() {
		Organizm *child = new Trawa(swiat, this->pos);
		swiat.lista.push_back(child);
		swiat.sortujInicjatywa();
		child->reallocate();
}

void Trawa::kolizja(Organizm& other) {

}