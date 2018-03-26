#include <iostream>
#include <windows.h>

using namespace std;

#pragma argsused
#define N 5000
struct dane_dla_watku // tablica zawiera dane, ktore otrzymaja wątki
{
	char nazwa[50];
	int parametr;
} dane[3] = { { "[1]", 5 },{ "[2]", 8 },
{ "[3]", 12 } };

// priorytety wątków
int priorytety[N] = { THREAD_PRIORITY_BELOW_NORMAL,
	THREAD_PRIORITY_NORMAL, THREAD_PRIORITY_ABOVE_NORMAL
};

// dojścia (uchwyty) wątków
HANDLE watki[N];
// deklaracja funkcji wątku
DWORD WINAPI funkcja_watku(void *argumenty);

int main(int argc, char **argv)
{
	int i;
	DWORD id; // identyfikator wątku
	//system("cls");
	printf("Uruchomienie programu\n");
	// tworzenie wątków

	for (i = 0; i < N; i++)
	{
		watki[i] = CreateThread(
			NULL, // atrybuty bezpieczeństwa
			0, // inicjalna wielkość stosu
			funkcja_watku, // funkcja wątku
			(void *)&dane[0],// dane dla funkcji wątku
			0, // flagi utworzenia
			&id);
		if (watki[i] != INVALID_HANDLE_VALUE)
		{
			printf("Utworzylem watek %d o identyfikatorze %x\n",
				i, id);
			// ustawienie priorytetu
			SetThreadPriority(watki[i], THREAD_PRIORITY_ABOVE_NORMAL);
		}
		if (watki[i] == NULL) {
			system("pause");
			break;
		}
	}
	Sleep(20000); // uśpienie wątku głównego na 20 s
	return 0;
}


DWORD WINAPI funkcja_watku(void *argumenty)
{
	unsigned int licznik = 0;
	// rzutowanie struktury na własny wskaźnik
	struct dane_dla_watku *moje_dane = (struct dane_dla_watku *)argumenty;
	// wyświetlenie informacji o uruchomieniu
	//gotoxy(1, moje_dane->parametr);
	//printf("%s", moje_dane->nazwa);
	Sleep(10000);
	// praca, wątki sa terminowane przez zakończenie programu
	// - funkcji main
	return 0;
}
