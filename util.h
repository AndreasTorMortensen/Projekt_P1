#ifndef Util_h
#define Util_h
#include "plante.h"

/*Læser og returnere én enkel karakter fra stdin buffer
  Hvis der indtastes mere end 1 karakter tømmes stdin bufferen og der returneres '\0'*/
char get_single_char();

/*Clearer alt indhold fra terminal prompten (virker kun på Linux og Windows)*/
void clrscr();

/*Indsætter planten p i arrayet p_arr, hvis p.score er højere end den mindste score tilstede i arrayet*/
void insert_plant(Plante *p_arr, Plante p, int n);

/*Udprinter hver plante i arrayet p_arr på listeform*/
void print_array(Plante *p_arr, Plante input_p, int n);

/*Sammenligner to Plante structs i forhold til deres score*/
int compare_plants(const void *a, const void *b);

#endif