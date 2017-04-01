#include "Swiat.h"

Swiat::Swiat() {
	p::hidecursor();
	turnCount = 0;
	czyKoniec = false;
	int LICZBA_STWOROW = 5;


	komunikaty.push_back("Nowa gra!");


	world = new Organizm**[HEIGHT];

	for (int i = 0; i < HEIGHT; i++) {
		world[i] = new Organizm*[WIDTH];
	}
	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; x < WIDTH; x++) {
			world[y][x] = NULL;
		}
	}



	for (int k = 0; k < LICZBA_STWOROW; k++) {
		lista.push_back(new Wilk(*this));
		lista.push_back(new Trawa(*this));
	}
	lista.push_back(new Czlowiek(*this));



	sortujInicjatywa();

	for (int i = 0; i < lista.size(); i++) {
		//if (world[lista[i]->getPosy()][lista[i]->getPosx()] == NULL)
		
		//problem z respawnem w tym samym miejscu!
	}
}

Swiat::~Swiat() {
	lista.erase(lista.begin(), lista.end());

	//delete caly world
}

void Swiat::Rysuj() {
	rysujInterfejs();
	listaGatunkow();
	rysujMape();
	p::xy(54, 2);

}

void Swiat::wykonajTure() {
	/* */
	Rysuj();
	/* */
	int x, y;
	string a;
	for (int i = 0; i < lista.size(); i++) {
		y = lista[i]->getPosy();
		x = lista[i]->getPosx();
		a = lista[i]->getRodzaj();
		lista[i]->akcja();
		world[y][x] = NULL;
		world[lista[i]->getPosy()][lista[i]->getPosx()] = lista[i];
	}

	turnCount++;
}

void Swiat::rysujInterfejs() {
	p::setColor();
	pos.x = 0;
	pos.y = 0;
	for (int x = 0; x < 2; x++) {
		for (int i = 0; i <= WIDTH; i++) {
			p::xy(pos.x, pos.y);
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
			p::xy(pos.x, pos.y);
			cout << "|";
			pos.y++;
		}
		pos.x = WIDTH;
		pos.y = OFFY;
	}

	int x = WIDTH + OFFX;
	int y = 0;
	p::xy(x, y);
	cout << "- - - - - - - - - - - -";
	p::xy(x, y++);
	cout << "Jacek Ardanowski 165178";
	p::xy(x, y++);
	cout << "Tura nr " << turnCount;
	p::xy(x, y++);
	cout << "Komunikaty: ";
	wypiszKomunikaty(x, y);
}

void Swiat::rysujMape() {
	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; x < WIDTH; x++) {
			if (world[y][x] != NULL) {
				world[y][x]->rysowanie();
				//tutaj jest problem z traw¹
				/*if (world[y][x]->getRodzaj() != "CZLOWIEK")
					komentuj("TU JEST COS INNEGO NIZ CZLOWIEK");*/
			}
			else
				p::xy(x, y);
			//	printf("%c", 177);
		}
	}
}

void Swiat::listaGatunkow() {
	int pom = 0;
	int x = WIDTH + OFFX;
	int y = 6;
	p::xy(x, y);
	cout << "lista organizmow: ";
	y++;
	for (int i = 0; i < lista.size(); i++) {
		p::xy(x, y + i);
		//if (lista[i]->getRodzaj() != "TRAWA")
		cout << i + 1 << ". " << lista[i]->getRodzaj() << ", ";
		pom = i;
	}
}

int Swiat::losuj(int a, int b) {
	random_device generator;
	uniform_int_distribution<int> distribution{ a, b };
	return distribution(generator);
}

void Swiat::komentuj(string komunikat) {
	komunikaty.push_back(komunikat);
}

void Swiat::wypiszKomunikaty(int x, int y) {
	p::setColor(11);
	if (komunikaty.size() == 0) {
		p::xy(x, y);
		cout << "Brak nowych komunikatow";
	}
	for (auto v : komunikaty) {
		p::xy(x, y++);
		cout << v;
	}
	p::setColor();
	while (!komunikaty.empty())
	{
		komunikaty.pop_back();
	}
}

void Swiat::sortujInicjatywa() {
	sort(lista.begin(), lista.end(), [](Organizm* a, Organizm* b) {
		return a->getInicjatywa() > b->getInicjatywa();
	});
}