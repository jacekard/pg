#ifndef SWIAT_H
#define SWIAT_H

#include <iostream>
using namespace std;
#include <vector>
#include <list>
#include <algorithm>
#include <functional>
#include <random>
#include "Set.h"

#include "Wilk.h"
#include "Czlowiek.h"
#include "Trawa.h"

class Swiat {
protected:

private:
	p pos;
public:
	const int WIDTH = 41;
	const int HEIGHT = 21;
	const int OFFY = 1;
	const int OFFX = 2;
	int turnCount;
	vector <Organizm*> lista;
	Organizm*** world;
	Organizm *player;
	list <string> komunikaty;
	Swiat();
	~Swiat();
	void wykonajTure();
	void rysujInterfejs();
	void listaGatunkow();
	void Rysuj();
	void rysujMape();
	int losuj(int a, int b);
	bool czyKoniec;
	bool tarczaAlzura;
	void komentuj(string komunikat);
	void wypiszKomunikaty(int x, int y);
	void sortujInicjatywa();
};

#endif