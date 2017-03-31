#ifndef ROSLINA_H
#define ROSLINA_H
#include "Organizm.h"

class Organizm;

class Roslina : public Organizm{
public:
	Roslina(int s, int i, char sy, int c, int w,
		string r, Swiat& sw) : Organizm(s, i, sy, c, w, r, sw) {};
	~Roslina() {};
	void akcja();
	void kolizja() {};
};

void Roslina::akcja() {
	int rand = Random::l(1, 100);

}

#endif