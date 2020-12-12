#include "core.h"
#include "util.h"
#include <stdlib.h>
#include <stdio.h>

int main(void) {
    char input;
    int counter = 0;

    do {
        printf("get_single_char input: \t\t");
        input = get_single_char();
        printf("get_single_char return: \t[%c]\n", input);
    } while(input != 'x');
}
