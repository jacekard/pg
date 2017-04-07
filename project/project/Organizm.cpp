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

bool  Organizm::czyOdbilAtak(Organizm& atakujacy) {
	if (&atakujacy == this) return false;
	string rodzaj = atakujacy.getRodzaj();
	if (rodzaj == "OWCA" || rodzaj == "LIS" || rodzaj == "ZOLW" ||
		rodzaj == "ANTYLOPA" || rodzaj == "CYBER-OWCA" ||
		rodzaj == "WILK" || rodzaj == "CZLOWIEK") {

		if (this->rodzaj == "OWCA" &&
			atakujacy.getSila() < 5) {
			//NAPASTNIK MUSI WROCIC NA SWOJE POPRZEDNIE POLE ;/
			atakujacy.reallocate();
		}

		////rozmnazanie
		//if (rodzaj == this->rodzaj) {
		//	if (this->wiek > 10 && atakujacy.getWiek() > 10) {
		//		if (Util::los(1, 5) == 1) {
		//			this->rozmnazanie();
		//			swiat.komentuj(" + Urodzil/a sie maly/a " + this->rodzaj + "! + ");
		//		}
		//		return true;
		//	}
		//}
		//walka
		else if (atakujacy.getSila() >= this->sila) {

			if (this->rodzaj == "ANTYLOPA" &&
				Util::los(0, 1) == 0) {
				this->reallocate();
				swiat.komentuj(this->rodzaj + " ucieka przed walka!");
				return false;
			}
			else if (rodzaj == "ANTYLOPA" &&
				Util::los(0, 10 == 0)) {
				atakujacy.reallocate();
				swiat.komentuj(this->rodzaj + " ucieka przed walka!");
				return false;
			}

			if (this->rodzaj == "CZLOWIEK" && swiat.tarczaAlzura) {
				swiat.komentuj(this->rodzaj + " uzywa Tarczy Alzura!");
				return true;
			}

			if (rodzaj == "ANTYLOPA" || rodzaj == "OWCA") {
				swiat.komentuj(" + " + this->rodzaj + " ginie w paszczy " + rodzaj.replace(rodzaj.length() - 1, 1, "Y! + "));
			}
			else if (rodzaj == "WILK" || rodzaj == "LIS")
				swiat.komentuj(" + " + 
				this->rodzaj + 
				" ginie w paszczy " + 
				rodzaj + 
				"A! + ");
			else if (rodzaj == "ZOLW")
				swiat.komentuj(" + " + this->rodzaj + " ginie w paszczy " + rodzaj + "IA! + ");
			else if (rodzaj == "CZLOWIEK")
				swiat.komentuj(" + " + this->rodzaj + " ginie z reki " + rodzaj + "A! + ");
			
			this->die();
			return false;
		}
		else {
			swiat.komentuj(this->rodzaj + " odbil atak!");
			return true;

		}
	}
	else {
		if (rodzaj == "GUARANA") {
			this->setSila(this->getSila() + 3);
			swiat.komentuj(" + " + this->rodzaj + " ma teraz +3 do sily! + ");
		}
		else if (rodzaj == "JAGODY") {
			swiat.komentuj(" + " + this->rodzaj + " jest otruty przez WILCZE JAGODY! + ");
			this->die();
		}
		else if (rodzaj == "BARSZCZ") {
			if (this->getRodzaj() != "CYBER-OWCA") {
				swiat.komentuj(" + " + this->rodzaj + " ginie otruty przez BARSZCZ! + ");
				this->die();
			}
		}
		swiat.komentuj(" + " + this->rodzaj + " zjada " + rodzaj);
		atakujacy.die();
		return false;
	}

}
void Organizm::die() {
	if (this->rodzaj == "CZLOWIEK") swiat.czyKoniec = true;
	else {
		swiat.world[pos.y][pos.x] = NULL;
		for (int v = 0; v < swiat.lista.size(); v++) {
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




