#include <stdio.h>
#include <pthread.h>

#define begin 10
#define end 20
#define size end-begin

#define MAX_PRIME size
int primes[MAX_PRIME]; // tablica z liczbami pierwszymi
int curr_p = 0; // ile w tablicy jest wpisanych liczb pierwszych
pthread_mutex_t m_p; // semafor chroniący dostępu do tablicy


void *f( void *arg ) {
   int a = *(int *) arg;
 
	for(int i = 2; i*i < a; i++ ) {
		if(a % i == 0) {
			return NULL;
		}
	}
	pthread_mutex_lock( &m_p );
	primes[curr_p] = a;
	curr_p++;
	pthread_mutex_unlock( &m_p );
	return NULL;
}




int main()
{
pthread_t w[size];
int tab[size];
pthread_mutex_init(&m_p, NULL);

for(int i = begin, j = 0; i < end; i++, j++) {
	tab[j] = i;
	pthread_create( w+j, NULL, f, tab+j);
}

for(int i = 0; i < size; i++) {
	pthread_join( w[i], NULL );
}

for(int i = 0; i < size; i++) {
	if( primes[i] != 0)
	printf("%d, ", primes[i]);
}
	printf("\n");

return 0;
}