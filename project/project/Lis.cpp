#include "Lis.h"
#include "Swiat.h"

//sila(s), inicjatywa(i), symbol(sy), color(c), wiek(w), rodzaj(r), swiat(sw) {
Lis::Lis(Swiat& sw) : Zwierze(3, 7, '#', 154, 0, "LIS", sw) {
	if (swiat.world[pos.y][pos.x] == NULL)
		swiat.world[pos.y][pos.x] = this;
	else {
		reallocate();
	}

}
Lis::Lis(Swiat& sw, int x, int y) : Zwierze(3, 7, '#', 154, 0, "LIS", sw) {
	this->pos.x = x;
	this->pos.y = y;

	if (swiat.world[pos.y][pos.x] == NULL)
		swiat.world[pos.y][pos.x] = this;
	else {
		reallocate();
	}
}
void Lis::kolizja(Organizm& other) {
	if (czyOdbilAtak(other))
		other.reallocate();

}

void Lis::rozmnazanie() {
	Organizm *child = new Lis(swiat, pos.x, pos.y);
	swiat.lista.push_back(child);
	swiat.sortujInicjatywa();

}
