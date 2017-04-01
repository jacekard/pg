#ifndef WILK_H
#define WILK_H
#include "Zwierze.h"

class Wilk : public Zwierze {
public:
	Wilk(Swiat&);
	Wilk(Swiat&, p);
	void kolizja(Organizm& other);
	void rozmnazanie() override;
};

#endif