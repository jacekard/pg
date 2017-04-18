#include "Jagody.h"
#include "Swiat.h"

Jagody::Jagody(Swiat& sw) : Roslina(99, 0, 'W', 13, 0, "JAGODY", sw) {
	allocate();
};

Jagody::Jagody(Swiat& sw, int x, int y) : Roslina(99, 0, 'W', 13, 0, "JAGODY", sw) {
	this->pos.x = x;
	this->pos.y = y;
	allocate();
}

void Jagody::rozmnazanie() {
	Organizm *child = new Jagody(swiat, pos.x, pos.y);
	swiat.lista.push_back(child);
	swiat.sortujInicjatywa();
}

void Jagody::kolizja(Organizm& other) {
	swiat.komentuj(" + " + other.getRodzaj() + " ginie otruty przez " + rodzaj + "! + ");
	other.die();
	this->die();
}

void Jagody::akcja() {
	grow();

	if (Util::los(1, 300) == Util::los(1, 50)) {
		if (rozsiewanie()) {
			rozmnazanie();
		}
	}
}