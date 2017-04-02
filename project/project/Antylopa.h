#ifndef ANTYLOPA_H
#define ANTYLOPA_H
#include "Zwierze.h"

class Antylopa : public Zwierze {
public:
	Antylopa(Swiat&);
	Antylopa(Swiat&, int, int);
	void kolizja(Organizm& other);
	void rozmnazanie() override;
	p ruch();
};

#endif