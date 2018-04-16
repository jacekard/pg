#include <iostream>
#include <time.h>
#define N 1000000
#define M 64
unsigned int l[N];
unsigned int n[N];
unsigned int p[N];
unsigned int wyniki1[M];
unsigned int wyniki2[M];
unsigned int wyniki3[M];
unsigned int wyniki4[M];


void generator_liniowy() {
	int a = 69069, c = 13;
	l[0] = (a*time(NULL) + c) % M;

	for (int i = 1; i < N; i++) {
		l[i] = (a * l[i - 1] + c) % M;
		wyniki1[l[i]] += 1;
	}
	for (int i = 0; i < M; i++) {
		std::cout << i << " : " << wyniki1[i] << std::endl;
	}
	return;
}


void generator_kwadratowy(int a, int b, int c) {
	unsigned int x = time(NULL);
	n[0] = (a*x*x + b * x + c) % M;

	for (int i = 1; i < N; i++) {
		x = n[i - 1];
		n[i] = (a*x*x + b * x + c) % M;
		wyniki2[n[i]] += 1;
	}

	for (int i = 0; i < M; i++) {
		//if (wyniki2[i] > 10000 && wyniki2[i] < 25000) {
			//std::cout << a << " " << b << " " << c << std::endl;
		std::cout << i << " : " << wyniki2[i] << std::endl;
		//}
	}

	return;
}

void generator_rejestr_przesuwny() {
	unsigned o = 2137420;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < sizeof(int) * 8; ++j) {
			int pom = !((1 << 7) & o) ^ !((1 << 13) & o);
			o <<= 1;
			o |= pom;
		}
		wyniki3[o % 64] += 1;
	}

	for (int i = 0; i < M; i++) {
		//if (wyniki2[i] > 10000 && wyniki2[i] < 25000) {
		std::cout << i << " : " << wyniki3[i] << std::endl;
		//}
	}

	return;
}

void funkcja_losowa(int x1, int x2) {
	int a = 69069, c = 13;
	unsigned x = (a * time(NULL) + c) % (x2 - x1) + x1;
	for (int i = 1; i < N; i++) {
		x = (a * x + c) % (x2 - x1) + x1;
		wyniki4[x] += 1;
	}

	for (int i = 0; i < M; i++) {
		std::cout << i << " : " << wyniki4[i] << std::endl;
	}
}

int main() {
	//generator_liniowy();
	//std::cout << std::endl;
	//for (int i = 10; i < 20; i++) {
	//	for (int j = 10; j < 20; j++) {
	//		for (int k = 10; k < 20; k++) {
					//generator_kwadratowy(10, 11, 11);
	//		}
	//	}
	//}

	//generator_rejestr_przesuwny();

	funkcja_losowa(10, 15);

	system("pause");
}
