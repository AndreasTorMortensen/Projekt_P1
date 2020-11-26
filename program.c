
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char id[25];
    char ph[20];
    char jord[20];
    char fugt[10];
    int hjort;
    int hare;
    int fugl;
    int insekt;
    int score;
}Plante;

Plante *parse_db(FILE *db);

int main(void) {
    return 0;
}

/*Læser og konverterer en linje fra FILE *db til en dynamisk allokeret instans af en plante struct.
  Pointeren til plante structen returneres.
  Hvis fil pointeren er nået til EOF returneres en NULL pointer.*/
Plante *parse_db(FILE *db) {
    Plante *db_plante = (Plante*) calloc(1, sizeof(Plante));
    char line[100];
    char *token;

    if(fgets(line, 100, db) == NULL) {
        /*Hvis EOF rammes i fgets returneres en NULL pointer*/
        return NULL;
    }
    else {    
        /*Den læste linje indeles i tokens adskilt af ',' - disse assignes til plantens variabler*/
        token = strtok(line, ",");
        strcpy(db_plante->id, token);
        token = strtok(NULL, ",");
        strcpy(db_plante->ph, token);
        token = strtok(NULL, ",");
        strcpy(db_plante->jord, token);
        token = strtok(NULL, ",");
        strcpy(db_plante->fugt, token);
        token = strtok(NULL, ",");
        db_plante->hjort = atoi(token);
        token = strtok(NULL, ",");
        db_plante->hare = atoi(token);
        token = strtok(NULL, ",");
        db_plante->fugl = atoi(token);
        token = strtok(NULL, ",");
        db_plante->insekt = atoi(token);

        return db_plante;
    }
}
