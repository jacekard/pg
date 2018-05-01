#include "Timer.hpp"
#include <iostream>
#include <cmath>

#define N 5000
double A[N][N];
double b[N];
const double eps = 1e-12;

double calcRes_norm(double x[]) {
	double *res = new double[N];
	for (int i = 0; i < N; i++) {
		res[i] = -b[i];
		for (int k = 0; k < N; k++) {
			res[i] += A[i][k] * x[k];
		}
	}

	double res_norm = 0.0;
	for (int i = 0; i < N; i++) {
		res_norm += res[i] * res[i];
	}

	return sqrt(res_norm);
}

void initializeA() {
	//zadanie A
	int a1 = 6;
	int a2 = -1, a3 = -1;
	int f = 5;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j) A[i][j] = a1;
			else if ((i - 1 == j) || (j - 1 == i)) A[i][j] = a2;
			else if ((i - 2 == j) || (j - 2 == i)) A[i][j] = a3;
			else A[i][j] = 0.0;
		}
	}

	for (int i = 0; i < N; i++) {
		b[i] = sin(i*(f + 1));
	}
}

void initializeC() {
	//zadanie A
	int a1 = 3;
	int a2 = -1, a3 = -1;
	int f = 5;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j) A[i][j] = a1;
			else if ((i - 1 == j) || (j - 1 == i)) A[i][j] = a2;
			else if ((i - 2 == j) || (j - 2 == i)) A[i][j] = a3;
			else A[i][j] = 0.0;
		}
	}

	for (int i = 0; i < N; i++) {
		b[i] = sin(i*(f + 1));
	}
}

//returns number of iterations
int Jacobi() {
	//Metoda Jacobiego
	double x1[N];
	double x2[N];

	for (int i = 0; i < N; i++) {
		x1[i] = 1.0;
		x2[i] = 1.0;
	}

	double ans = 0.0;
	int k = 0;
	do {
		for (int i = 0; i < N; i++) {
			double sum1 = 0, sum2 = 0;
			for (int j = 0; j <= i - 1; j++) {
				sum1 += A[i][j] * x1[j];
			}
			for (int j = i + 1; j < N; j++) {
				sum2 += A[i][j] * x1[j];
			}
			x2[i] = (b[i] - sum1 - sum2) / A[i][i];
		}
		for (int i = 0; i < N; i++)
			x1[i] = x2[i];
		ans = calcRes_norm(x1);
		//cout << ans << endl;
		k++;
	} while (ans >= 1e-9);

	return k;
}

//returns number of iterations
int Gauss() {
	//Metoda Gaussa-Seidela
	double x[N];
	for (int i = 0; i < N; i++) {
		x[i] = 1.0;
	}

	double ans = 0.0;
	int k = 0;
	do {
		for (int i = 0; i < N; i++) {
			double sum1 = 0, sum2 = 0;
			for (int j = 0; j <= i - 1; j++) {
				sum1 += A[i][j] * x[j];
			}
			for (int j = i + 1; j < N; j++) {
				sum2 += A[i][j] * x[j];
			}
			x[i] = (b[i] - sum1 - sum2) / A[i][i];
		}
		ans = calcRes_norm(x);
		//cout << ans << endl;
		k++;
	} while (ans >= 1e-9);
	return k;
}

// LU distribution of matrix A
bool lu_dist() {
	int i, j, k;

	for (k = 0; k < N - 1; k++) {
		if (fabs(A[k][k]) < eps) return false;

		for (i = k + 1; i < N; i++)
			A[i][k] /= A[k][k];

		for (i = k + 1; i < N; i++)
			for (j = k + 1; j < N; j++)
				A[i][j] -= A[i][k] * A[k][j];
	}

	return true;
}

bool lusolve() {
	int    i, j;
	double s;
	double X[N];
	X[0] = b[0];

	for (i = 1; i < N; i++) {
		s = 0;
		for (j = 0; j < i; j++)
			s += A[i][j] * X[j];

		X[i] = b[i] - s;
	}

	if (fabs(A[N - 1][N - 1]) < eps)
		return false;

	X[N - 1] /= A[N - 1][N - 1];

	for (i = N - 2; i >= 0; i--) {
		s = 0;

		for (j = i + 1; j < N; j++)
			s += A[i][j] * X[j];

		if (fabs(A[i][i]) < eps)
			return false;

		X[i] = (X[i] - s) / A[i][i];
	}

	cout << "Norma residuum: " << calcRes_norm(X) << endl;
	return true;
}


int main() {
	Timer t;

	//Zadanie A
	initializeA();

	//Zadanie B
	//cout << "Zadanie B - porownanie czasow\n" << endl;
	//cout << "Metoda Jacobiego:" << endl;
	//t.start();
	//cout << "Liczba iteracji: " << Jacobi() << endl;
	//cout << "Czas: " << t.end() << endl;

	////Metoda Gaussa-Seidela:
	//cout << "\nMetoda Gaussa-Seidela: " << endl;
	//t.start();
	//cout << "Liczba iteracji: " << Gauss() << endl;;
	//cout << "Czas: " << t.end() << endl;

	////Zadanie C
	//initializeC();
	//cout << "\nZadanie C - zbieznosc algorytmow\n" << endl;
	//cout << "Liczba iteracji (Jacobi): " << Jacobi() << endl;
	//cout << "Liczba iteracji (Gauss-Seidel): " << Gauss() << endl;

	//Zadanie D
	//initializeC();
	//cout << "\nMetoda Faktoryzacji LU: " << endl;
	//lu_dist();
	//lusolve();


	////Zadanie E
	cout << "Zadanie B - porownanie czasow\n" << endl;
	cout << "Metoda Jacobiego:" << endl;
	t.start();
	cout << "Liczba iteracji: " << Jacobi() << endl;
	cout << "Czas: " << t.end() << endl;

	//Metoda Gaussa-Seidela:
	cout << "\nMetoda Gaussa-Seidela: " << endl;
	t.start();
	cout << "Liczba iteracji: " << Gauss() << endl;;
	cout << "Czas: " << t.end() << endl;

	cout << "\nMetoda Faktoryzacji LU: " << endl;
	t.start();
	lu_dist();
	lusolve();
	cout << "Czas: " << t.end() << endl;

	system("pause");
}