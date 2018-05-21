#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#define ODCZYT 0
#define ZAPIS 1
void savePipe(const char* pipe, char bufor[], int size);
void loadPipe(const char* pipe, char bufor[], int size);
void modifyString(char* tab, int size);

int main() {
    char pipe1[] = "./pipe1";
    char pipe2[] = "./pipe2";
    mkfifo(pipe1, 0666);
    mkfifo(pipe2, 0666); //prawa 
    char bufor[255];

    if (fork()) {
        // zapisanie ciagu znakow
        scanf("%s", bufor);
        savePipe(pipe1, bufor, sizeof(bufor));

    } else {
        if (fork() == 0) {
            // modyfikowanie ciagu znakow
            char bufor2[255];
            loadPipe(pipe1, bufor2, sizeof(bufor2));
            modifyString(bufor2, 255);
            savePipe(pipe2, bufor2, sizeof(bufor2));
        }
        // odczytanie
        char bufor3[255];
        loadPipe(pipe2, bufor3, sizeof(bufor3));
        printf("%s\n", bufor3);
    }
    return 0;
}

void modifyString(char* tab, int size) {
    for (int i = 0; i < size; ++i) {
        if (tab[i] >= 'a' && tab[i] <= 'z') {
            tab[i] = tab[i] - 'a' + 'A';
        }
    }
}

void savePipe(const char* pipe, char bufor[], int size) {
    int f = open(pipe, O_WRONLY);
    write(f, bufor, size);
    close(f);
}

void loadPipe(const char* pipe, char bufor[], int size) {
    int f = open(pipe, O_RDONLY);
    read(f, bufor, size);
    close(f);
}
