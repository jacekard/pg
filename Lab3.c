#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

double pi() {
	srand(time(NULL) + getpid());
	int n = 10e7;
	int k = 0;
	double x, y;
	for(int i = 0; i < n; i++) {
		x = (double)rand()/RAND_MAX;
		y = (double)rand()/RAND_MAX;
		if( x*x + y*y <= 1) 
			k++;
	}
	double wynik = (double)(k)/n;
	return wynik*4;

}
int main() {
	for(int i = 0; i < 10; i++) {
	int pid = fork();
	  if(pid == 0) {
		printf("%f\n", pi());
		break;
	  } else {
		waitpid( pid, NULL, 0);
	    }
	}

	
	return 0;
}
