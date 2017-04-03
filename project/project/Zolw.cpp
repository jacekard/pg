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
