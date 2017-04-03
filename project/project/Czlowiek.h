#ifndef CZLOWIEK_H
#define CZLOWIEK_H

#include <conio.h>
#include "Zwierze.h"

class Czlowiek : public Zwierze {
private:
	int coolDown;
	int skillEnabled;
public:
	Czlowiek(Swiat&);
	Czlowiek(Swiat&, int, int);
	void kolizja(Organizm& other);
	void akcja() override;
	void rozmnazanie() override {};
	void umiejetnosc();
	p obslugaStrzalek();
};

#endif