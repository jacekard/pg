#include "Zolw.h"
#include "Swiat.h"

//sila(s), inicjatywa(i), symbol(sy), color(c), wiek(w), rodzaj(r), swiat(sw) {
Zolw::Zolw(Swiat& sw) : Zwierze(4, 4, 206, 5, 0, "ZOLW", sw) {
	allocate();
}
Zolw::Zolw(Swiat& sw, int x, int y) : Zwierze(4, 4, 206, 5, 0, "ZOLW", sw) {
	this->pos.x = x;
	this->pos.y = y;
	allocate();
}
bool Zolw::czyOdbilAtak(Organizm& other) {
	if (other.getSila() < 5) {
		other.setPosx(other.getOldPosx());
		other.setPosy(other.getOldPosy());
		swiat.komentuj(" + ZOLW odbija atak! +");
		return true;
	}
	else return false;
}

void Zolw::rozmnazanie() {
	Organizm *child = new Zolw(swiat, pos.x, pos.y);
	swiat.lista.push_back(child);
	swiat.sortujInicjatywa();
	swiat.komentuj(" + Urodzil sie maly zolw! + ");
}

point Zolw::ruch() {
	point tmp;
	if (Util::los(1, 4) == 2) {
		int kierunek_ruchu = Util::los(0, 3);
		  
		if (kierunek_ruchu == 0)
			tmp.y--;
		else if (kierunek_ruchu == 1)
			tmp.y++;
		else if (kierunek_ruchu == 2)
			tmp.x--;
		else if (kierunek_ruchu == 3)
			tmp.x++;
	}
	return tmp;
}