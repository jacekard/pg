#ifndef CZLOWIEK_H
#define CZLOWIEK_H

#include <conio.h>
#include "Zwierze.h"

class Czlowiek : public Zwierze {
private:
	bool tarczaAlzura;
public:
	Czlowiek(Swiat& sw);
	void kolizja(Organizm& other);
	void akcja();
	void rozmnazanie() override {};
	p obslugaStrzalek();
};

#endif