#include "Swiat.h"

Swiat::Swiat() {
	Util::hidecursor();
	turnCount = 0;
	czyKoniec = false;
	czySave = false;
	czyLoad = false;
	czyRespawn = false;
	tarczaAlzura = false;
	int LICZBA_ZWIERZAT = 0;
	int LICZBA_ROSLIN = 3;

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

	for (int k = 0; k < LICZBA_ZWIERZAT; k++) {
		lista.push_back(new Wilk(*this));
		lista.push_back(new Antylopa(*this));
		lista.push_back(new Owca(*this));
		lista.push_back(new Zolw(*this));
		lista.push_back(new Lis(*this));
	}
	for (int k = 0; k < LICZBA_ROSLIN; k++) {
		lista.push_back(new Trawa(*this));
		//lista.push_back(new Mlecz(*this));
		//lista.push_back(new Trawa(*this));
		//lista.push_back(new Mlecz(*this));
		//lista.push_back(new Guarana(*this));
		//lista.push_back(new Jagody(*this));
		//lista.push_back(new Barszcz(*this));

	}
	lista.push_back(new Czlowiek(*this));


	sortujInicjatywa();
}

Swiat::~Swiat() {
	int listaobiektow = lista.size();
	lista.erase(lista.begin(), lista.end());
	listaobiektow = lista.size();
	for (int y = 1; y < HEIGHT; y++) {
		for (int x = 1; x < WIDTH; x++) {
			delete world[y][x];
		}
	}
}

void Swiat::Rysuj() {
	rysujInterfejs();
	//listaGatunkow();
	rysujMape();
}

void Swiat::wykonajTure() {

	if (czySave) save();
	if (czyLoad) load();
	if (czyRespawn) respawn();
	int x, y;
	string a;
	
	randomPlants();
	lista.shrink_to_fit();
	for (int i = 0; i < lista.size(); i++) {
		y = lista[i]->getPosy();
		x = lista[i]->getPosx();
		a = lista[i]->getRodzaj();
		lista[i]->akcja();
		world[y][x] = NULL;
		if (i == lista.size()) break;
		world[lista[i]->getPosy()][lista[i]->getPosx()] = lista[i];
	}

	if (turnCount >= 500 - 1) {
		komentuj("Zakonczono symulacje!");
		czyKoniec = true;
	}
	turnCount++;

	Rysuj();

}

void Swiat::randomPlants() {
	//randomowe rozsiewanie: (dla guarany, wilczych jagod i barszczu sosnowskiego)
	if (Util::los(1, 200) == 1)
		lista.push_back(new Guarana(*this));
	if (Util::los(1, 200) == 2)
		lista.push_back(new Jagody(*this));
	if (Util::los(1, 200) == 3)
		lista.push_back(new Barszcz(*this));
}

void Swiat::rysujInterfejs() {
	Util::setColor();
	pos.x = 0;
	pos.y = 0;
	for (int x = 0; x < 2; x++) {
		for (int i = 0; i <= WIDTH; i++) {
			Util::gotoxy(pos.x, pos.y);
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
			Util::gotoxy(pos.x, pos.y);
			cout << "|";
			pos.y++;
		}
		pos.x = WIDTH;
		pos.y = OFFY;
	}

	int x = WIDTH + OFFX;
	int y = 0;
	Util::gotoxy(x, y);
	cout << "+ + + + + + + + + + + + + + + + + + +";
	Util::gotoxy(x, ++y);
	cout << "Tura nr " << turnCount;
	Util::gotoxy(x + 13, y);
	if (tarczaAlzura) {
		Util::setColor(14);
		cout << "Tarcza Alzura: ";
		Util::setColor(10);
		printf("%c", 254);
	}
	else {
		Util::setColor(14);
		cout << "Tarcza Alzura: ";
		Util::setColor(12);
		printf("%c", 254);
	}
	++y;
}

void Swiat::rysujMape() {
	for (int y = 1; y < HEIGHT; y++) {
		for (int x = 1; x < WIDTH; x++) {
			if (world[y][x] != NULL)
				world[y][x]->rysowanie();
			else {
				Util::gotoxy(x, y);
				printf(" ");
			}
		}
	}
}

void Swiat::listaGatunkow() {
	int pom = 0;
	int x = WIDTH + OFFX;
	int y = 12;
	Util::gotoxy(x, y);
	cout << "lista organizmow: ";
	y++;
	for (int i = 0; i < lista.size(); i++) {
		Util::gotoxy(x, y + i);
		cout << i + 1 << ". " << lista[i]->getRodzaj() << ", ";
		pom = i;
	}
}

void Swiat::komentuj(string komunikat) {
	komunikaty.push_back(komunikat);
}

void Swiat::wypiszKomunikaty(int x, int y) {
	Util::setColor(13);
	Util::gotoxy(x, ++y);
	cout << "Komunikaty: ";
	Util::setColor(11);
	Util::gotoxy(x, ++y);
	cout << "                                                       ";
	if (komunikaty.size() == 0) {
		Util::gotoxy(x, y);
		cout << "Brak nowych komunikatow";
	}

	for (int i = 0; i < HEIGHT; i++) {
		Util::gotoxy(WIDTH+1, y+1+i);
		cout << "                                                   ";

	}

	for (auto v : komunikaty) {
		Util::gotoxy(x, y);
		Util::setColor(Util::los(14,16));
		cout << v;
	}
	while (!komunikaty.empty())
	{
		komunikaty.pop_back();
	}

	Util::setColor();
}

void Swiat::sortujInicjatywa() {
	sort(lista.begin(), lista.end(), [](Organizm* a, Organizm* b) {
		if (a->getInicjatywa() == b->getInicjatywa())
			return a->getWiek() > b->getWiek();
		return a->getInicjatywa() > b->getInicjatywa();
	});
}

void Swiat::save() {
	czySave = false;

	char b[4];
	ofstream plik;
	plik.open("Saves/save.txt");

	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; x < WIDTH; x++) {
			if (world[y][x] == NULL) plik << ".";
			else if (world[y][x]->getRodzaj() == "CZLOWIEK") plik << "c";
			else if (world[y][x]->getRodzaj() == "WILK") plik << "w";
			else if (world[y][x]->getRodzaj() == "OWCA") plik << "o";
			else if (world[y][x]->getRodzaj() == "LIS") plik << "l";
			else if (world[y][x]->getRodzaj() == "ZOLW") plik << "z";
			else if (world[y][x]->getRodzaj() == "ANTYLOPA") plik << "a";
			else if (world[y][x]->getRodzaj() == "TRAWA") plik << "t";
			else if (world[y][x]->getRodzaj() == "MLECZ") plik << "m";
			else if (world[y][x]->getRodzaj() == "GUARANA") plik << "g";
			else if (world[y][x]->getRodzaj() == "JAGODY") plik << "j";
			else if (world[y][x]->getRodzaj() == "BARSZCZ") plik << "b";
		}
		plik << endl;
	}
	if (tarczaAlzura) plik << "1 ";
	else plik << "0 ";

	plik << turnCount - 1;

	plik.close();

	komentuj("Zapisano gre!");

}

void Swiat::load() {
	czyLoad = false;
	Util::clrscr();
	Util::gotoxy(0, 0);
	lista.erase(lista.begin(), lista.end());
	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; x < WIDTH; x++) {
			world[y][x] = NULL;
		}
	}


	char n;
	int x0 = 0;
	int y0 = 0;
	int a = 0, b = 0;
	FILE *plik = fopen("Saves/save.txt", "r");
	while (y0 != HEIGHT) {
		fscanf(plik, "%c", &n);
		if (n == '\n') {
			x0 = -1;
			++y0;
		}
		if (n == 'c') lista.push_back(new Czlowiek(*this, x0, y0));
		else if (n == 'w') lista.push_back(new Wilk(*this, x0, y0));
		else if (n == 'a') lista.push_back(new Antylopa(*this, x0, y0));
		else if (n == 'o') lista.push_back(new Owca(*this, x0, y0));
		else if (n == 'z') lista.push_back(new Zolw(*this, x0, y0));
		else if (n == 'l') lista.push_back(new Lis(*this, x0, y0));
		else if (n == 'g') lista.push_back(new Guarana(*this, x0, y0));
		else if (n == 't') lista.push_back(new Trawa(*this, x0, y0));
		else if (n == 'm') lista.push_back(new Mlecz(*this, x0, y0));
		else if (n == 'j') lista.push_back(new Jagody(*this, x0, y0));
		else if (n == 'b') lista.push_back(new Barszcz(*this, x0, y0));
		++x0;
	}
	fscanf(plik, "\n%d %d", &a, &b);
	if (a) tarczaAlzura = true;
	turnCount = b;
	komentuj("Wczytano gre!");
	//
	Util::clrscr();
	Rysuj();
	//
}

void Swiat::respawn() {
	czyRespawn = false;
	Util::gotoxy(1, HEIGHT + 1);
	cout << "Jakie zwierze chcesz dodac? ";
	char n;
	cin >> n;
	if (n == 'c') lista.push_back(new Czlowiek(*this));
	else if (n == 'w') lista.push_back(new Wilk(*this));
	else if (n == 'a') lista.push_back(new Antylopa(*this));
	else if (n == 'o') lista.push_back(new Owca(*this));
	else if (n == 'z') lista.push_back(new Zolw(*this));
	else if (n == 'l') lista.push_back(new Lis(*this));
	else if (n == 'g') lista.push_back(new Guarana(*this));
	else if (n == 't') lista.push_back(new Trawa(*this));
	else if (n == 'm') lista.push_back(new Mlecz(*this));
	else if (n == 'j') lista.push_back(new Jagody(*this));
	else if (n == 'b') lista.push_back(new Barszcz(*this));
	cout << " OK!";
}