#pragma once
#include "Swiat.h"

class Organizm {
public:
	int sila = 0;
	int inicjatywa = 0;
	int polozenie = 0;
	
	virtual void akcja();
	virtual void kolizja();
	virtual void rysowanie();
	virtual ~Organizm();
};

