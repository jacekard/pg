#include "Zwierze.h"
#include "Swiat.h"

Zwierze::Zwierze(int s, int i, char sy, int c, int w, string r, Swiat& sw)
: Organizm(s, i, sy, c, w, r, sw) {
}

void Zwierze::akcja() {
	p tmp = ruch();

	if (pos.x + tmp.x > swiat.WIDTH - 1 || pos.x + tmp.x < 1)
		tmp.x = 0;
	if (pos.y + tmp.y > swiat.HEIGHT - 1 || pos.y + tmp.y < 1)
		tmp.y = 0;

	//aktualizuj pozycje
	pos.x += tmp.x;
	pos.y += tmp.y;

	if (swiat.world[pos.y][pos.x] != NULL)
		kolizja(*swiat.world[pos.y][pos.x]);
	
	//dodaj wiek;
	grow();
}

Zwierze::~Zwierze() {

};