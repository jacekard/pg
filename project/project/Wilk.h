#pragma once
#include "Header.h"

class Wilk : public Zwierze {
private:
	//int sila;
	//int inicjatywa;
	//position pos;
	int symbol;
public:
	Wilk();
	~Wilk() {};
	void kolizja();
	void rysowanie();
};

Wilk::Wilk() {
	this->sila = 9;
	this->inicjatywa = 5;
	this->pos.x = x_dist(gen);
	this->pos.y = y_dist(gen);
	symbol = move_dist(gen);
}

void Wilk::rysowanie() {
	gotoxy(pos.x, pos.y);
	if (symbol <= 50)
		printf("@");
	else
		printf("$");
}

void Wilk::kolizja() {
	
};