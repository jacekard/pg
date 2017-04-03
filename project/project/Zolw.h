#ifndef ZOLW_H
#define ZOLW_H
#include "Zwierze.h"

class Zolw : public Zwierze {
public:
	Zolw(Swiat&);
	Zolw(Swiat&, int, int);
	void kolizja(Organizm& other);
	void rozmnazanie() override;
};

#endif