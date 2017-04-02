#include "Roslina.h"
#include "Swiat.h"

Roslina::Roslina(int s, int i, char sy, int c, int w, string r, Swiat& sw)
: Organizm(s, i, sy, c, w, r, sw) {
}



void Roslina::kolizja(Organizm& other) {
	// tutaj jesli roslina jest zabojcza to wtedy cos tam
	if (this->rodzaj == "GUARANA")
		other.setSila(other.getSila() + 3);
	else if (this->rodzaj == "JAGODY")
		other.die();
	else if (this->rodzaj == "BARSZCZ") {
		if (other.getRodzaj() != "CYBER-OWCA")
			other.die();
	}
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