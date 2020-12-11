#ifndef Plante_h
#define Plante_h
#define ID_MAX_LEN 25
#define PH_MAX_LEN 20
#define JORD_MAX_LEN 20
#define FUGT_MAX_LEN 10


struct planteStruct{
    char id[ID_MAX_LEN];
    char ph[PH_MAX_LEN];
    char jord[JORD_MAX_LEN];
    char fugt[FUGT_MAX_LEN];
    int hjort;
    int hare;
    int fugl;
    int insekt;
    int score;
};

typedef struct planteStruct Plante;

#endif