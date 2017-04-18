#ifndef SWIAT_H
#define SWIAT_H

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
private:
	point pos;
	int turnCount = 0;
	bool czyKoniec = false;
	bool czySave = false;
	bool czyLoad = false;
	bool tarczaAlzura = false;
	bool czyRespawn = false;
public:
	const int WIDTH = 41;
	const int HEIGHT = 21;
	const int OFFY = 1;
	const int OFFX = 2;

	vector <Organizm*> lista;
	Organizm*** world;
	list <string> komunikaty;

	Swiat();
	~Swiat();
	
	void wykonajTure();
	void turnAction(Organizm &v);
	void addTurn();
	void rysujInterfejs();
	void listaGatunkow();
	void Rysuj();
	void rysujMape();
	void komentuj(string komunikat);
	void wypiszKomunikaty();
	void sortujInicjatywa();
	void save();
	void load();
	void respawn();
	void randomPlants();
	void changeStatement(bool &statement);
	//getters
	bool &getCzyKoniec() { return czyKoniec; }
	bool &getCzySave() { return czySave; }
	bool &getCzyLoad() { return czyLoad; }
	bool &getTarczaAlzura() { return tarczaAlzura; }
	void setTarczaAlzura(bool statement);
	bool &getCzyRespawn() { return czyRespawn; }
	int getTurnCount() { return turnCount; }

};

#endif