#pragma once
#include "Header.h"

class Czlowiek : public Zwierze {
private:
	char znak;
public:
	Czlowiek();
	~Czlowiek() {};
	void kolizja();
	void rysowanie();
	void akcja();
};

Czlowiek::Czlowiek() {
	this->sila = 9;
	this->inicjatywa = 5;
	this->pos.x = WIDTH /2;
	this->pos.y = HEIGHT / 2;
}

void Czlowiek::rysowanie() {
	gotoxy(pos.x, pos.y);
	HANDLE hConsole;
	int k = 12;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, k);
	printf("%c", 254);
	k = 15;
	SetConsoleTextAttribute(hConsole, k);
}

void Czlowiek::kolizja() {

};

void Czlowiek::akcja() {
	unsigned char znak = getch();

	switch (znak)
	{
	case 0: //klawisze specjalne
	case 224: //klawisze specjalne
		znak = getch();
		switch (znak)
		{
		case 72: //strza³ka w górê
			pos.y--;
			break;
		case 80: //strza³ka w dó³
			pos.y++;
			break;
		case 75: //strza³ka w lewo
			pos.x--;
			break;
		case 77: //strza³ka w prawo
			pos.x++;
			break;
		default:
			break;
		}
		znak = 0;
		break;
	}
}
