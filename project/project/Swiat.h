#ifndef SWIAT_H
#define SWIAT_H

//#include <functional>
#include <iostream>
#include <algorithm>
#include <random>
#include <fstream>
#include <vector>
#include <list>
#include "Point.h"
#include "Util.h"

#include "Czlowiek.h"
#include "Wilk.h"
#include "Antylopa.h"
#include "Owca.h"
#include "Zolw.h"
#include "Lis.h"

#include "Trawa.h"
#include "Mlecz.h"
#include "Guarana.h"
#include "Jagody.h"
#include "Barszcz.h"

using namespace std;

class Swiat {
protected:

private:
	point pos;
public:
	const int WIDTH = 41;
	const int HEIGHT = 21;
	const int OFFY = 1;
	const int OFFX = 2;

	vector <Organizm*> lista;
	Organizm*** world;
	Organizm *player;
	list <string> komunikaty;
	string ostatni_komunikat;
	Swiat();
	~Swiat();

	int turnCount;
	bool czyKoniec;
	bool czySave;
	bool czyLoad;
	bool tarczaAlzura;
	bool czyRespawn;
	
	void wykonajTure();
	void rysujInterfejs();
	void listaGatunkow();
	void Rysuj();
	void rysujMape();
	void komentuj(string komunikat);
	void wypiszKomunikaty(int x, int y);
	void sortujInicjatywa();
	void save();
	void load();
	void respawn();
	void randomPlants();
};

#endif