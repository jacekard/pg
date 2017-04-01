#ifndef ZWIERZE_H
#define ZWIERZE_H
#include "Organizm.h"

class Zwierze : public Organizm {
public:
	Zwierze(int s, int i, char sy, int c, int w, string r, Swiat& sw);
	~Zwierze();
	void akcja() override;
	p ruch();
};


#endif