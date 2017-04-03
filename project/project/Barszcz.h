#ifndef BARSZCZ_H
#define BARSZCZ_H
#include "Roslina.h"

class Barszcz : public Roslina {
public:
	Barszcz(Swiat&);
	Barszcz(Swiat&, int, int);
	void kolizja(Organizm& other);
	void rozmnazanie() override;
	void akcja() override;
};

#endif