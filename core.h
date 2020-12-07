#ifndef Core_h
#define Core_h

#include <stdio.h>
#include "plante.h"

/*Læser og konverterer en linje fra FILE *db til en dynamisk allokeret instans af en plante struct.
  Pointeren til plante structen returneres.
  Hvis fil pointeren er nået til EOF returneres en NULL pointer.*/
Plante *parse_db(FILE *db);

/*Returnerer en dynamisk allokeret instans af en plante struct ud fra dialog med brugeren
  Hvis brugeren afbryder dialogen returneres en NULL pointer*/
Plante *parse_input();

/*TODO KOMMENTAR*/
int check_input(Plante p);

/*TODO KOMMENTAR*/
int check_db(Plante p);

/*TODO KOMMENTAR*/
int check_ph(Plante p);

/*TODO KOMMENTAR*/
int check_jord(Plante p);

/*TODO KOMMENTAR*/
int check_fugt(Plante p);

/*Prompter og assigner brugerens input til ph variablen af planten overført som parameter
  Der promptes indtil brugeren indtaster et godkendt input
  Ved accepteret input returneres 0, hvis brugeren indtaster 'b', ellers 1*/
void prompt_ph(Plante *p);

/*Prompter og assigner brugerens input til jord variablen af planten overført som parameter
  Der promptes indtil brugeren indtaster et godkendt input
  Ved accepteret input returneres 0, hvis brugeren indtaster 'b', ellers 1*/
void prompt_jord(Plante *p);

/*Prompter og assigner brugerens input til fugt variablen af planten overført som parameter
  Der promptes indtil brugeren indtaster et godkendt input
  Ved accepteret input returneres 0, hvis brugeren indtaster 'b', ellers 1*/
void prompt_fugt(Plante *p);

/*Prompter og assigner brugerens input til hjort variablen af planten overført som parameter
  Der promptes indtil brugeren indtaster et godkendt input
  Ved accepteret input returneres 0, hvis brugeren indtaster 'b', ellers 1*/
void prompt_hjort(Plante *p);

/*Prompter og assigner brugerens input til hare variablen af planten overført som parameter
  Der promptes indtil brugeren indtaster et godkendt input
  Ved accepteret input returneres 0, hvis brugeren indtaster 'b', ellers 1*/
void prompt_hare(Plante *p);

/*Prompter og assigner brugerens input til fugl variablen af planten overført som parameter
  Der promptes indtil brugeren indtaster et godkendt input
  Ved accepteret input returneres 0, hvis brugeren indtaster 'b', ellers 1*/
void prompt_fugl(Plante *p);

/*Prompter og assigner brugerens input til insekt variablen af planten overført som parameter
  Der promptes indtil brugeren indtaster et godkendt input
  Ved accepteret input returneres 0, hvis brugeren indtaster 'b', ellers 1*/
void prompt_insekt(Plante *p);

/*Beregner og returnere scoren af indlæst plante fra database db_p ud fra brugerens input input_p
  Score = summen af produkterne af hjort, hare, fugl og insekt værdierne for db_p og input_p*/
int evaluate_score(Plante db_p, Plante input_p);

#endif