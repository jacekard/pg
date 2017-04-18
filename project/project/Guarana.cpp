#include "Guarana.h"
#include "Swiat.h"

Guarana::Guarana(Swiat& sw) : Roslina(0, 0, '+', 20, 0, "GUARANA", sw) {
	allocate();
};

Guarana::Guarana(Swiat& sw, int x, int y) : Roslina(0, 0, '+', 20, 0, "GUARANA", sw) {
	this->pos.x = x;
	this->pos.y = y;
	allocate();
}

void Guarana::kolizja(Organizm& other) {
	other.setSila(other.getSila() + 3);
	swiat.komentuj(" + " + other.getRodzaj() + " ma teraz +3 do sily! + ");
	Roslina::kolizja(other);
}

void Guarana::rozmnazanie() {
	Organizm *child = new Guarana(swiat, pos.x, pos.y);
	swiat.lista.push_back(child);
	swiat.sortujInicjatywa();
}

void Guarana::akcja() {
	grow();

	if (Util::los(1, 200) == 1) {
		if (rozsiewanie()) {
			rozmnazanie();
		}
	}
}

Guarana::~Guarana() {};



