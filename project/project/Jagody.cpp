#include "Jagody.h"
#include "Swiat.h"

Jagody::Jagody(Swiat& sw) : Roslina(99, 0, 'W', 13, 0, "JAGODY", sw) {
	if (swiat.world[pos.y][pos.x] == NULL)
		swiat.world[pos.y][pos.x] = this;
	else {
		reallocate();
	}
};

Jagody::Jagody(Swiat& sw, int x, int y) : Roslina(99, 0, 'W', 13, 0, "JAGODY", sw) {
	this->pos.x = x;
	this->pos.y = y;

	if (swiat.world[pos.y][pos.x] == NULL)
		swiat.world[pos.y][pos.x] = this;
	else {
		reallocate();
	}
}

void Jagody::rozmnazanie() {
	Organizm *child = new Jagody(swiat, pos.x, pos.y);
	swiat.lista.push_back(child);
	swiat.sortujInicjatywa();
}

void Jagody::kolizja(Organizm& other) {

}

void Jagody::akcja() {
	grow();

	if (swiat.losuj(1, 300) == swiat.losuj(1, 50)) {
		if (rozsiewanie()) {
			rozmnazanie();
		}
	}
}