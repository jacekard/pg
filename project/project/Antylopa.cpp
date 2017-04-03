#include "Antylopa.h"
#include "Swiat.h"

//sila(s), inicjatywa(i), symbol(sy), color(c), wiek(w), rodzaj(r), swiat(sw) {
Antylopa::Antylopa(Swiat& sw) : Zwierze(4, 4, 182, 4, 0, "ANTYLOPA", sw) {
	if (swiat.world[pos.y][pos.x] == NULL)
		swiat.world[pos.y][pos.x] = this;
	else {
		reallocate();
	}

}
Antylopa::Antylopa(Swiat& sw, int x, int y) : Zwierze(4, 4, 182, 4, 0, "ANTYLOPA", sw) {
	this->pos.x = x;
	this->pos.y = y;

	if (swiat.world[pos.y][pos.x] == NULL)
		swiat.world[pos.y][pos.x] = this;
	else {
		reallocate();
	}
}
void Antylopa::kolizja(Organizm& other) {
	if (czyOdbilAtak(other))
		other.reallocate();
}

void Antylopa::rozmnazanie() {
	Organizm *child = new Antylopa(swiat, pos.x, pos.y);
	swiat.lista.push_back(child);
	swiat.sortujInicjatywa();
}

p Antylopa::ruch() {
	int s = swiat.losuj(0, 3);
	p tmp;
	if (s == 0)
		tmp.y-=2;
	else if (s == 1)
		tmp.y+=2;
	else if (s == 2)
		tmp.x-=2;
	else if (s == 3)
		tmp.x+=2;

	return tmp;
}