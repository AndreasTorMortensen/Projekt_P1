#include <stdlib.h>
#include <string.h>
#include "core.h"
#include "util.h"
#include "plante.h"
#define DB_FILE "db_biodiversitet.csv"

void suggest_plants(FILE *db, int n);

int main(void) {
    FILE *db = fopen(DB_FILE, "r");
    char input;
    
    /*Ændre den brugte codepage i Windows terminal til UTF-8, hvis der kompileres til Windows*/
    #ifdef _WIN32
    system("chcp 65001");
    #endif

    do {
        clrscr();
        suggest_plants(db, 5);
        printf("Tast 'b' for at afslutte, enter for at indtaste igen.\n");
    } while ((input = get_single_char()) != 'b');
    
    clrscr();
    fclose(db);

    return 0;
}

/*Finder og printer n antal passende planter i *db filen.
  Brugeren promptes for input m. parse_input som herefter bruges til at finde matches med parse_db*/
void suggest_plants(FILE *db, int n) {
    Plante *db_p, *input_p;
    Plante *p_arr = (Plante*) calloc(n, sizeof(Plante));
    int db_counter = 1;

    if((input_p = parse_input()) != NULL) {

        while((db_p = parse_db(db)) != NULL) {
            db_p->score = evaluate_score(*db_p, *input_p);
            if(db_p->score > 0) {
                insert_plant(p_arr, *db_p, n);
            }
            db_counter++;
            free(db_p);
        }

        if(feof(db)) {
            qsort(p_arr, n, sizeof(Plante), compare_plants);
            print_array(p_arr, *input_p, n);
        }
        else {
            printf("End of database was not reached, failed at line: %d\n", db_counter);
        }
        free(input_p);
    }
    free(p_arr);
    rewind(db);
}