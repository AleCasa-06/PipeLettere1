#include <stdio.h>
#include <unistd.h>
#include "sys/wait.h"
#include <stdlib.h>
#include "ctype.h"

int main() {




    int tot[26] = {};
    char carattLetto;
    char carattRicevuto;

    int fd[2];
    int id = fork();
    int lettere[26] = {0};

    if(id == 0){
        //siamo nel figlio
        close(fd[0]);
        FILE *ft = fopen("C:\\Users\\casar\\Desktop\\Itis Rossi\\ProgettiC\\eseParolePipe\\Mattarella.txt", "r");

        carattLetto = fgetc(ft);

        while( carattLetto != EOF){
            write(fd[1],  &carattLetto, sizeof carattLetto);

        }

    }
    else{
        //siamo nel padre
        close(fd[1]);
        while( read(fd[0], &carattRicevuto, sizeof carattRicevuto)!= EOF){
            carattRicevuto = tolower(carattRicevuto);
            lettere[carattRicevuto - 'a']++;


        }

    }
    for(int i = 0; i < 26; i++){
        printf("%c: %d \n", 'a' + i, lettere[i]);
    }

    wait(NULL);



}
