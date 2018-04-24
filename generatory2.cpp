#include <cmath>
#include <iostream>
#define MIL 1000000
using namespace std;
long long  int potega(int n, int m, long long  int wynik) {
	if (m == 0)
		return wynik;
	else
		potega(n, m - 1, wynik*n);
}
long long  int potega(int n, int m) {
	if (m == 0)
		return 1;
	else
		potega(n, m - 1, n);
}
void generator1() {
	int c = 1;
	int a = 69069;
	long long  int M = potega(2,6) ;

	long long int *tab = new long long int[MIL];
	tab[0] = 31;

	for (int i = 1; i < MIL; i++) {
		tab[i] = ((tab[i - 1] * a) + c) % M;
	}

	int zlicz[64];
	for (int i = 0; i < 64; i++)
		zlicz[i] = 0;

	for (int i = 0; i < MIL; i++)
		for (int j = 0; j <= 63; j++)
			if (tab[i] == j)
			{
				zlicz[j]++;
				break;
			}
	cout << "Generator liniowy" << endl;
	for (int i = 0; i <= 63; i++) {
		cout << i << " wolosowane " << zlicz[i] << " razy" << endl;
			}

	cout << "------------------------------" << endl;

}
void generator2() {
	int c = 1;
	int a = 4;
	int b = 13;
	long long  int M = potega(2, 6);

	long long int *tab = new long long int[MIL];
	tab[0] = 1;

	for (int i = 1; i < MIL; i++) {
		tab[i] = ((potega(tab[i - 1],2)*a) + (b*tab[i - 1])+ c) % M;
	}

	int zlicz[64];
	for (int i = 0; i < 64; i++)
		zlicz[i] = 0;

	for (int i = 0; i < MIL; i++)
		for (int j = 0; j <= 63; j++)
			if (tab[i] == j)
			{
				zlicz[j]++;
				break;
			}
	cout << "Generator nieliniowy" << endl;
	for (int i = 0; i <= 63; i++) {
		cout << i << " -> " << zlicz[i] << endl;
	
	}
	cout << "------------------------------" << endl;
}
void generator3() {
	long long  int M = potega(2, 6);

	int p = 7, q = 3;
	bool tab2[MIL + 32] = { 1, 1, 0, 1, 0, 0, 1 };
	unsigned long long int *licz = new unsigned long long int[MIL+32];
	long long  int *zlicz2=new long long int [64] ;
	for (int i = 0; i < MIL+32 ; i++) {
		licz[i] = 0;
	}
	for (int i = 0; i < 64; i++)
		zlicz2[i] = 0;

	for (int i = 0; i < MIL + 32; i++)
		tab2[i] = !(tab2[i - p] == tab2[i - q]); //xor
	
	for (int i = 0; i < MIL+32; i++)
		{
			for (int j = 0; j < 32; j++)
				if (tab2[i + j])
					licz[i] += potega(2,j);	
			licz[i] %= M;
		}
	
		for (int i = 0; i < MIL; i++)
			for (int j = 0; j < 64; j++)

				if (licz[i] == j)
				{
					zlicz2[j]++;
					break;
				}
		zlicz2[0] = zlicz2[0] * 2;
		cout << "Generator na rejestrach przesuwnych" << endl;
		for (int i = 0; i < 64; i++) {
			cout << i << " wolosowane " << zlicz2[i] << " razy" << endl;
			
		}
	
}
void generator(int a, int b) {
	
	int c = 16;
	int A = 69069;
	long long  int M = potega(2, 6);

	long long int *tab = new long long int[MIL];
	tab[0] = 31;

	for (int i = 1; i < MIL; i++) {
		tab[i] = ((((tab[i - 1] * A) + c) % M));
	}
	for (int i = 1; i < MIL; i++) {
		tab[i] = (tab[i] * (b - a + 1)) / M + a;
	}
	int *zlicz=new int[b-a+1];
	for (int i = 0; i <= b-a; i++)
		zlicz[i] = 0;

	
	for (int i = 0; i < MIL; i++)
		for (int j = 0; j <= b-a; j++)
			if (tab[i] == j+a)
			{
				zlicz[j]++;
				break;
			}

	cout << "Generator liczb od " << a << " do " << b << endl;
	for (int i = 0; i <=b-a; i++) {
		cout << i+a << " wolosowane " << zlicz[i] << " razy" << endl;
	}
	cout << "------------------------------" << endl;

}
int main()
{
	
	//generator1();
	//generator2();
	//generator3();
	
	generator(10,11);

	system("pause");
	return 0;
}
