#ifndef JAGODY_H
#define JAGODY_H
#include "Roslina.h"

class Jagody : public Roslina {
public:
	Jagody(Swiat&);
	Jagody(Swiat&, int, int);
	void kolizja(Organizm& other);
	void rozmnazanie() override;
	void akcja() override;
};

#endif