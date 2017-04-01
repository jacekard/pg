#include "Wilk.h"
#include "Swiat.h"

//sila(s), inicjatywa(i), symbol(sy), color(c), wiek(w), rodzaj(r), swiat(sw) {
Wilk::Wilk(Swiat& sw) : Zwierze(1, 5, '%', 14, 0, "WILK", sw) {
}
Wilk::Wilk(Swiat& sw, p poz) : Zwierze(9, 5, '%', 14, 0, "WILK", sw) {
	this->pos = poz;
}
void Wilk::kolizja(Organizm& other) {
	if (czyOdbilAtak(other))
		other.reallocate();

}

void Wilk::rozmnazanie() {
	
		Organizm *child = new Wilk(swiat, this->pos);
		swiat.lista.push_back(child);
		swiat.sortujInicjatywa();
		child->reallocate();
	
}
