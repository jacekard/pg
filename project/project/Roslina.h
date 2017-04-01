#ifndef ROSLINA_H
#define ROSLINA_H
#include "Organizm.h"

class Roslina : public Organizm{
public:
	Roslina(int s, int i, char sy, int c, int w, string r, Swiat& sw);
	~Roslina();
	void akcja() override;
};

#endif