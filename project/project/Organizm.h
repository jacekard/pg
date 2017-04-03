#ifndef ORGANIZM_H
#define ORGANIZM_H

#include <string>
#include "Set.h"

using namespace std;

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

	Organizm(int, int, char, int, int, string, Swiat&);
	~Organizm() {};
	virtual void rozmnazanie() = 0;
	virtual void akcja() = 0;
	virtual void kolizja(Organizm& other) = 0;
	virtual void rysowanie();
	//gettery
	int getPosx();
	int getPosy();
	int getWiek();
	int getSila();
	int getInicjatywa();
	string getRodzaj();
	//settery
	void setPosx(int x);
	void setPosy(int y);
	void setWiek(int a);
	void setSila(int s);
	bool czyDozwolonyRuch(p tmp);
	bool czyOdbilAtak(Organizm& atakujacy);
	bool Organizm::czyZwierze(Organizm& other);
	void grow();
	void die();
	void reallocate();
	void operator=(p& other) {
		this->pos.x += other.x;
		this->pos.y += other.y;
	}


};



#endif