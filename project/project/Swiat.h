#pragma once

#include "Header.h"

class Swiat {
protected:
	//virtual void Wypisz(ostream& out) const = 0;
	//friend ostream& operator<<(ostream& os, const Swiat& swiat);
private:
	int iloscOrganizmow;
	Organizm **organizmy;
	position pos;
public:
	Swiat();
	~Swiat();
	void wykonajTure();
	void rysujSwiat();
	void rysujMenu();
	void Rysuj();
	static void gotoxy(int x, int y){
		COORD coord;
		coord.X = x;
		coord.Y = y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	}
};

Swiat::Swiat() {
	iloscOrganizmow = 1;
	organizmy = new Organizm*[iloscOrganizmow];
	for (int i = 0; i < iloscOrganizmow; i++) {
		organizmy[i] = new Organizm;
	}

}

Swiat::~Swiat() {
	for (int i = 0; i < iloscOrganizmow; i++) {
		delete organizmy[i];
	}
	delete organizmy;
}


void Swiat::rysujSwiat() {
	HANDLE hConsole;
	int k = 23;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, k);
	/*
	PLANSZA
	*/
	pos.x = 0;
	pos.y = 0;
	for (int x = 0; x < 2; x++) {
		for (int i = 0; i <= WIDTH; i++) {
			gotoxy(pos.x, pos.y);
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
			gotoxy(pos.x, pos.y);
			cout << "|";
			pos.y++;
		}
		pos.x = WIDTH;
		pos.y = OFFY;
	}
	k = 14;
	SetConsoleTextAttribute(hConsole, k);
}

void Swiat::rysujMenu() {
	/*
	MENU KONTEKSTOWE
	*/
	pos.x = WIDTH + OFFX;
	pos.y = 0;
	gotoxy(pos.x, pos.y);
	cout << "- - - - - - - - - - - -";
	gotoxy(pos.x, pos.y + 1);
	cout << "Jacek Ardanowski 165178";
	gotoxy(pos.x, pos.y + 2);
	cout << "Komunikat: ";
	gotoxy(pos.x, pos.y + HEIGHT-1);
	cout << "- - - - - - - - - - - - -";
	gotoxy(pos.x, pos.y + HEIGHT);
	cout << "Komenda: ";
}

void Swiat::wykonajTure() {
	for (int i = 0; i < iloscOrganizmow; i++) {
		organizmy[i]->rysowanie();
		organizmy[i]->akcja();
	}
}

void Swiat::Rysuj() {
	rysujMenu();
	rysujSwiat();
}

//ostream& operator<<(ostream& os, const Swiat& swiat) {
//	swiat.Wypisz(os);
//	return os;
//}

