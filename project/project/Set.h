#ifndef SET_H
#define SET_H
#include <Windows.h>
#include <iostream>
using namespace std;

class p{
public:
	int x;
	int y;
	p() : x(0), y(0) {};
	static void setColor(int k = 15) { 
		HANDLE hConsole;
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute( hConsole, k);
	}
	static void hidecursor()
	{
		HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_CURSOR_INFO info;
		info.dwSize = 100;
		info.bVisible = FALSE;
		SetConsoleCursorInfo(consoleHandle, &info);
	}
	static void xy(int x, int y){
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
	static void gameOver() {
		p::xy(1, 1);
		cout << " @@@@@@@@   @@@@@@   @@@@@@@@@@   @@@@@@@@		 @@@@@@   @@@  @@@  @@@@@@@@  @@@@@@@   " << endl;
		cout << "@@@@@@@@@  @@@@@@@@  @@@@@@@@@@@  @@@@@@@@		@@@@@@@@  @@@  @@@  @@@@@@@@  @@@@@@@@ " << endl;
		cout << "!@@        @@!  @@@  @@! @@! @@!  @@!		      @@!  @@@  @@!  @@@  @@!       @@!  @@@  " << endl;
		cout << "!@!        !@!  @!@  !@! !@! !@!  !@!			!@!  @!@  !@!  @!@  !@!       !@!  @!@ " << endl;
		cout << "!@! @!@!@  @!@!@!@!  @!! !!@ @!@  @!!!:!		@!@  !@!  @!@  !@!  @!!!:!    @!@!!@!" << endl;
		cout << "!!! !!@!!  !!!@!!!!  !@!   ! !@!  !!!!!:		!@!  !!!  !@!  !!!  !!!!!:    !!@!@!" << endl;
		cout << ":!!   !!:  !!:  !!!  !!:     !!:  !!:			!!:  !!!  :!:  !!:  !!:       !!: :!!" << endl;
		cout << ":!:   !::  :!:  !:!  :!:     :!:  :!:			:!:  !:!   ::!!:!   :!:       :!:  !:!" << endl;
		cout << " ::: ::::  ::   :::  :::     ::    :: ::::		::::: ::    ::::     :: ::::  ::   ::: " << endl;
		cout << " :: :: :    :   : :   :      :    : :: ::		 : :  :      :      : :: ::    :   : : " << endl;
		cout << endl;
		cout << endl;
	}
};

                                            


    
       
    
    
       
       
  
   
                                            
                                        

 

 
   
    
   
  
 
 


//virtual void Wypisz(ostream& out) const = 0;
//friend ostream& operator<<(ostream& os, const Swiat& swiat);

//ostream& operator<<(ostream& os, const Swiat& swiat) {
//	swiat.Wypisz(os);
//	return os;
//}
#endif