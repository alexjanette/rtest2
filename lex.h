/*from textbook*/
#include <stdio.h>
#include <ctype.h>
/* Global declarations */
/* Variables */
int classofChar;
char lexicalTerm [100];
char adjChar;
int numofLex;
int thisToke;
int adjToke;
FILE *in_fp, *fopen();
void inChar();
void outChar();
void findSomething();
int lex();
/* Character classes */
#define ALPHA 0
#define DIGITNUM 1
#define WHAT 99
/* Token codes */
#define INTEGER 10
#define IDENT 11
#define ATAMA_IS 20
#define ADDING 21
#define SUBTRACTING 22
#define MULITPLYING 23
#define DIVIDING 24
#define LESSER 25
#define MORE 26
#define LEFTBLOCK 27
#define RIGHTBLOCK 28
#define LONGPAUSE 29
#define MODUL 30
#define SQIGGL 31
#define MONEY 32
#define LEFTPARENT 33
#define RIGHTPARENT 34
#define OKAYAND 35
#define PAUSE 36
#define DDOT 37
#define ASSIGNING 38
#define IQUOTE 39
#define FULLSTOP 40
#define NOTTHESAME 41
#define DEFNUM 42
#define ENDER 43
#define STARTER 44
#define LEFTBRACK 45
#define RIGHTBRACK 46



int lookup(char ch) {
switch (ch) {

case '&':
inChar();
adjToke = OKAYAND;
break;

case '<':
inChar();
adjToke = LESSER;
break;

case '>':
inChar();
adjToke = MORE;
break;

case '=':
inChar();
adjToke = ASSIGNING;
break;

case '+':
inChar();
adjToke = ADDING;
break;

case ':':
inChar();
adjToke = DDOT;
break;

case '-':
inChar();
adjToke = SUBTRACTING;
break;

case ',':
inChar();
adjToke = PAUSE;
break;

case '*':
inChar();
adjToke = MULITPLYING;
break;

case '"':
inChar();
adjToke = IQUOTE;
break;

case '/':
inChar();
adjToke = DIVIDING;
break;

case '$':
inChar();
adjToke= MONEY;
break;

case '~':
inChar();
adjToke= SQIGGL;
break;

case ';':
inChar();
adjToke= LONGPAUSE;
break;

case '[':
inChar();
adjToke= LEFTBLOCK;
break;

case ']':
inChar();
adjToke= RIGHTBLOCK;
break;

case '(':
inChar();
adjToke= LEFTPARENT;
break;

case ')':
inChar();
adjToke= RIGHTPARENT;
break;

case '.':
inChar();
adjToke= FULLSTOP;
break;

case '!':
inChar();
adjToke = NOTTHESAME;
break;

case '#':
inChar();
adjToke = DEFNUM;
break;

case '^':
inChar();
adjToke = ENDER;
break;

case '@':
inChar();
adjToke = STARTER;
break;

case '{':
inChar();
adjToke = LEFTBRACK;
break;

case '}':
inChar();
adjToke = RIGHTBRACK;
break;

case '%':
inChar();
adjToke = MODUL;
break;

default:
inChar();
adjToke = EOF;
break;
}
return adjToke;
}



void inChar() {
if (numofLex <= 98) {
lexicalTerm[numofLex++] = adjChar;
lexicalTerm[numofLex] = 0;
}
else
printf("Error - lexicalTerm is too long \n");
} 


void outChar() {
if ((adjChar = getc(in_fp)) != EOF) {
if (isalpha(adjChar))
classofChar = ALPHA;
else if (isdigit(adjChar))
classofChar = DIGITNUM;
else classofChar = WHAT;
}
else
classofChar = EOF;
}



void findSomething() {
while (isspace(adjChar))
outChar();
}


int lex() {
numofLex = 0;
findSomething();
switch (classofChar) {
    
case ALPHA:
inChar();
outChar();
while (classofChar == ALPHA || classofChar == DIGITNUM) {
inChar();
outChar();
}
adjToke = IDENT;
break;

case DIGITNUM:
inChar();
outChar();
while (classofChar == DIGITNUM) {
inChar();
outChar();
}
adjToke = INTEGER;
break;

case WHAT:
lookup(adjChar);
outChar();
break;

/* EOF */
case EOF:
adjToke = EOF;
lexicalTerm[0] = 'E';
lexicalTerm[1] = 'O';
lexicalTerm[2] = 'F';
lexicalTerm[3] = 0;
break;
} /* End of switch */
printf("The token is: %d, The lexical term is %s\n",
adjToke, lexicalTerm);
return adjToke;
} 
/* End of function lex */
