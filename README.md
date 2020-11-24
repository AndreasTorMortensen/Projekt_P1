# Projekt_P1 #
Projekt repo til gruppe A307b P1 projekt om biodiversitet

# Designovervejelser #
Arbejde med data fra databasen bygges op om en struct, på følgende form:
## Plante Struct ##
```
char id[] - indeholder en string til at identificere planten
char ph[] - indeholder plantens ønskede ph værdi for jorden
char jord[] - indeholder plantens ønskede jordblanding
char fugt[] - indeholder plantens ønskede jordfugtighed
double hjort - indeholder plantens pasningsgrad for hjortevildt
double hare - indeholder plantens pasningsgrad for hare
double fugle - indeholder plantens pasningsgrad for fugle
double insekt - indeholder plantens pasningsgrad for insekter
double score - indeholder plantens beregnede score ud fra ovenstående data samt brugeinput
```
Denne struct vil blive brugt både til at omdanne det indhentede data fra databasen samt bruger input, til noget fast og let tilgængeligt. For database indhold bliver der læst direkte ind på de forskellige parametre, hvor det for brugerinputtet vil blive læst ind alt efter hvad brugeren indtaster. Derudover skal brugeren ved de forskellige "dyre"parametre indtaste en form for vægt der angiver vigtigheden af de forskellige dyr. Dermed kan brugeren mere detaljeret udvælge hvilke dyr der ønskes tilpasning til.

## Backend funktionaliteter ##
Følgende beskriver overordnet funktionaliteter af udvalgte funktioner, der opererer i "backenden" af programmet.
### Plante parse_db(FILE *db) ###
Denne funktion skal læse og omdanne en linje i csv-databasen til en plante struct. Parameteren er pointeren til databasen, der skal være åbnet på forhånd. Hvis pointeren er i slutningen af filen og peger på End-Of-File skal den returnere NULL.
### Plante parse_input() ###
Denne funktion skal stå for dialog samt indscanning af brugerinput, samt passende omdannelse af dette til at kunne repræsenteres i en plante struct. Brugervalgmulighedernede skal være statisk implementeret så input håndtering minimeres. For input af dyr, skal brugerne angive vægte for hvor vigtige de forskellige dyregrupper er.
### double evaluate_score(Plante db, Plante input) ###

### int compare_plant(const void *a, const void *b) ###

## Frontend funktionaliteter ##
Følgende beskriver overordnet funktinalitet af udvalgte funktioner, der operere i "frontenden" af programmet.
### void print_plant(Plante p) ###