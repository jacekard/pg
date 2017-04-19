#ifndef ROSLINA_H
#define ROSLINA_H
#include "Organizm.h"

class Roslina : public Organizm{
protected:
	int maxZakresLosowania;
	bool czyRosnie = true;
public:
	Roslina(int s, int i, char sy, int c, int w, string r, Swiat& sw);
	Roslina(Swiat&, int, int);

	~Roslina();
	virtual void akcja();
	virtual void rozmnazanie() = 0;
	virtual void kolizja(Organizm& other);
	bool rozsiewanie();
};

#endif