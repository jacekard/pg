#ifndef TRAWA_H
#define TRAWA_H
#include "Roslina.h"

class Trawa : public Roslina {
public:
	Trawa(Swiat&);
	Trawa(Swiat&, p);
	void kolizja(Organizm& other);
	void rozmnazanie() override;
};

#endif