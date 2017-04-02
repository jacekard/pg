#ifndef OWCA_H
#define OWCA_H
#include "Zwierze.h"

class Owca : public Zwierze {
public:
	Owca(Swiat&);
	Owca(Swiat&, int, int);
	void kolizja(Organizm& other);
	void rozmnazanie() override;
};

#endif