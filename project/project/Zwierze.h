#ifndef ZWIERZE_H
#define ZWIERZE_H
#include "Organizm.h"

class Zwierze : public Organizm {
public:
	Zwierze(int s, int i, char sy, int c, int w, string r, Swiat& sw);
	~Zwierze();
	virtual void akcja() override;
	virtual void rozmnazanie() = 0;
	virtual void kolizja(Organizm& other) = 0;
	virtual p ruch();
};


#endif