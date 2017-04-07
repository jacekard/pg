#include "Antylopa.h"
#include "Swiat.h"

//sila(s), inicjatywa(i), symbol(sy), color(c), wiek(w), rodzaj(r), swiat(sw) {
Antylopa::Antylopa(Swiat& sw) : Zwierze(4, 4, 182, 4, 0, "ANTYLOPA", sw) {
	allocate();
}
Antylopa::Antylopa(Swiat& sw, int x, int y) : Zwierze(4, 4, 182, 4, 0, "ANTYLOPA", sw) {
	this->pos.x = x;
	this->pos.y = y;
	allocate();
}

bool Antylopa::czyOdbilAtak(Organizm& atakujacy) {
	if(Util::los(0, 1) == 1) {
		this->reallocate();
		swiat.komentuj(this->rodzaj + " ucieka przed walka z " + atakujacy.getRodzaj() + "! +");
		return true;
	}
	else return false;
}

void Antylopa::rozmnazanie() {
	Organizm *child = new Antylopa(swiat, pos.x, pos.y);
	swiat.lista.push_back(child);
	swiat.sortujInicjatywa();
	swiat.komentuj(" + Urodzila sie mala antylopa! + ");
}

point Antylopa::ruch() {
	int kierunek_ruchu = Util::los(0, 3);
	point tmp;
	if (kierunek_ruchu == 0)
		tmp.y-=2;
	else if (kierunek_ruchu == 1)
		tmp.y+=2;
	else if (kierunek_ruchu == 2)
		tmp.x-=2;
	else if (kierunek_ruchu == 3)
		tmp.x+=2;

	return tmp;
}