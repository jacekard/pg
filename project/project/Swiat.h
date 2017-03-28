#pragma once
#include "Organizm.h"
#include <iostream>
using namespace std;

class Swiat {
protected:
	virtual void Wypisz(ostream& out) const = 0;
	friend ostream& operator<<(ostream& os, const Swiat& swiat);
public:
	virtual ~Swiat();
	virtual void wykonajTure();
	virtual void rysujSwiat();
	Organizm organizmy[];
	
};

ostream& operator<<(ostream& os, const Swiat& figura) {
	figura.Wypisz(os);
	return os;
}
