#include "Guarana.h"
#include "Swiat.h"

Guarana::Guarana(Swiat& sw) : Roslina(0, 0, '+', 20, 0, "GUARANA", sw) {
	if (swiat.world[pos.y][pos.x] == NULL)
		swiat.world[pos.y][pos.x] = this;
	else {
		reallocate();
	}
};

Guarana::Guarana(Swiat& sw, int x, int y) : Roslina(0, 0, '+', 20, 0, "GUARANA", sw) {
	this->pos.x = x;
	this->pos.y = y;

	if (swiat.world[pos.y][pos.x] == NULL)
		swiat.world[pos.y][pos.x] = this;
	else {
		reallocate();
	}
}

void Guarana::rozmnazanie() {
	Organizm *child = new Guarana(swiat, pos.x, pos.y);
	swiat.lista.push_back(child);
	swiat.sortujInicjatywa();
}

void Guarana::akcja() {
	grow();

	if (swiat.losuj(1, 150) == 1) {
		if (rozsiewanie()) {
			rozmnazanie();
		}
	}
}

Guarana::~Guarana() {};