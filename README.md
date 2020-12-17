# Projekt_P1 #
Projekt repository til gruppe A307b - P1 projekt om biodiversitet fra AAU 
I dette repository findes alt det materiale, der indgår i vores programmerede løsning, til projektet om biodiversitet. Tilhørende rapport udvikles i overleaf, og kan ses på følgende link:
https://www.overleaf.com/read/tqzfxgqpjwjc

## Kompiler ## 
Vi bruger gnu compiler collection (gcc) for at kompiler vores program. 
Kommando: ```gcc -g -ansi -Wall -pedantic main.c core.c util.c -o main ```

## Oversigt ## 
Vores Test og validering for programmet kan findes i mappen **Test**  
Programmets **hiraki** tilhørende **flowcharts** samt en oversigt over **komponenterne i programmet** kan findes i mappen **bilag**  
Vores **database** er lageret som en .csv fil i hovedmappen med navn **db_biodiversitet.csv**

Indehold af **Main.c**
* main
* suggest_plants

Indhold af **Core.c**
* parse_db
* parse_input
* check_input
* check_db
* check_ph
* check_jord
* check_fugt
* prompt_ph
* promt_jord
* prompt_fugl
* prompt_hjort
* prompt_hare
* prompt_fugl
* prompt_insekt
* evaluate_score

Indhold af **util.c**
* get_single_char
* clrscr
* insert_plant
* print_array
* compare_plants

Indhold af **plante.h**
* Struct Plante
