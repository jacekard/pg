#pragma once
#include "Header.h"



class Organizm {
private:
	int sila;
	int inicjatywa;
	position pos;
public:
	virtual void akcja() {};
	virtual void kolizja() {};
	virtual void rysowanie() {};

	static void gotoxy(int x, int y){
		COORD coord;
		coord.X = x;
		coord.Y = y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	}


};
