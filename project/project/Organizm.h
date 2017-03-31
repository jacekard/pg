#ifndef ORGANIZM_H
#define ORGANIZM_H

#include <string>
#include "Set.h"
#include "Rand.h"

class Swiat; //deklaracja zapowiadajaca

class Organizm {
protected:
	int sila;
	int inicjatywa;
	char symbol;
	int color;
	int wiek;
	string rodzaj;
	p pos;
	Swiat& swiat;
public:
	Organizm(int s, int i, char sy, int c, int w,
		string r, Swiat& sw) 
		: sila(s), inicjatywa(i), symbol(sy),
		color(c), wiek(w), rodzaj(r), swiat(sw) {
		pos.x = Random::l(1, 40);//swiat.WIDTH - 1);
		pos.y = Random::l(1, 20);//swiat.HEIGHT - 1);
	};
	virtual void akcja() = 0;
	virtual void kolizja() = 0;
	virtual void rysowanie() {
		p::xy(pos.x, pos.y);
		p::setColor(color);
		printf("%c", symbol);
		p::setColor();
	}
	int getPosx() { return this->pos.x; }
	int getPosy() { return this->pos.y; }
	void setPosx(int x) { this->pos.x = x; }
	void setPosy(int y) { this->pos.y = y; }
	//void setSwiat(Swiat& swiat) {
	//	this->swiat = swiat;
	//};
	//Swiat& operator=(const Swiat& swiat) {
	//	*this = swiat;
	//}
	int getSila() { return this->sila; }
	int getInicjatywa() { return this->inicjatywa; }
	string getRodzaj() { return this->rodzaj; }
	bool operator<(Organizm& a) { return inicjatywa < a.getInicjatywa(); }
	bool czyOdbilAtak(Organizm *atakujacy) {
		if (atakujacy->getSila() == this->sila)
			return false;
		else if (atakujacy->getSila() > this->sila)
			return false;
		else return true;
	}
	void grow() { this->wiek++; }

};



#endif