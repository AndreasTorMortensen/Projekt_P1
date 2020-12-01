#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define NUM_OF_SUGGESTIONS 5

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

void suggest_plants(FILE *db);
void initialize_array(Plante *p_arr);
void insert_plant(Plante *p_arr, Plante p);
void print_array(Plante *p_arr);
int compare_plants(const void *a, const void *b);
Plante *parse_db(FILE *db);
Plante *parse_input();
int prompt_ph(Plante *p);
int prompt_jord(Plante *p);
int prompt_fugt(Plante *p);
int prompt_hjort(Plante *p);
int prompt_hare(Plante *p);
int prompt_fugl(Plante *p);
int prompt_insekt(Plante *p);
int evaluate_score(Plante db_p, Plante input_p);
char get_single_char();
void clrscr();


int main(void) {
    FILE *db = fopen("db_biodiversitet copy.csv", "r");
    suggest_plants(db);
    fclose(db);
    return 0;
}

/*TODO kommentar*/
void suggest_plants(FILE *db) {
    Plante *db_p, *input_p;
    Plante p_arr[NUM_OF_SUGGESTIONS];

    initialize_array(p_arr);
    if(((input_p = parse_input()) != NULL)) {
        while((db_p = parse_db(db)) != NULL) {
            db_p->score = evaluate_score(*db_p, *input_p);
            if(db_p->score > 0) {
                insert_plant(p_arr, *db_p);
            }
            free(db_p);
        }
        free(input_p);
        qsort(p_arr, NUM_OF_SUGGESTIONS, sizeof(Plante), compare_plants);
        print_array(p_arr);
    }
}

/*TODO kommentar*/
void initialize_array(Plante *p_arr) {
    int i;

    for(i = 0; i < NUM_OF_SUGGESTIONS; i++) {
        p_arr[i].score = 0;
    }
}

/*TODO kommentar*/
void insert_plant(Plante *p_arr, Plante p) {
    int lowest_score = p_arr[0].score, lowest_index = 0, i;

    for(i = 1; i < NUM_OF_SUGGESTIONS; i++) {
        if(p_arr[i].score < lowest_score) {
            lowest_score = p_arr[i].score;
            lowest_index = i;
        }
    }
    if(p.score > lowest_score) {
        p_arr[lowest_index] = p;
    }   
}

/*TODO kommentar*/
/*Hvis der ikke er fundet nogen foreslag printes der en meddelelse*/
void print_array(Plante *p_arr) {
    int i;

    for(i = 0; i < NUM_OF_SUGGESTIONS; i++) {
        if(p_arr[i].score > 0) {
            printf("%s: %d\n", p_arr[i].id, p_arr[i].score);
        }
    }
}

/*TODO kommentar*/
int compare_plants(const void *a, const void *b) {
    Plante *pa = (Plante*) a;
    Plante *pb = (Plante*) b;

    return pb->score - pa->score;
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

/*Returnerer en dynamisk allokeret instans af en plante struct ud fra dialog med brugeren
  Hvis brugeren afbryder dialogen returneres en NULL pointer*/
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

/*Prompter og assigner brugerens input til ph variablen af planten overført som parameter
  Der promptes indtil brugeren indtaster et godkendt input
  Ved accepteret input returneres 0, hvis brugeren indtaster 'b', ellers 1*/
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

/*Prompter og assigner brugerens input til jord variablen af planten overført som parameter
  Der promptes indtil brugeren indtaster et godkendt input
  Ved accepteret input returneres 0, hvis brugeren indtaster 'b', ellers 1*/
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

/*Prompter og assigner brugerens input til fugt variablen af planten overført som parameter
  Der promptes indtil brugeren indtaster et godkendt input
  Ved accepteret input returneres 0, hvis brugeren indtaster 'b', ellers 1*/
int prompt_fugt(Plante *p) {
    char input;
    int good_input = 0;

    while(!good_input) {
        printf("Indtast jordens fugtighed:\n1. Tør\n2. Våd\n");
        input = get_single_char();
        switch(input) {
            case '1':
                strcpy(p->fugt, "toer");
                good_input = 1;
                break;
            case '2':
                strcpy(p->fugt, "vaad");
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

/*Prompter og assigner brugerens input til hjort variablen af planten overført som parameter
  Der promptes indtil brugeren indtaster et godkendt input
  Ved accepteret input returneres 0, hvis brugeren indtaster 'b', ellers 1*/
int prompt_hjort(Plante *p) {
    char input;
    int good_input = 0;

    while(!good_input) {
        printf("På en skala fra 0-5 hvor vigtig er det at tiltrække hjorte?\n");
        input = get_single_char();
        if(input >= '0' && input <= '5') {
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

/*Prompter og assigner brugerens input til hare variablen af planten overført som parameter
  Der promptes indtil brugeren indtaster et godkendt input
  Ved accepteret input returneres 0, hvis brugeren indtaster 'b', ellers 1*/
int prompt_hare(Plante *p) {
    char input;
    int good_input = 0;

    while(!good_input) {
        printf("På en skala fra 0-5 hvor vigtig er det at tiltrække hare?\n");
        input = get_single_char();
        if(input >= '0' && input <= '5') {
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

/*Prompter og assigner brugerens input til fugl variablen af planten overført som parameter
  Der promptes indtil brugeren indtaster et godkendt input
  Ved accepteret input returneres 0, hvis brugeren indtaster 'b', ellers 1*/
int prompt_fugl(Plante *p) {
    char input;
    int good_input = 0;

    while(!good_input) {
        printf("På en skala fra 0-5 hvor vigtig er det at tiltrække fugle?\n");
        input = get_single_char();
        if(input >= '0' && input <= '5') {
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

/*Prompter og assigner brugerens input til insekt variablen af planten overført som parameter
  Der promptes indtil brugeren indtaster et godkendt input
  Ved accepteret input returneres 0, hvis brugeren indtaster 'b', ellers 1*/
int prompt_insekt(Plante *p) {
    char input;
    int good_input = 0;

    while(!good_input) {
        printf("På en skala fra 0-5 hvor vigtig er det at tiltrække insekter?\n");
        input = get_single_char();
        if(input >= '0' && input <= '5') {
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

/*Beregner og returnere scoren af indlæst plante fra database db_p ud fra brugerens input input_p
  Score = summen af produkterne af hjort, hare, fugl og insekt værdierne for db_p og input_p*/
int evaluate_score(Plante db_p, Plante input_p) {
    if(strstr(db_p.ph, input_p.ph) != NULL && strstr(db_p.jord, input_p.jord) != NULL && strstr(db_p.fugt, input_p.fugt) != NULL) {
        return db_p.hjort*input_p.hjort+db_p.hare*input_p.hare+db_p.fugl*input_p.fugl+db_p.insekt*input_p.insekt;
    }
    return 0;
}

/*Læser og returnere én enkel karakter fra stdin buffer
  Hvis der indtastes mere end 1 karakter tømmes stdin bufferen og der returneres '\0'*/
char get_single_char() {
    /*line skal have størrelsen 3, da der ved kald til fgets skal være plads til '\n' og '\0' karakter*/
    char line[3];

    fgets(line, 3, stdin);
    /*Clearing af stdin buffer hvis fgets ikke har læst hele stdin bufferen*/
    if(strchr(line, '\n') == NULL) {
        while(getchar() != '\n');
    }
    /*Hvis 2. karakter i line ikke er new-line returneres '\0'*/
    return line[1] == '\n' ? line[0] : '\0';
}

void clrscr() {
    system("cls || clear");
}