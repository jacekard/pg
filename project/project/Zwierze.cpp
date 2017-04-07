#include "Zwierze.h"
#include "Swiat.h"

Zwierze::Zwierze(int s, int i, char sy, int c, int w, string r, Swiat& sw)
: Organizm(s, i, sy, c, w, r, sw) {
}

bool Zwierze::czyOdbilAtak(Organizm& atakujacy) {
	return false;
}

bool Zwierze::czyRozmnazanie(Organizm& other) {
	if (rodzaj == other.getRodzaj())
		return true;
	else
		return false;
}

void Zwierze::kolizja(Organizm& other) {
	if (&other == this) return;
	string rodzaj = other.getRodzaj();
	if (czyRozmnazanie(other)) {
		if (other.getWiek() > 10 && this->wiek > 10) {
			if (Util::los(1, 5) == 1)
				this->rozmnazanie();
		}
	}
	else if (czyOdbilAtak(other) == false) {
		if (other.getSila() >= sila) {
			if (rodzaj == "CZLOWIEK")
				swiat.komentuj(" + " + this->rodzaj + " ginie z reki " + rodzaj + "A! + ");
			else
				swiat.komentuj(" + " + this->rodzaj + " ginie w paszczy " + rodzaj + "! + ");

			int a = pos.x;
			int b = pos.y;
			this->die();
			swiat.world[b][a] = &other;
		}
		else {
			if (this->rodzaj == "CZLOWIEK")
				swiat.komentuj(" + " + rodzaj + " ginie z reki " + this->rodzaj + "A! + ");
			else
				swiat.komentuj(" + " + rodzaj + " ginie w paszczy " + this->rodzaj + "A! + ");
			int a = other.getPosx();
			int b = other.getPosy();
			other.die();
			swiat.world[b][a] = &other;
		}
	}
}

void Zwierze::akcja() {
	point tmp = ruch();
	/*tmp.x = 0;
	tmp.y = 0;*/
	if (pos.x + tmp.x > swiat.WIDTH - 1 || pos.x + tmp.x < 1)
		tmp.x = 0;
	if (pos.y + tmp.y > swiat.HEIGHT - 1 || pos.y + tmp.y < 1)
		tmp.y = 0;

	old_pos = pos;
	//aktualizuj pozycje
	pos.x += tmp.x;
	pos.y += tmp.y;

	if (swiat.world[pos.y][pos.x] != NULL
		&& swiat.world[pos.y][pos.x] != this)
		swiat.world[pos.y][pos.x]->kolizja(*this);

	//dodaj wiek;
	grow();
}

Zwierze::~Zwierze() {

};