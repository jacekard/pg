#ifndef ORGANIZM_H
#define ORGANIZM_H

#include <string>
#include "Point.h"

using namespace std;

//deklaracja zapowiadajaca
class Swiat; 

class Organizm {
protected:
	int sila;
	int inicjatywa;
	char symbol;
	int color;
	int wiek;
	string rodzaj;
	point pos;
	point old_pos;
	Swiat& swiat;
public:
	Organizm(int, int, char, int, int, string, Swiat&);
	~Organizm() {};
	
	//metody wirtualne
	virtual void rozmnazanie() = 0;
	virtual void akcja() = 0;
	virtual void kolizja(Organizm& other) = 0;
	virtual void rysowanie();
	virtual point ruch();

	//gettery
	int getPosx() { return this->pos.x; }
	int getPosy() { return this->pos.y; }
	int getOldPosx() { return this->old_pos.x; }
	int getOldPosy() { return this->old_pos.y; }
	int getWiek() { return this->wiek; }
	int getSila() { return this->sila; }
	int getInicjatywa() { return this->inicjatywa; }
	string getRodzaj() { return this->rodzaj; }
	
	//settery
	void setPosx(int x) { this->pos.x = x; }
	void setPosy(int y) { this->pos.y = y; }
	void setWiek(int a) { this->wiek = a; }
	void setSila(int s) { this->sila = s; }
	
	//metody
	bool czyDozwolonyRuch(point tmp);
	bool czyOdbilAtak(Organizm& atakujacy);
	void grow();
	void die();
	void reallocate();
	void allocate();
};



#endif