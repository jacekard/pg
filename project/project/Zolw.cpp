#include "Zolw.h"
#include "Swiat.h"

//sila(s), inicjatywa(i), symbol(sy), color(c), wiek(w), rodzaj(r), swiat(sw) {
Zolw::Zolw(Swiat& sw) : Zwierze(4, 4, 206, 5, 0, "ZOLW", sw) {
	if (swiat.world[pos.y][pos.x] == NULL)
		swiat.world[pos.y][pos.x] = this;
	else {
		reallocate();
	}

}
Zolw::Zolw(Swiat& sw, int x, int y) : Zwierze(4, 4, 206, 5, 0, "ZOLW", sw) {
	this->pos.x = x;
	this->pos.y = y;

	if (swiat.world[pos.y][pos.x] == NULL)
		swiat.world[pos.y][pos.x] = this;
	else {
		reallocate();
	}
}
void Zolw::kolizja(Organizm& other) {
	if (czyOdbilAtak(other))
		other.reallocate();
}

void Zolw::rozmnazanie() {
	Organizm *child = new Zolw(swiat, pos.x, pos.y);
	swiat.lista.push_back(child);
	swiat.sortujInicjatywa();
}

p Zolw::ruch() {
	p tmp;

	if (swiat.losuj(1, 4) == 1) {
		int s = swiat.losuj(0, 3);
		if (s == 0)
			tmp.y--;
		else if (s == 1)
			tmp.y++;
		else if (s == 2)
			tmp.x--;
		else if (s == 3)
			tmp.x++;
	}
	return tmp;
}