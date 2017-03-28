#pragma once
#include "Header.h"

class Zwierze : public Organizm {
protected:
	int sila;
	int inicjatywa;
	position pos;
	bool MoveLpr;
	int rand;
public:
	Zwierze();
	~Zwierze() {};
	void akcja() override;
	void kolizja() override;
	void rysowanie() override;
	int losuj();
};

Zwierze::Zwierze() {
	MoveLpr = false;
	rand = 0;
	//pos.x = map_dist(gen);
	//pos.y = map_dist(gen);
}

void Zwierze::akcja() {
	if (move_dist(gen) < 20)
		MoveLpr = true;
	else
		MoveLpr = false;

	if (!MoveLpr)
		rand = losuj();
	else rand = losuj()*losuj();

	if (pos.x + rand < 20 && pos.x + rand >= 1)
		pos.x += round(rand);

		if (MoveLpr) rand = losuj();
		else rand = losuj() * losuj() ;
		if (pos.y + rand < 20 && pos.y + rand >= 1)
			pos.y += round(rand);
}

int Zwierze::losuj() {
	int rand = move_dist(gen);
	if (rand >= 1 && rand < 43) rand = -1;
	else if (rand >= 43 && rand < 56) rand = 0;
	else if (rand >= 56) rand = 1;
	return rand;
}

void Zwierze::kolizja() {};
void Zwierze::rysowanie() {};