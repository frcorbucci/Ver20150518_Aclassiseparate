#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//dichiaro le costanti
#define MAX_CARAT 25
#define MAX_NUMFIL 255
#define N 2

//dichiaro il record

struct s_studente {
    char nome[MAX_CARAT + 1];
    char cognome[MAX_CARAT + 1];
    char classe[MAX_CARAT + 1];
    char sesso[MAX_CARAT + 1];
    unsigned int eta;
};

//dichiaro 'studente' come s_studente
typedef struct s_studente studente;

int main(int argc, char** argv) {

    //dicharo le variabili
    FILE *Maschi, *Femmine;
    int i, k;
    int o, h = 0;
    char ses;
    studente t[N], c[N], temp;
    studente *p;
    char stdMin = 0;



    for (i = 0; i < N; i++) {
        printf("Inserisci il sesso: ");
        scanf("%s.\n", (t[i].sesso));

        strcmp(t[i].sesso, 'm');
        if (!t[i].sesso == 0) {
            if (h < 1) {
                Maschi = fopen("maschi.csv", "w");
                h++;
            }

            printf("\nInserisci il nome: ");
            scanf("%s.\n", (t[i].nome));
            fprintf(Maschi, "%s", t[i].nome);
            printf("Inserisci il cognome: ");
            scanf("%s.\n", (t[i].cognome));
            fprintf(Maschi, "%s", t[i].cognome);
            printf("Inserisci la classe: ");
            scanf("%s.\n", (t[i].classe));
            fprintf(Maschi, "%s", t[i].classe);
            printf("Inserisci l'eta: ");
            scanf("%d.\n", &t[i].eta);
            fprintf(Maschi, "%d", t[i].eta);
        }
        else {
            if (o < 1)
                Femmine = fopen("femmine.csv", "w");
            o++;

            printf("\nInserisci il nome: ");
            scanf("%s.\n", (t[i].nome));
            fprintf(Femmine, "%s", t[i].nome);
            printf("Inserisci il cognome: ");
            scanf("%s.\n", (t[i].cognome));
            fprintf(Femmine, "%s", t[i].cognome);
            printf("Inserisci la classe: ");
            scanf("%s.\n", (t[i].classe));
            fprintf(Femmine, "%s", t[i].classe);
            printf("Inserisci l'eta: ");
            scanf("%d.\n", &t[i].eta);
            fprintf(Femmine, "%d", t[i].eta);
        }

    }
    if (i == N) {
        fclose(Maschi);
        fclose(Femmine);
    }


    //ordinato con il metodo selection sort
    for (i = 0; i < N - 1; i++) {
        stdMin = i;

        for (k = i + 1; k < N; k++) {
            if (strcmp(c[stdMin].cognome, c[k].cognome) < 0)
                stdMin = k;
        }
        if (k != stdMin) {
            temp = c[stdMin];
            c[stdMin] = c[k];
            c[k] = temp;
        }
    }

    //allocazione dinamica in memoria
    p = (studente*) malloc(sizeof (studente));

    return (EXIT_SUCCESS);
}


