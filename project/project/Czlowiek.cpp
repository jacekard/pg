#include "Czlowiek.h"
#include "Swiat.h"
//
//void Czlowiek::kolizja() {
//
//};

Czlowiek::Czlowiek(Swiat& sw) : Zwierze(5, 4, 254, 12, 0, "CZLOWIEK", sw) {
	tarczaAlzura = false;
};

void Czlowiek::akcja() {
	unsigned char znak = getch();

	switch (znak)
	{
	case 0: //klawisze specjalne
	case 'q':
		swiat.czyKoniec = true;
		break;
	case 'p': //tarcza alzura
		tarczaAlzura = true;
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


	if (swiat.world[pos.y][pos.x] != NULL)
		kolizja(*swiat.world[pos.y][pos.x]);

}

void Czlowiek::kolizja(Organizm& other) {

		if (czyOdbilAtak(other))
			other.reallocate();

}
