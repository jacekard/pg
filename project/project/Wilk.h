#ifndef WILK_H
#define WILK_H
#include "Zwierze.h"

class Zwierze;

class Wilk : public Zwierze {
public:
	Wilk(Swiat& sw) : Zwierze(9, 5, 37, 14, 0, "WILK", sw) {
	}
	void kolizja();
};

void Wilk::kolizja() {
	//zalezne od sily, przeniesc do klasy Organizm (sam komunikat)
	//poszczegolne kolizje dla klas zwierzat overridowac
	//licznik tur!
	//tu mozna dac w swiecie miejsce na komunikaty (zmienne x,y)

	//	list.erase(list.begin() + i - 1);
	//linijka do usuwania zwierzat;

	p::xy(42, 3);
	p::setColor(11);
	printf("Wystapila kolizja!");
	p::setColor();
	this->akcja();

}
#endif