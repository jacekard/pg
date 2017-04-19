#include "Roslina.h"
#include "Swiat.h"

Roslina::Roslina(int s, int i, char sy, int c, int w, string r, Swiat& sw)
: Organizm(s, i, sy, c, w, r, sw) {
}

void Roslina::kolizja(Organizm& other) {
	swiat.komentuj(" + " + other.getRodzaj() + " zjada " + this->rodzaj + "! + ");
	swiat.world[pos.y][pos.x] = &other;
	swiat.world[other.getOldPosy()][other.getOldPosx()] = NULL;
	this->die();
}

void Roslina::akcja() {
	if (czyRosnie) {
		grow();
		if (Util::los(1, maxZakresLosowania) == 1)
		if (rozsiewanie()) {
			rozmnazanie();
		}
	}
}

bool Roslina::rozsiewanie() {
	if (wiek >= 100) czyRosnie = false;
	point tmp = ruch();
	if ((pos.x + tmp.x < swiat.WIDTH - 1 && pos.y + tmp.y > 1) &&
		(pos.y + tmp.y < swiat.HEIGHT - 1 && pos.y + tmp.y > 1)) {
		if (swiat.world[pos.y + tmp.y][pos.x + tmp.x] == NULL) {
			return true;
		}
	}
	return false;
}

Roslina::~Roslina() {

}