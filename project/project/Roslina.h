#pragma once
#include "Header.h"

class Roslina : public Organizm{
private:
	int sila;
	int inicjatywa;
	position pos;
public:
	Roslina();
	~Roslina() {};
	void akcja() override;
	void kolizja() override;
	void rysowanie() override;
};