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
int hjort - indeholder plantens pasningsgrad for hjortevildt (ved brugerinput indeholder denne variable den "vægt" brugeren vælger)
int hare - indeholder plantens pasningsgrad for hare (ved brugerinput indeholder denne variable den "vægt" brugeren vælger)
int fugle - indeholder plantens pasningsgrad for fugle (ved brugerinput indeholder denne variable den "vægt" brugeren vælger)
int insekt - indeholder plantens pasningsgrad for insekter (ved brugerinput indeholder denne variable den "vægt" brugeren vælger)
int score - indeholder plantens beregnede score ud fra ovenstående data samt brugerinput
```
Plante structen vil blive brugt både til at omdanne indhentet data fra databasen samt bruger input, til noget fast og let tilgængeligt. For database indhold bliver der læst direkte ind på de forskellige parametre, hvor det for brugerinputtet vil blive læst ind alt efter hvad brugeren indtaster. Derudover skal brugeren ved de forskellige "dyre"parametre indtaste en form for vægt der angiver vigtigheden af de forskellige dyr. Dermed kan brugeren mere detaljeret udvælge hvilke dyr der ønskes tilpasning til.

## Funktionsbeskrivelser ##
### Plante parse_db(FILE *db) ###
Læser og konverterer en linje fra FILE *db til en dynamisk allokeret instans af en plante struct.
Pointeren til plante structen returneres, hvis fil pointeren er nået til EOF returneres en NULL pointer.
### Plante parse_input() ###
Returnerer en dynamisk allokeret instans af en plante struct ud fra dialog med brugeren
Hvis brugeren afbryder dialogen returneres en NULL pointer
### int evaluate_score(Plante db, Plante input) ###
Beregner og returnere scoren af planten fra database db_p ud fra brugerens input input_p.
Score = summen af produkterne af hjort, hare, fugl og insekt værdierne for db_p og input_p
### void suggest_plants(FILE *db) ###
Denne funktion står for hele foreslagsprocessen. Det er her parse_input og parse_db vil blive kaldt fra, samt her scoren for hver plante beregnes med kald til evaluate_score. Disse ordnes i et array af plante structs som udfyldes med de højest scorende planter, og til sidst udprintes på terminalen.
### void initialize_array(Plante *p_arr) ###
Hjælpefunktion til at initialisere alle score værdierne i det parameteroverførte array, til værdien 0.
### void insert_plant(Plante *p_arr, Plante p) ###
Hjælpefunktion til at indsætte/erstatte planten p i arrayet, hvis dens score er højere end den mindste score i plante arrayet.
### void print_array ###
Hjælpefunktion til udprintning af plante arrayet.
### int prompt_"data"(Plante *p) ###
Prompter og assigner brugerens input til de diverse "data"(eg. ph, jord, fugt) variabler af planten overført som parameter. Der promptes indtil brugeren indtaster et godkendt input. Ved accepteret input returneres 0, hvis brugeren indtaster 'b', ellers 1
### char get_single_char() ###
Hjælpefunktion der læser og returnere én enkel karakter fra stdin buffer Hvis der indtastes mere end 1 karakter tømmes stdin bufferen og der returneres '\0'
### int compare_plant(const void *a, const void *b) ###
Compare funktionen er udelukkende den sammenligningsfunktion der skal bruges til at sortere vores liste af egnede planter med qsort. Denne skal umiddelbart sortere efter planternes score. Yderligere sortering vil være relevant hvis der implementeres flere datapunkter, som f.eks. mængde såsæd pr. kvm eller lign.
# Programudvikling #
Vi har gennemgået hvordan vi som gruppe kan samarbejde om program-arbejdet, med det bedst mulige udbytte for os alle. Dette er med påtanke på at alle involverede kan forsvare samt forklare funktionaliteten af alle aspekter af programmet. Ud fra dette kom vi frem til en stykvis proces, hvor vi istedet for at uddele ansvar for at implementere individuelle funktioner hver især, istedet alle laver et foreslag til hvordan funktionen kan udformes. Disse foreslag går vi efterfølgende igennem sammen, hvor vi kan afklare hvordan vi hver især har udført opgaven, samt få svar på spørgsmål, hvis disse opstår. Ud fra denne gennemngang kan vi bestemme os samlet på én løsning vi anser som bedst. 

Det tekniske udviklingsforløb kommer til at foregå gennem en fælles GitHub, hvor vi når der arbejdes indiduelt kan arbejde på tildelte branches, uden at påvirke vores samlede program. Dette sikrer samtidig også at vi alle arbejde ud fra samme kodebase. 

Derudover har vi også gjort os tanker om hvordan programmet kan fragmentaliseres, i passende header og kilde filer, for at forbedre overskueligheden af programkoden. Vi er dog ikke gået meget yderligere i dybden med dette, da størstedelen af programdesignet lige nu stadig er i planlægning/teoretiske stadie. 