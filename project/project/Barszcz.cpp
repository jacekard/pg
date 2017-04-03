#include "Barszcz.h"
#include "Swiat.h"

Barszcz::Barszcz(Swiat& sw) : Roslina(99, 0, 223, 11, 0, "BARSZCZ", sw) {
	if (swiat.world[pos.y][pos.x] == NULL)
		swiat.world[pos.y][pos.x] = this;
	else {
		reallocate();
	}
};

Barszcz::Barszcz(Swiat& sw, int x, int y) : Roslina(99, 0, 223, 11, 0, "BARSZCZ", sw) {
	this->pos.x = x;
	this->pos.y = y;

	if (swiat.world[pos.y][pos.x] == NULL)
		swiat.world[pos.y][pos.x] = this;
	else {
		reallocate();
	}
}

void Barszcz::rozmnazanie() {
	Organizm *child = new Barszcz(swiat, pos.x, pos.y);
	swiat.lista.push_back(child);
	swiat.sortujInicjatywa();
}

void Barszcz::kolizja(Organizm& other) {

}

void Barszcz::akcja() {
	grow();

	//if (validPosY(pos.y - 1) && (swiat.world[pos.y - 1][pos.x] != NULL)) {
	//	swiat.world[pos.y - 1][pos.x]->die();
	//	swiat.komentuj(" + " + swiat.world[pos.y - 1][pos.x]->getRodzaj() + " ginie przez trujace opary BARSZCZU! + ");
	//}
	//if (validPosY(pos.y + 1) && (swiat.world[pos.y + 1][pos.x] != NULL)) {
	//	swiat.world[pos.y + 1][pos.x]->die();
	//	swiat.komentuj(" + " + swiat.world[pos.y + 1][pos.x]->getRodzaj() + " ginie przez trujace opary BARSZCZU! + ");
	//}
	//if (validPosX(pos.x - 1) && (swiat.world[pos.y][pos.x - 1] != NULL)) {
	//	swiat.world[pos.y][pos.x - 1]->die();
	//	swiat.komentuj(" + " + swiat.world[pos.y][pos.x - 1]->getRodzaj() + " ginie przez trujace opary BARSZCZU! + ");
	//}
	//if (validPosX(pos.x + 1) 
	//	&& (swiat.world[pos.y][pos.x + 1] != NULL)) {
	//	swiat.world[pos.y][pos.x + 1]->die();
	//	swiat.komentuj(" + " + swiat.world[pos.y][pos.x + 1]->getRodzaj() + " ginie przez trujace opary BARSZCZU! + ");
	//}

	if (swiat.losuj(1, 300) == swiat.losuj(1, 50))
		rozmnazanie();
}