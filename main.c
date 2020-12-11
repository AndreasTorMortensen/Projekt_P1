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

    do {
        clrscr();
        suggest_plants(db, 5);
        printf("Tast 'b' for at afslutte, enter for at indtaste igen.\n");
    } while ((input = get_single_char()) != 'b');
    
    clrscr();
    fclose(db);

    return 0;
}

/*TODO kommentar*/
void suggest_plants(FILE *db, int n) {
    Plante *db_p, *input_p;
    Plante *p_arr = (Plante*) calloc(n, sizeof(Plante));
    int db_counter = 1;

    memset(p_arr, 0, n*sizeof(Plante));

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
            print_array(p_arr, n);
        }
        else {
            printf("End of database was not reached, failed at line: %d\n", db_counter);
        }
        free(input_p);
    }
    free(p_arr);
    rewind(db);
}