#include "Barszcz.h"
#include "Swiat.h"

Barszcz::Barszcz(Swiat& sw) : Roslina(99, 0, 'B', 11, 0, "BARSZCZ", sw) {
	allocate();
};

Barszcz::Barszcz(Swiat& sw, int x, int y) : Roslina(99, 0, 'B', 11, 0, "BARSZCZ", sw) {
	this->pos.x = x;
	this->pos.y = y;

	allocate();
}

void Barszcz::rozmnazanie() {
	Organizm *child = new Barszcz(swiat, pos.x, pos.y);
	swiat.lista.push_back(child);
	swiat.sortujInicjatywa();
}

void Barszcz::kolizja(Organizm& other) {
	if (this->getRodzaj() != "CYBER-OWCA") {
		swiat.komentuj(" + " + other.getRodzaj() + " ginie otruty przez " + rodzaj + "! + ");
		swiat.world[other.getOldPosy()][other.getOldPosx()] = NULL;
		other.die();
		swiat.world[pos.y][pos.x] = NULL;
		this->die();
	}
}

void Barszcz::akcja() {
	grow();
	Organizm* tmp;
	if (pos.y - 1 < swiat.HEIGHT - 1 && pos.y - 1 > 1) {
		tmp = swiat.world[pos.y - 1][pos.x];
		if (tmp != NULL && dynamic_cast<Zwierze*>(tmp)) {
			swiat.komentuj(" + " + tmp->getRodzaj() + " ginie przez trujace opary BARSZCZU! + ");
			swiat.world[tmp->getOldPosy()][tmp->getOldPosx()] = NULL;
			swiat.world[tmp->getPosy()][tmp->getPosx()] = NULL;
			tmp->die();
		}
	}

	if (pos.y + 1 < swiat.HEIGHT - 1 && pos.y + 1 > 1) {
		tmp = swiat.world[pos.y + 1][pos.x];
		if (tmp != NULL && dynamic_cast<Zwierze*>(tmp)) {
			swiat.komentuj(" + " + tmp->getRodzaj() + " ginie przez trujace opary BARSZCZU! + ");
			swiat.world[tmp->getOldPosy()][tmp->getOldPosx()] = NULL;
			swiat.world[tmp->getPosy()][tmp->getPosx()] = NULL;
			tmp->die();

		}
	}

	if (pos.x + 1 < swiat.WIDTH - 1 && pos.x + 1 > 1) {
		tmp = swiat.world[pos.y][pos.x + 1];
		if (tmp != NULL && dynamic_cast<Zwierze*>(tmp)) {
			swiat.komentuj(" + " + tmp->getRodzaj() + " ginie przez trujace opary BARSZCZU! + ");
			swiat.world[tmp->getOldPosy()][tmp->getOldPosx()] = NULL;
			swiat.world[tmp->getPosy()][tmp->getPosx()] = NULL;
			tmp->die();
		}
	}

	if (pos.x - 1 < swiat.WIDTH - 1 && pos.x - 1 > 1) {
		tmp = swiat.world[pos.y][pos.x - 1];
		if (tmp != NULL && dynamic_cast<Zwierze*>(tmp)) {
			swiat.komentuj(" + " + tmp->getRodzaj() + " ginie przez trujace opary BARSZCZU! + ");
			swiat.world[tmp->getOldPosy()][tmp->getOldPosx()] = NULL;
			swiat.world[tmp->getPosy()][tmp->getPosx()] = NULL;
			tmp->die();

		}
	}


	if (Util::los(1, 300) == Util::los(1, 50)) {
		if (rozsiewanie()) {
			rozmnazanie();
		}
	}
}