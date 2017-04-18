#include "Czlowiek.h"
#include "Swiat.h"

Czlowiek::Czlowiek(Swiat& sw) : Zwierze(5, 4, 254, 12, 0, "CZLOWIEK", sw) {
	coolDown = 0;
	skillEnabled = 5;
	allocate();
};

Czlowiek::Czlowiek(Swiat& sw, int x, int y) : Zwierze(5, 4, 254, 12, 0, "CZLOWIEK", sw) {
	coolDown = 0;
	skillEnabled = 5;
	this->pos.x = x;
	this->pos.y = y;
	allocate();
};

void Czlowiek::akcja() {

	swiat.Rysuj();
	
	old_pos = pos;
	unsigned char znak = getch();

	if (--skillEnabled < 0)
		swiat.setTarczaAlzura(0);

	switch (znak)
	{
	case 'q':
		swiat.changeStatement(swiat.getCzyKoniec());
		swiat.komentuj(" + Wyszedles z gry +");
		break;
	case 'p': //tarcza alzura
		umiejetnosc();
		break;
	case 's':
		swiat.changeStatement(swiat.getCzySave());
		break;
	case 'l':
		swiat.changeStatement(swiat.getCzyLoad());
		break;
	case 'r':
		swiat.changeStatement(swiat.getCzyRespawn());
		break;
	case 0: //klawisze specjalne
	case 224: //klawisze specjalne
		znak = getch();
		switch (znak)
		{
		case 72: //strza³ka w górê
			if (pos.y - 1 > 0)
				pos.y--;
			break;
		case 80: //strza³ka w dó³
			if (pos.y + 1 <= swiat.HEIGHT - 1)
				pos.y++;
			break;
		case 75: //strza³ka w lewo
			if (pos.x - 1 > 0)
				pos.x--;
			break;
		case 77: //strza³ka w prawo
			if (pos.x + 1 <= swiat.WIDTH - 1)
				pos.x++;
			break;
		default:
			break;
		}
		znak = 0;
		break;
	}
	if (swiat.world[pos.y][pos.x] != NULL 
		&& swiat.world[pos.y][pos.x] != this)
		swiat.world[pos.y][pos.x]->kolizja(*this);

	grow();
	coolDown--;
}

void Czlowiek::umiejetnosc() {
	if (!swiat.getTarczaAlzura() && coolDown <= 0) {
		coolDown = 11;
		skillEnabled = 5;
		swiat.setTarczaAlzura(1);
		skillEnabled--;
	}
}

bool Czlowiek::czyOdbilAtak(Organizm& atakujacy) {
	if (swiat.getTarczaAlzura()) {
		atakujacy.reallocate();
		swiat.komentuj(this->rodzaj + " uzywa Tarczy Alzura! + ");
		return true;
	}
	else return false;
}
