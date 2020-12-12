#include "util.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#define CLEAR_STR "cls"
#elif defined(__linux)
#define CLEAR_STR "clear"
#endif

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
    system(CLEAR_STR);
}

void insert_plant(Plante *p_arr, Plante p, int n) {
    int lowest_score = p_arr[0].score, lowest_index = 0, i;

    for(i = 1; i < n; i++) {
        if(p_arr[i].score < lowest_score) {
            lowest_score = p_arr[i].score;
            lowest_index = i;
        }
    }
    if(p.score > lowest_score) {
        p_arr[lowest_index] = p;
    }   
}

void print_array(Plante *p_arr, Plante input_p,int n) {
    int i, found = 1;

    printf("Dine indtastede værdier:\n");
    printf("pH: %s - Jord: %s - Fugt: %s\n", input_p.ph, input_p.jord, input_p.fugt);
    printf("Hjort: %d - Hare: %d - Fugl: %d - Insekt: %d\n\n", input_p.hjort, input_p.hare, input_p.fugl, input_p.insekt);

    printf("Matchende planter:\n");
    printf("%-2s %-25sScore\n", "#","Plante ID");
    for(i = 0; i < n; i++) {
        if(p_arr[i].score > 0) {
            printf("%-2d %-25s %d\n", i+1, p_arr[i].id, p_arr[i].score);
            found++;
        }
    }
    if(found == 0) {
        printf("Der blev ikke fundet nogen matches i database\n");
    }
}

int compare_plants(const void *a, const void *b) {
    Plante *pa = (Plante*) a;
    Plante *pb = (Plante*) b;

    return pb->score - pa->score;
}
