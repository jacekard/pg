#ifndef ROSLINA_H
#define ROSLINA_H
#include "Organizm.h"

class Roslina : public Organizm{
public:
	Roslina(int s, int i, char sy, int c, int w, string r, Swiat& sw);
	~Roslina();
	virtual void akcja() = 0;
	virtual void rozmnazanie() = 0;
	virtual void kolizja(Organizm& other) override;
	bool validPosY(int y);
	bool validPosX(int x);
};

#endif