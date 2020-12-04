#include "util.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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

/*TODO kommentar*/
void clrscr() {
    system("cls || clear");
}

/*TODO kommentar*/
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

/*TODO kommentar*/
/*Hvis der ikke er fundet nogen foreslag printes der en meddelelse*/
void print_array(Plante *p_arr, int n) {
    int i;

    for(i = 0; i < n; i++) {
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
