#include "core.h"
#include "util.h"
#include <stdlib.h>
#include <stdio.h>

int main(void) {
    FILE *dummy_db = fopen("parse_db_kontrol.csv", "r");
    Plante *result;
    int i;

    for(i = 1; i <= 6; i++) {
        printf("Parse_db call no. %d\n", i);
        result = parse_db(dummy_db);
        printf("\n");
        free(result);
    }
}