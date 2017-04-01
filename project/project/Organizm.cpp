#include "Organizm.h"
#include "Swiat.h"
#include <typeinfo>

Organizm::Organizm(int s, int i, char sy, int c, int w,
	string r, Swiat& sw)
	: sila(s), inicjatywa(i), symbol(sy),
	color(c), wiek(w), rodzaj(r), swiat(sw) {
	
	pos.x = swiat.losuj(1, swiat.WIDTH - 1);
	pos.y = swiat.losuj(1, swiat.HEIGHT - 1);
	if (swiat.world[pos.y][pos.x] == NULL)
		swiat.world[pos.y][pos.x] = this;
	else {
		reallocate();
	}

};
void Organizm::rysowanie() {
	p::xy(pos.x, pos.y);
	p::setColor(color);
	printf("%c", symbol);
	p::setColor();
}

int Organizm::getPosx() { return this->pos.x; }
int Organizm::getPosy() { return this->pos.y; }
int Organizm::getWiek() { return this->wiek; }
int  Organizm::getSila() { return this->sila; }
int  Organizm::getInicjatywa() { return this->inicjatywa; }
string  Organizm::getRodzaj() { return this->rodzaj; }

void Organizm::setPosx(int x) { this->pos.x = x; }
void Organizm::setPosy(int y) { this->pos.y = y; }
void Organizm::setWiek(int a) { this->wiek = a; }
void  Organizm::grow() { this->wiek++; }

//bool  Organizm::operator<(Organizm& a) { return inicjatywa < a.getInicjatywa(); }
bool  Organizm::czyOdbilAtak(Organizm& atakujacy) {
	string rodzaj = atakujacy.getRodzaj();
	if (rodzaj == "OWCA" || rodzaj == "LIS" || rodzaj == "ZOLW" ||
		rodzaj == "ANTYLOPA" || rodzaj == "CYBER-OWCA" ||
		rodzaj == "WILK" || rodzaj == "CZLOWIEK") {
		if (rodzaj == this->rodzaj) {
			if (this->wiek > 10 && atakujacy.getWiek() > 10) {
				this->rozmnazanie();
				swiat.komentuj("Urodzil/a sie maly/a " + this->rodzaj + "!");
			}
		}
		else if (atakujacy.getSila() >= this->sila) {
			swiat.komentuj(this->rodzaj + " zostal pokonany przez " + rodzaj + "!");
			this->die();
			return false;
		}
		else {
			return true;
			swiat.komentuj(this->rodzaj + " odbil atak!");
		}
	}
	else {
		swiat.komentuj(this->rodzaj + " zjada " + rodzaj);
		atakujacy.die();
		return false;
	}

}
void Organizm::die() {
	//tutaj jest jakis problem przy wpisywaniu NULL do world[][]
	//nie wiem jaki, ale trzeba to naprawic!
	if (this->rodzaj == "CZLOWIEK") swiat.czyKoniec = true;
	else {
		swiat.world[pos.y][pos.x] = NULL;
		for (int v = 0; v < swiat.lista.size(); v++) {
			if (this == swiat.lista[v]) {
				swiat.lista.erase(swiat.lista.begin() + v);
				break;
			}
		}
		swiat.sortujInicjatywa();
	}
}

void Organizm::reallocate() {
	p tmp;

	
	int rand = swiat.losuj(1, 4);
	switch (rand) {
	case 1: 	//case up
		tmp = pos;
		tmp.y--;
		if ((czyDozwolonyRuch(tmp)) &&
			(swiat.world[tmp.y][tmp.x] == NULL)) {
			swiat.world[tmp.y][tmp.x] = this;
			pos = tmp;
			return;
		break;
	}
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

	//swiat.komentuj("Realokacja obiektu " + this->rodzaj + " nie udala sie ");
	this->die();
}

bool Organizm::czyDozwolonyRuch(p tmp) {
	bool correctX = true;
	bool correctY = true;
	if (tmp.x > swiat.WIDTH - 1 || tmp.x < 1)
		correctX = false;
	if (tmp.y > swiat.HEIGHT - 1 || tmp.y < 1)
		correctY = false;

	if (correctX && correctY) return true;
	else return false;
}



//Organizm& Organizm::operator=(const Organizm& other) {
//	//mozliwe ze to przeciazenie bedzie zbedne
//}




