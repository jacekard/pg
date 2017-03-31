#ifndef SWIAT_H
#define SWIAT_H

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <functional>
#include "Set.h"

#include "Wilk.h"
#include "Czlowiek.h"
#include "Trawa.h"
//class Organizm;
//class Zwierze;

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
	vector <Organizm*> list;
	Organizm*** world;
	Organizm *player;
	Swiat();
	~Swiat();
	void wykonajTure();
	void rysujInterfejs();
	void listaGatunkow();
	void Rysuj();
	void rysujMape();
};


Swiat::Swiat() {

	//Organizm *gowno = new Organizm(this);

	turnCount = 0;
	int LICZBA_STWOROW = 15;
	world = new Organizm**[HEIGHT];

	for (int i = 0; i < HEIGHT; i++) {
		world[i] = new Organizm*[WIDTH];
	}
	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; x < WIDTH; x++) {
			world[y][x] = NULL;
		}
	}

	for (int k = 0; k < LICZBA_STWOROW; k++) {
		list.push_back(new Wilk(*this));
		list.push_back(new Trawa(*this));
		list.push_back(new Trawa(*this));
	}

	player = new Czlowiek(*this);
	sort(list.begin(), list.end(),
		[](Organizm* a, Organizm* b) { return a->getInicjatywa() > b->getInicjatywa(); });

	world[player->getPosy()][player->getPosx()] = player;

	for (int i = 0; i < list.size(); i++) {
		//if (world[list[i]->getPosy()][list[i]->getPosx()] == NULL)
		world[list[i]->getPosy()][list[i]->getPosx()] = list[i];
		//problem z respawnem w tym samym miejscu!
	}

	//for (int i = 0; i < list.size(); i++) {
	//	int b = list[i]->getPosx();
	//	int a = list[i]->getPosy();
	//	if (world[a][b] == NULL)
	//		world[a][b] = list[i];
	//	else {
	//		list.erase(list.begin()+i-1);
	//	}
	//}
}

Swiat::~Swiat() {
	list.erase(list.begin(), list.end());
}

void Swiat::Rysuj() {
	rysujInterfejs();
	//listaGatunkow();
	rysujMape();
	p::xy(54, 2);

}

void Swiat::wykonajTure() {

	//for (int y = 0; y < HEIGHT; y++) {
	//	for (int x = 0; x < WIDTH; x++) {
	//		world[y][x] = NULL;
	//	}
	//}

	for (int i = 0; i < list.size(); i++) {
		world[list[i]->getPosy()][list[i]->getPosx()] = NULL;
		list[i]->akcja();
		world[list[i]->getPosy()][list[i]->getPosx()] = list[i];
	}

	p tmp;
	tmp.x = player->getPosx();
	tmp.y = player->getPosy();

	/*
	*/
	Rysuj();
	/*
	*/
	player->akcja();
	world[tmp.y][tmp.x] = NULL;
	world[player->getPosy()][player->getPosx()] = player;

	//for (int y = 0; y < HEIGHT; y++) {
	//	for (int x = 0, i = 0; (x < WIDTH) && (i < list.size()); x++, i++) {
	//		if (i < list.size()) {
	//			
	//			//list[i]->akcja();

	//			int a = list[i]->getPosx();
	//			int b = list[i]->getPosy();
	//			if (a == x && b == y) {
	//				if (world[y][x]) {
	//					list[i]->kolizja();
	//					i--;
	//				}
	//				else
	//					world[y][x] = list[i];
	//			}
	//			else
	//				world[y][x] = NULL;
	//		}
	//	}
	//}






	turnCount++;
}

void Swiat::rysujInterfejs() {
	p::setColor();
	pos.x = 0;
	pos.y = 0;
	for (int x = 0; x < 2; x++) {
		for (int i = 0; i <= WIDTH; i++) {
			p::xy(pos.x, pos.y);
			cout << "-";
			pos.x++;
		}
		pos.x = 0;
		pos.y = HEIGHT;
	}
	pos.x = 0;
	pos.y = 1;
	for (int x = 0; x < 2; x++) {
		for (int i = 0; i < HEIGHT - 1; i++) {
			p::xy(pos.x, pos.y);
			cout << "|";
			pos.y++;
		}
		pos.x = WIDTH;
		pos.y = OFFY;
	}

	int x = WIDTH + OFFX;
	p::xy(x, 0);
	cout << "- - - - - - - - - - - -";
	p::xy(x, 1);
	cout << "Jacek Ardanowski 165178";
	p::xy(x, 2);
	cout << "Komunikat: ";
	p::xy(x, 5);
	cout << "- - - - - - - - - - - -";
	//p::xy(pos.x, HEIGHT);
	//cout << "Komenda: ";
}

void Swiat::rysujMape() {
	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; x < WIDTH; x++) {
			if (world[y][x] == NULL) {
				p::xy(x, y);
				//	printf("%c", 177);
			}
			else {
				p::xy(x, y);
				if ((player->getPosx() == x) &&
					(player->getPosy() == y))
					player->rysowanie();
				else
					world[y][x]->rysowanie();
			}
		}
	}
}

void Swiat::listaGatunkow() {
	int pom = 0;
	int x = WIDTH + OFFX;
	int y = 6;
	p::xy(x, y);
	cout << "Lista organizmow: ";
	y++;
	for (int i = 0; i < list.size(); i++) {
		p::xy(x, y + i);

		cout << i + 1 << ". " << list[i]->getRodzaj() << ", ";
		pom = i;
	}
	x = WIDTH + OFFX;
	y++;
	p::xy(x, y + pom);
	cout << player->getRodzaj();
}


#endif