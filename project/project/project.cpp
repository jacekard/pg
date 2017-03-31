#include "Swiat.h"
int main() {

	Swiat swiat;

	char zn = '1';
	do {
		
		swiat.wykonajTure();
		
		system("cls");
	} while (zn != 'q');
	
	system("pause");
}