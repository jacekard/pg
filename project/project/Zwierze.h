#ifndef ZWIERZE_H
#define ZWIERZE_H
#include "Organizm.h"
#include "Swiat.h"

class Zwierze : public Organizm {
public:
		Zwierze(int s, int i, char sy, int c, int w,
		string r, Swiat& sw) : Organizm(s, i, sy, c, w, r, sw) {
	}
	//Zwierze(int x, int y) {
	//	setPosx(x);
	//	setPosy(y);
	//};
	~Zwierze();
	void akcja() override;
	p ruch();
};

//
p Zwierze::ruch() {
	enum Kierunek {
		GORA,
		DOL,
		LEWO,
		PRAWO
	} s;

	int rand = Random::l(1, 100);
	if (rand <= 25) s = GORA;
	else if (rand > 25 && rand <= 50) s = DOL;
	else if (rand > 50 && rand <= 75) s = LEWO;
	else if (rand > 75 && rand <= 100) s = PRAWO;

	p tmp;
	tmp.x = 0;
	tmp.y = 0;
	switch (s) {
	case GORA:
		tmp.y--;
		break;
	case DOL:
		tmp.y++;
		break;
	case LEWO:
		tmp.x--;
		break;
	case PRAWO:
		tmp.x++;
	}
	return tmp;

}

void Zwierze::akcja() {
	//mozliwe, ze updejtuj pozycje dopiero kiedy sprawdzisz
	//czy na tej pozycji zcegos juz nie ma
	//potrzeba referencja na swiat!!
	p tmp = ruch();
	
	if (pos.x + tmp.x > 40 || pos.x + tmp.x < 1)
		tmp.x = 0;
	if (pos.y + tmp.y > 20 || pos.y + tmp.y < 1)
		tmp.y = 0;

	//if(world[ty][tx]) to coœ tam kolizja np.

	pos.x += tmp.x;
	pos.y += tmp.y;
}


Zwierze::~Zwierze() {};

#endif