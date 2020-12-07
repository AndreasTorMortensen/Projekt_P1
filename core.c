#include "core.h"
#include "util.h"
#include <string.h>
#include <stdlib.h>
#include <string.h>



Plante *parse_db(FILE *db) {
    Plante *db_plante = (Plante*) calloc(1, sizeof(Plante));
    int scanned = 0;
    char line[100];
    if(fgets(line, 100, db) != NULL) {
        scanned = sscanf(line, "%[^,] , %[^,] , %[^,] , %[^,] , %d , %d , %d , %d", db_plante->id, db_plante->ph, db_plante->jord, db_plante->fugt, 
                                                                                    &db_plante->hjort, &db_plante->hare, &db_plante->fugl, &db_plante->insekt);
        if(scanned == 8 && check_db(*db_plante)) {
            return db_plante;
        }
    }
    /*Hvis EOF rammes i fgets, eller indscanning fejler returneres en NULL pointer, og den allokerede hukkommelse frigøres*/
    free(db_plante);
    return NULL;
}

Plante *parse_input() {
    Plante *input_plante = calloc(1, sizeof(Plante));
    char input;
    int good_input = 0;

    memset(input_plante, 0, sizeof(Plante));

    while(!good_input) {
        printf("1 - pH \t\t %s\n2 - Jord \t %s\n3 - Fugt \t %s\n4 - Hjort \t %d\n5 - Hare \t %d\n6 - Fugl \t %d\n7 - Insekt \t %d\nn - Søg med valgte parametre\nb - Afbryd\n", 
                input_plante->ph, input_plante->jord, input_plante->fugt, input_plante->hjort, input_plante->hare, input_plante->fugl,input_plante->insekt);

        input = get_single_char();
        clrscr();
        switch(input) {
            case '1':
                prompt_ph(input_plante);
                break;
            case '2':
                prompt_jord(input_plante);
                break;
            case '3':
                prompt_fugt(input_plante);
                break;
            case '4':
                prompt_hjort(input_plante);
                break;
            case '5':
                prompt_hare(input_plante);
                break;
            case '6':
                prompt_fugl(input_plante);
                break;
            case '7':
                prompt_insekt(input_plante);
                break;
            case 'n':
                if(check_input(*input_plante)) {
                    good_input = 1;
                }
                else {
                    good_input = 0;
                }
                break;
            case 'b':
                return NULL;
            default:
                printf("Forkert indtastning, prøv igen!\n");
                break;
        }
    }
    return input_plante;
}

int check_input(Plante p) {
    if(p.ph[0] == '\0' || p.jord[0] == '\0' || p.fugt[0] == '\0') {
        printf("Der SKAL vælges ph, jord, og fugtighed!\n");
        return 0;
    }
    else if(p.hjort == 0 && p.hare == 0 && p.fugl == 0 && p.insekt == 0) {
        printf("Minimum ÉN dyregruppe skal have en vægt højere end 0\n");
        return 0;
    }
    return 1;
}

int check_db(Plante p) {
    if(check_ph(p) && check_jord(p) && check_fugt(p)) {
        return 1;
    }  
    return 0;
}

int check_ph(Plante p) {
    int i = 0, prev_i = 0;
    char buffer[PH_MAX_LEN] = "";

    while(i < PH_MAX_LEN) {
        if(p.ph[i] == ';' || p.ph[i] == '\0') {
            strncpy(buffer, &p.ph[prev_i], i-prev_i);
            if(strcmp(buffer, "basisk") != 0 && strcmp(buffer, "neutral") != 0 && strcmp(buffer, "sur") != 0) {
                return 0;
            }
            else if(p.ph[i] == '\0') {
                break;
            }
            memset(buffer, 0, sizeof(buffer));
            prev_i = i+1;
        }
        i++;
    }

    return 1;
}

int check_jord(Plante p) {
    int i = 0, prev_i = 0;
    char buffer[JORD_MAX_LEN] = "";

    while(i < JORD_MAX_LEN) {
        if(p.jord[i] == ';' || p.jord[i] == '\0') {
            strncpy(buffer, &p.jord[prev_i], i-prev_i);
            if(strcmp(buffer, "let") != 0 && strcmp(buffer, "blandet") != 0 && strcmp(buffer, "haard") != 0) {
                return 0;
            }
            else if(p.jord[i] == '\0') {
                break;
            }
            memset(buffer, 0, sizeof(buffer));
            prev_i = i+1;
        }
        i++;
    }

    return 1;
}

int check_fugt(Plante p) {
    int i = 0, prev_i = 0;
    char buffer[FUGT_MAX_LEN] = "";

    while(i < FUGT_MAX_LEN) {
        if(p.fugt[i] == ';' || p.fugt[i] == '\0') {
            strncpy(buffer, &p.fugt[prev_i], i-prev_i);
            if(strcmp(buffer, "vaad") != 0 && strcmp(buffer, "toer") != 0) {
                return 0;
            }
            else if(p.fugt[i] == '\0') {
                break;
            }
            memset(buffer, 0, sizeof(buffer));
            prev_i = i+1;
        }
        i++;
    }   

    return 1;
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

int evaluate_score(Plante db_p, Plante input_p) {
    if(strstr(db_p.ph, input_p.ph) != NULL && strstr(db_p.jord, input_p.jord) != NULL && strstr(db_p.fugt, input_p.fugt) != NULL) {
        return db_p.hjort*input_p.hjort+db_p.hare*input_p.hare+db_p.fugl*input_p.fugl+db_p.insekt*input_p.insekt;
    }
    return 0;
}