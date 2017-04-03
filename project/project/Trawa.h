#ifndef TRAWA_H
#define TRAWA_H
#include "Roslina.h"

class Trawa : public Roslina {
public:
	Trawa(Swiat&);
	Trawa(Swiat&, int, int);
	void kolizja(Organizm& other);
	void rozmnazanie() override;
	void akcja() override;
};

#endif