#include "Roslina.h"
#include "Swiat.h"

Roslina::Roslina(int s, int i, char sy, int c, int w, string r, Swiat& sw)
: Organizm(s, i, sy, c, w, r, sw) {
}



void Roslina::kolizja(Organizm& other) {

}

bool Roslina::validPosY(int y) {
	if (y < swiat.HEIGHT)
		return true;
	else return false;
}
bool Roslina::validPosX(int x) {
	if (x < swiat.WIDTH)
		return true;
	else return false;
}

Roslina::~Roslina() {

}