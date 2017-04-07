#include "Lis.h"
#include "Swiat.h"

//sila(s), inicjatywa(i), symbol(sy), color(c), wiek(w), rodzaj(r), swiat(sw) {
Lis::Lis(Swiat& sw) : Zwierze(3, 7, '#', 154, 0, "LIS", sw) {
	allocate();
}
Lis::Lis(Swiat& sw, int x, int y) : Zwierze(3, 7, '#', 154, 0, "LIS", sw) {
	this->pos.x = x;
	this->pos.y = y;
	allocate();
}

void Lis::rozmnazanie() {
	Organizm *child = new Lis(swiat, pos.x, pos.y);
	swiat.lista.push_back(child);
	swiat.sortujInicjatywa();
	swiat.komentuj(" + Urodzil sie maly lisek! + ");
}

void Lis::akcja() {
	point tmp = ruch();

	if (pos.x + tmp.x > swiat.WIDTH - 1 || pos.x + tmp.x < 1)
		tmp.x = 0;
	if (pos.y + tmp.y > swiat.HEIGHT - 1 || pos.y + tmp.y < 1)
		tmp.y = 0;

	old_pos = pos;
	//aktualizuj pozycje
	pos.x += tmp.x;
	pos.y += tmp.y;

	if (swiat.world[pos.y][pos.x] != NULL
		&& swiat.world[pos.y][pos.x] != this)
		swiat.world[pos.y][pos.x]->kolizja(*this);

	//dodaj wiek;
	grow();
}