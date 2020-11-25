# Projekt_P1 #
Projekt repo til gruppe A307b P1 projekt om biodiversitet
I dette repository findes alt det materiale, der indgår i vores programmerede løsning, til projektet om biodiversitet. Tilhørende rapport udvikles i overleaf, og kan ses på følgende link:
https://www.overleaf.com/read/tqzfxgqpjwjc
# Programopbygning #
Størstedelen af programstrukturen, samt funktionaliteten, bygges op omkring følgende struct, der skal repræsentere en plante:
## Plante Struct ##
```
char id[] - indeholder en string til at identificere planten
char ph[] - indeholder plantens ønskede ph værdi for jorden
char jord[] - indeholder plantens ønskede jordblanding
char fugt[] - indeholder plantens ønskede jordfugtighed
double hjort - indeholder plantens pasningsgrad for hjortevildt (ved brugerinput indeholder denne variable den "vægt" brugeren vælger)
double hare - indeholder plantens pasningsgrad for hare (ved brugerinput indeholder denne variable den "vægt" brugeren vælger)
double fugle - indeholder plantens pasningsgrad for fugle (ved brugerinput indeholder denne variable den "vægt" brugeren vælger)
double insekt - indeholder plantens pasningsgrad for insekter (ved brugerinput indeholder denne variable den "vægt" brugeren vælger)
double score - indeholder plantens beregnede score ud fra ovenstående data samt brugeinput
```
Plante structen vil blive brugt både til at omdanne indhentet data fra databasen samt bruger input, til noget fast og let tilgængeligt. For database indhold bliver der læst direkte ind på de forskellige parametre, hvor det for brugerinputtet vil blive læst ind alt efter hvad brugeren indtaster. Derudover skal brugeren ved de forskellige "dyre"parametre indtaste en form for vægt der angiver vigtigheden af de forskellige dyr. Dermed kan brugeren mere detaljeret udvælge hvilke dyr der ønskes tilpasning til.

## Backend funktionaliteter ##
Følgende beskriver overordnet funktionaliteter af udvalgte funktioner, der opererer i "backenden" af programmet.
### Plante parse_db(FILE *db) ###
Denne funktion skal læse og omdanne en linje i csv-databasen til en plante struct. Parameteren er pointeren til database-filen, der skal være åbnet på forhånd. Hvis pointeren er i slutningen af filen og peger på End-Of-File skal den returnere NULL.
### Plante parse_input() ###
Denne funktion skal stå for dialog samt indscanning af brugerinput, samt passende omdannelse af dette til at kunne repræsenteres i en plante struct. Brugervalgmulighedernede skal være statisk implementeret så input håndtering minimeres. For input af dyr, skal brugerne angive vægte for hvor vigtige de forskellige dyregrupper er.
### double evaluate_score(Plante db, Plante input) ###
Denne funktion står for at sammenligne og beregne scoren for en plante læst fra databasen, med det givne bruger input. Dette gøres ved hjælp af de to Plante parametre, hvor scoren returneres som en double. Hvordan denne funktion specifikt beregner scoren er ikke 100% fastlagt endnu, vores umiddelbare tanke er dog følgende:
Scoren returneres som summen af produkterne af de brugerindtastede vægte og "database" plantens specifikationer. Levevilkår egenskaberne såsom; ph, jord og fugt - behandler vi umiddelbart som alt eller intet værdier hvor de planter der ikke lever op til de ønskede forhold automatisk sættes til at have en score på 0, og dermed bliver de discarded. 
### int compare_plant(const void *a, const void *b) ###
Compare funktionen er udelukkende den sammenligningsfunktion der skal bruges til at sortere vores liste af egnede planter med qsort. Denne skal umiddelbart sortere efter planternes score. 
### Samlet backend funktion ###
Vi kommer uden tvivl også til at få brug for en funktion der samler og gør brug af de ovenstående funktioner. Denne er dog på nuværende tidspunkt for os lidt flydende og ikke så definerbar. Umiddelbart skal den stå for at lave kald til og parse input fra brugeren, og herefter gennemgå, indlæse og sammenligne/evaluere hver individuel plante i databasen. Her vil der være en aktiv og dynamisk liste/array hvori vi indsætter/overskirver med de højest/højere scorende planter. Denne liste udprintes til sidst til brugeren i terminalen. 
## Frontend funktionaliteter ##
Følgende beskriver overordnet funktinalitet af udvalgte funktioner, der operere i "frontenden" af programmet.
### void print_plant(Plante p) ###
Denne funktion skal på en flot og overskuelig måde udprinte en plante p, repræsenteret i form af vores Plante struktur, til terminalen. Denne bruges når listen af de egnede planter skal udprintes. 
### Generelle interface funktionaliteter ###
Udover en funktion til at udprinte en plante, vil der uden tvivl opstå brug for andre funktioner til bruger-interaktion/terminal-interface. Eftersom dette ikke udgør en vital del af programmets kerneformål, ligger vi som udgangspunkt fokus på at få implementeret alt det bagvedliggende funktionalitet før der arbejdes for meget på bruger-interfacet.
# Programudvikling #
Vi har gennemgået hvordan vi som gruppe kan samarbejde om program-arbejdet, med det bedst mulige udbytte for os alle. Dette er med påtanke på at alle involverede kan forsvare samt forklare funktionaliteten af alle aspekter af programmet. Ud fra dette kom vi frem til en stykvis proces, hvor vi istedet for at uddele ansvar for at implementere individuelle funktioner hver især, istedet alle laver et foreslag til hvordan funktionen kan udformes. Disse foreslag går vi efterfølgende igennem sammen, hvor vi kan afklare hvordan vi hver især har udført opgaven, samt få svar på spørgsmål, hvis disse opstår. Ud fra denne gennemngang kan vi bestemme os samlet på én løsning vi anser som bedst. 

Det tekniske udviklingsforløb kommer til at foregå gennem en fælles GitHub, hvor vi når der arbejdes indiduelt kan arbejde på tildelte branches, uden at påvirke vores samlede program. Dette sikrer samtidig også at vi alle arbejde ud fra samme kodebase. 

Derudover har vi også gjort os tanker om hvordan programmet kan fragmentaliseres, i passende header og kilde filer, for at forbedre overskueligheden af programkoden. Vi er dog ikke gået meget yderligere i dybden med dette, da størstedelen af programdesignet lige nu stadig er i planlægning/teoretiske stadie. 