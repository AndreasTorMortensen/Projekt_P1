#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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
Plante *parse_input();
int prompt_ph(Plante *p);
int prompt_jord(Plante *p);
int prompt_fugt(Plante *p);
int prompt_hjort(Plante *p);
int prompt_hare(Plante *p);
int prompt_fugl(Plante *p);
int prompt_insekt(Plante *p);
char get_single_char();
void clrscr();


int main(void) {
    FILE *db;
    Plante *db_p, *input_p;

    input_p = parse_input();
    free(input_p);

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
        /*Hvis EOF rammes i fgets returneres en NULL pointer, og den allokerede hukkommelse frigøres*/
        free(db_plante);
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

Plante *parse_input() {
    Plante *input_plante = calloc(1, sizeof(Plante));
    int input_stage = 0;
    clrscr();
    while(input_stage >= 0 && input_stage <= 6) {
        switch(input_stage) {
            case 0:
                input_stage += prompt_ph(input_plante) ? 1 : -1;
                break;
            case 1:
                input_stage += prompt_jord(input_plante) ? 1 : -1;
                break;
            case 2:
                input_stage += prompt_fugt(input_plante) ? 1 : -1;
                break;
            case 3:
                input_stage += prompt_hjort(input_plante) ? 1 : -1;
                break;
            case 4:
                input_stage += prompt_hare(input_plante) ? 1 : -1;
                break;
            case 5:
                input_stage += prompt_fugl(input_plante) ? 1 : -1;
                break;
            case 6:
                input_stage += prompt_insekt(input_plante) ? 1 : -1;
                break;
            default:
                break;
        }
    }

    if(input_stage < 0) {
        free(input_plante);
        return NULL;
    }
    return input_plante;
}

int prompt_ph(Plante *p) {
    char input;
    int good_input = 0;

    while(!good_input) {
        printf("Indtast jordens surhed:\n1. Basisk\n2. Neutral\n3. Sur\n");
        input = get_single_char();
        switch(input) {
            case '1':
                strcpy(p->ph, "basisk");
                good_input = 1;
                break;
            case '2':
                strcpy(p->ph, "neutral");
                good_input = 1;
                break;
            case '3':
                strcpy(p->ph, "sur");
                good_input = 1;
                break;
            case 'b':
                clrscr();
                return 0;
            default:
                clrscr();
                printf("Forkert indtastning, prøv igen.\n");
                break;
        }
    }
    clrscr();
    return 1;
}

int prompt_jord(Plante *p) {
    char input;
    int good_input = 0;

    while(!good_input) {
        printf("Indtast jordens hårdhed:\n1. Let\n2. Blandet\n3. Hård\n");
        input = get_single_char();
        switch(input) {
            case '1':
                strcpy(p->jord, "let");
                good_input = 1;
                break;
            case '2':
                strcpy(p->jord, "blandet");
                good_input = 1;
                break;
            case '3':
                strcpy(p->jord, "haard");
                good_input = 1;
                break;
            case 'b':
                clrscr();
                return 0;
            default:
                clrscr();
                printf("Forkert indtastning, prøv igen.\n");
                break;
        }
    }
    clrscr();
    return 1;
}

int prompt_fugt(Plante *p) {
    char input;
    int good_input = 0;

    while(!good_input) {
        printf("Indtast jordens fugtighed:\n1. Tør\n2. Våd\n");
        input = get_single_char();
        switch(input) {
            case '1':
                strcpy(p->ph, "toer");
                good_input = 1;
                break;
            case '2':
                strcpy(p->ph, "vaad");
                good_input = 1;
                break;
            case 'b':
                clrscr();
                return 0;
            default:
                clrscr();
                printf("Forkert indtastning, prøv igen.\n");
                break;
        }
    }
    clrscr();
    return 1;
}

int prompt_hjort(Plante *p) {
    char input;
    int good_input = 0;

    while(!good_input) {
        printf("På en skala fra 0-9 hvor vigtig er det at tiltrække hjorte?\n");
        input = get_single_char();
        if(isdigit(input)) {
            p->hjort = input - '0';
            good_input = 1;
        }
        else if(input == 'b') {
            clrscr();
            return 0;
        }
        else {
            clrscr();
            printf("Forkert indtastning, prøv igen.\n");
        }
    }
    clrscr();
    return 1;
}

int prompt_hare(Plante *p) {
    char input;
    int good_input = 0;

    while(!good_input) {
        printf("På en skala fra 0-9 hvor vigtig er det at tiltrække hare?\n");
        input = get_single_char();
        if(isdigit(input)) {
            p->hare = input - '0';
            good_input = 1;
        }
        else if(input == 'b') {
            clrscr();
            return 0;
        }
        else {
            clrscr();
            printf("Forkert indtastning, prøv igen.\n");
        }
    }
    clrscr();
    return 1;
}

int prompt_fugl(Plante *p) {
    char input;
    int good_input = 0;

    while(!good_input) {
        printf("På en skala fra 0-9 hvor vigtig er det at tiltrække fugle?\n");
        input = get_single_char();
        if(isdigit(input)) {
            p->fugl = input - '0';
            good_input = 1;
        }
        else if(input == 'b') {
            clrscr();
            return 0;
        }
        else {
            clrscr();
            printf("Forkert indtastning, prøv igen.\n");
        }
    }
    clrscr();
    return 1;
}

int prompt_insekt(Plante *p) {
    char input;
    int good_input = 0;

    while(!good_input) {
        printf("På en skala fra 0-9 hvor vigtig er det at tiltrække insekter?\n");
        input = get_single_char();
        if(isdigit(input)) {
            p->insekt = input - '0';
            good_input = 1;
        }
        else if(input == 'b') {
            clrscr();
            return 0;
        }
        else {
            clrscr();
            printf("Forkert indtastning, prøv igen.\n");
        }
    }
    clrscr();
    return 1;
}

char get_single_char() {
    char input, check;
    
    scanf(" %c", &input);
    while(check = getchar() != '\n') {
        if(!isspace(check)) {
            return '\0';
        }
    }
    return input;
}

void clrscr()
{
    system("clear");
}