#include "Zwierze.h"
#include "Swiat.h"

Zwierze::Zwierze(int s, int i, char sy, int c, int w, string r, Swiat& sw)
: Organizm(s, i, sy, c, w, r, sw) {
}

bool Zwierze::czyOdbilAtak(Organizm& atakujacy) {
	return false;
}

bool Zwierze::czyRozmnazanie(Organizm& other) {
	if (rodzaj == other.getRodzaj()) {
		if (Util::los(1, 3) == 1) {
			if (other.getWiek() > 15 && this->wiek > 15)
				return true;
		}
	}
	return false;
}

void Zwierze::kolizja(Organizm& other) {
	if (&other == this) return;
	string rodzaj = other.getRodzaj();
	if (czyRozmnazanie(other))
		this->rozmnazanie();
	else if (!czyOdbilAtak(other)) {
		if (other.getSila() >= sila) {
			if (rodzaj == "CZLOWIEK")
				swiat.komentuj(" + " + this->rodzaj + " ginie z reki " + rodzaj + "A! + ");
			else
				swiat.komentuj(" + " + this->rodzaj + " ginie w paszczy " + rodzaj + "! + ");
			swiat.world[pos.y][pos.x] = &other;
			swiat.world[other.getOldPosy()][other.getOldPosx()] = NULL;
			this->die();
		}
		else {
			if (this->rodzaj == "CZLOWIEK")
				swiat.komentuj(" + " + rodzaj + " ginie z reki " + this->rodzaj + "A! + ");
			else
				swiat.komentuj(" + " + rodzaj + " ginie w paszczy " + this->rodzaj + "A! + ");
			swiat.world[other.getOldPosy()][other.getOldPosx()] = NULL;
			other.die();
		}
	}
}

void Zwierze::akcja() {
	//dodaj wiek;
	grow();

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
	else {
		swiat.world[old_pos.y][old_pos.x] = NULL;
		swiat.world[pos.y][pos.x] = this;
	}

}

Zwierze::~Zwierze() {

};