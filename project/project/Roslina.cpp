#include "Roslina.h"
#include "Swiat.h"

Roslina::Roslina(int s, int i, char sy, int c, int w, string r, Swiat& sw)
: Organizm(s, i, sy, c, w, r, sw) {
}

void Roslina::kolizja(Organizm& other) {
	swiat.komentuj(" + " + other.getRodzaj() + " zjada " + this->rodzaj + "! + ");
	this->die();
}

bool Roslina::rozsiewanie() {
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