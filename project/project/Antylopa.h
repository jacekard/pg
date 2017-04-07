#ifndef ANTYLOPA_H
#define ANTYLOPA_H
#include "Zwierze.h"

class Antylopa : public Zwierze {
public:
	Antylopa(Swiat&);
	Antylopa(Swiat&, int, int);
	bool czyOdbilAtak(Organizm& atakujacy);
	void rozmnazanie() override;
	point ruch();
};

#endif