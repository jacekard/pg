#include "Wilk.h"
#include "Swiat.h"

//sila(s), inicjatywa(i), symbol(sy), color(c), wiek(w), rodzaj(r), swiat(sw) {
Wilk::Wilk(Swiat& sw) : Zwierze(9, 5, '%', 23, 0, "WILK", sw) {
	if (swiat.world[pos.y][pos.x] == NULL)
		swiat.world[pos.y][pos.x] = this;
	else {
		reallocate();
	}

}
Wilk::Wilk(Swiat& sw, int x, int y) : Zwierze(9, 5, '%', 24, 0, "WILK", sw) {
	this->pos.x = x;
	this->pos.y = y;

	if (swiat.world[pos.y][pos.x] == NULL)
		swiat.world[pos.y][pos.x] = this;
	else {
		reallocate();
	}
}
void Wilk::kolizja(Organizm& other) {
	if (czyOdbilAtak(other))
		other.reallocate();

}

void Wilk::rozmnazanie() {
	
		Organizm *child = new Wilk(swiat, pos.x, pos.y);
		swiat.lista.push_back(child);
		swiat.sortujInicjatywa();
	
}
