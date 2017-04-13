#include "Organizm.h"
#include "Swiat.h"
#include <typeinfo>

Organizm::Organizm(int s, int i, char sy, int c, int w,
	string r, Swiat& sw)
	: sila(s), inicjatywa(i), symbol(sy),
	color(c), wiek(w), rodzaj(r), swiat(sw) {

	pos.x = Util::los(1, swiat.WIDTH - 1);
	pos.y = Util::los(1, swiat.HEIGHT - 1);
	old_pos = pos;
};
void Organizm::rysowanie() {
	Util::gotoxy(pos.x, pos.y);
	Util::setColor(color);
	printf("%c", symbol);
	Util::setColor();
}

int Organizm::getPosx() { return this->pos.x; }
int Organizm::getPosy() { return this->pos.y; }
int Organizm::getOldPosx() { return this->old_pos.x; }
int Organizm::getOldPosy() { return this->old_pos.y; }
int Organizm::getWiek() { return this->wiek; }
int Organizm::getSila() { return this->sila; }
int Organizm::getInicjatywa() { return this->inicjatywa; }
string Organizm::getRodzaj() { return this->rodzaj; }

void Organizm::setPosx(int x) { this->pos.x = x; }
void Organizm::setPosy(int y) { this->pos.y = y; }
void Organizm::setWiek(int a) { this->wiek = a; }
void Organizm::setSila(int s) { this->sila = s; }
void Organizm::grow() { this->wiek++; }

void Organizm::allocate() {
	if (swiat.world[pos.y][pos.x] == NULL)
		swiat.world[pos.y][pos.x] = this;
	else {
		reallocate();
	}
}

//
void Organizm::die() {
	if (this->rodzaj == "CZLOWIEK") swiat.czyKoniec = true;
	else {
		swiat.world[pos.y][pos.x] = NULL;
		for (int v = swiat.lista.size() -1; v >=0 ; v--) {
			if (this == swiat.lista[v]) {
				swiat.lista.erase(swiat.lista.begin() + v);
				//delete this;
				break;
			}
		}
	}
}

void Organizm::reallocate() {
	point tmp;
	int rand;
	rand = Util::los(1, 4);
	for (int i = 0; i < 4; i++) {
		switch ((rand + i)%4 + 1) {
		case 1: 	//case up
			tmp = pos;
			tmp.y--;
			if ((czyDozwolonyRuch(tmp)) &&
				(swiat.world[tmp.y][tmp.x] == NULL)) {
				swiat.world[tmp.y][tmp.x] = this;
				pos = tmp;
				return;
			}
			break;
		case 2: 	//case down
			tmp = pos;
			tmp.y++;
			if ((czyDozwolonyRuch(tmp)) &&
				(swiat.world[tmp.y][tmp.x] == NULL)) {
				swiat.world[tmp.y][tmp.x] = this;
				pos = tmp;
				return;
			}
			break;
		case 3:	//case left
			tmp = pos;
			tmp.x--;
			if ((czyDozwolonyRuch(tmp)) &&
				(swiat.world[tmp.y][tmp.x] == NULL)) {
				swiat.world[tmp.y][tmp.x] = this;
				pos = tmp;
				return;
			}
			break;
		case 4: 	//case right
			tmp = pos;
			tmp.x++;
			if ((czyDozwolonyRuch(tmp)) &&
				(swiat.world[tmp.y][tmp.x] == NULL)) {
				swiat.world[tmp.y][tmp.x] = this;
				pos = tmp;
				return;
			}
			break;
		}
	}
	//swiat.komentuj("Realokacja obiektu " + this->rodzaj + " nie udala sie ");
	for (int v = 0; v < swiat.lista.size(); v++) {
		if (this == swiat.lista[v]) {
			swiat.lista.erase(swiat.lista.begin() + v);
			//delete this;
			break;
		}
	}
}

bool Organizm::czyDozwolonyRuch(point tmp) {
	bool correctX = true;
	bool correctY = true;
	if (tmp.x > swiat.WIDTH - 1 || tmp.x < 1)
		correctX = false;
	if (tmp.y > swiat.HEIGHT - 1 || tmp.y < 1)
		correctY = false;

	if (correctX && correctY) return true;
	else return false;
}

point Organizm::ruch() {
	int kierunek_ruchu = Util::los(0, 3);
	point tmp;
	if (kierunek_ruchu == 0)
		tmp.y--;
	else if (kierunek_ruchu == 1)
		tmp.y++;
	else if (kierunek_ruchu == 2)
		tmp.x--;
	else if (kierunek_ruchu == 3)
		tmp.x++;

	return tmp;
}




