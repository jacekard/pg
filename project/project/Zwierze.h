#ifndef ZWIERZE_H
#define ZWIERZE_H
#include "Organizm.h"

class Zwierze : public Organizm {
public:
	Zwierze(int s, int i, char sy, int c, int w, string r, Swiat& sw);
	~Zwierze();
	virtual void akcja();
	virtual void kolizja(Organizm& other);
	virtual bool czyOdbilAtak(Organizm& atakujacy);
	virtual bool czyRozmnazanie(Organizm& other);
	virtual void rozmnazanie() = 0;
};


#endif