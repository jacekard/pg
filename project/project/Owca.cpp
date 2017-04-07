#include "Owca.h"
#include "Swiat.h"

//sila(s), inicjatywa(i), symbol(sy), color(c), wiek(w), rodzaj(r), swiat(sw) {
Owca::Owca(Swiat& sw) : Zwierze(4, 4, '@', 15, 0, "OWCA", sw) {
	allocate();
}
Owca::Owca(Swiat& sw, int x, int y) : Zwierze(4, 4, '@', 15, 0, "OWCA", sw) {
	this->pos.x = x;
	this->pos.y = y;
	allocate();
}

void Owca::rozmnazanie() {
	Organizm *child = new Owca(swiat, pos.x, pos.y);
	swiat.lista.push_back(child);
	swiat.sortujInicjatywa();
	swiat.komentuj(" + Urodzila sie mala biala owieczka! + ");
}
