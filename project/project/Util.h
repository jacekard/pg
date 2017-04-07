#ifndef UTIL_H
#define UTIL_H

#include <Windows.h>
#include <string>
#include <random>
#include <iostream>
using namespace std;

class Util {
public:
	Util() {
		SetConsoleTitle(TEXT("Wirtualny swiat-- Jacek Ardanowski 165178"));
	}
	static int los(int a, int b) {
		random_device generator;
		uniform_int_distribution<int> distribution{ a, b };
		return distribution(generator);
	}

	static void setColor(int k = 15) {
		HANDLE hConsole;
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, k);
	}
	static void hidecursor()
	{
		HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_CURSOR_INFO info;
		info.dwSize = 100;
		info.bVisible = FALSE;
		SetConsoleCursorInfo(consoleHandle, &info);
	}
	static void gotoxy(int x, int y){
		COORD coord;
		coord.X = x;
		coord.Y = y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	}
	static void clrscr()
	{
		HANDLE                     hStdOut;
		CONSOLE_SCREEN_BUFFER_INFO csbi;
		DWORD                      count;
		DWORD                      cellCount;
		COORD                      homeCoords = { 0, 0 };

		hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
		if (hStdOut == INVALID_HANDLE_VALUE) return;

		/* Get the number of cells in the current buffer */
		if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return;
		cellCount = csbi.dwSize.X *csbi.dwSize.Y;

		/* Fill the entire buffer with spaces */
		if (!FillConsoleOutputCharacter(
			hStdOut,
			(TCHAR) ' ',
			cellCount,
			homeCoords,
			&count
			)) return;

		/* Fill the entire buffer with the current colors and attributes */
		if (!FillConsoleOutputAttribute(
			hStdOut,
			csbi.wAttributes,
			cellCount,
			homeCoords,
			&count
			)) return;
	}
	static void gameOver(int turnCount, int OrganismCount, string ostatni_komunikat) {
		gotoxy(0, 0);
		clrscr();
		setColor(4);
		cout << endl;
		cout << "   @@@@@@@@   @@@@@@   @@@@@@@@@@   @@@@@@@@     @@@@@@   @@@  @@@  @@@@@@@@  @@@@@@@" << endl;
		cout << "  @@@@@@@@@  @@@@@@@@  @@@@@@@@@@@  @@@@@@@@    @@@@@@@@  @@@  @@@  @@@@@@@@  @@@@@@@@" << endl;
		cout << "  !@@        @@!  @@@  @@! @@! @@!  @@!         @@!  @@@  @@!  @@@  @@!       @@!  @@@" << endl;
		cout << "  !@!        !@!  @!@  !@! !@! !@!  !@!         !@!  @!@  !@!  @!@  !@!       !@!  @!@ " << endl;
		cout << "  !@! @!@!@  @!@!@!@!  @!! !!@ @!@  @!!!:!      @!@  !@!  @!@  !@!  @!!!:!    @!@!!@!" << endl;
		cout << "  !!! !!@!!  !!!@!!!!  !@!  !  !@!  !!!!!:      !@!  !!!  !@!  !!!  !!!!!:    !!@!@!" << endl;
		cout << "  :!!   !!:  !!:  !!!  !!:     !!:  !!:         !!:  !!!  :!:  !!:  !!:       !!: :!!" << endl;
		cout << "  :!:   !::  :!:  !:!  :!:     :!:  :!:         :!:  !:!   ::!!:!   :!:       :!:  !:!" << endl;
		cout << "   ::: ::::  ::   :::  :::     ::   :: ::::     ::::: ::    ::::    :: ::::   ::   ::: " << endl;
		cout << "   :: :: :    :   : :   :      :    : :: ::      : :  :      :      : :: ::    :   : : " << endl;
		cout << endl;
		cout << endl;


		setColor(14);
		cout << " *** " + ostatni_komunikat + " ***";
		cout << endl;
		cout << endl;
		setColor(12);
		cout << " * Udalo ci sie przezyc " << turnCount << " tur" << endl;
		cout << " * Liczba stworzen na mapie: " << OrganismCount << endl;
		cout << endl;
	}
};

#endif