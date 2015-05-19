%{

#include "DEBUG.h"

#include	<iostream>

extern int 		yylex();
extern char* 	yytext;
extern int 		yylineno;

void	yyerror(const char *error)
{
	std::cerr << "Error: Line #" << yylineno << ": " << yytext << ": " << error << std::endl;
	//exit(EXIT_FAILURE);
}

#include	"KObject.hpp"
#include	"Keepi.hpp"

Keepi*	__keepi;

%}

%union
{
	std::string* 	id;
	KObject*		obj;
}

%token <id> IDENTIFIER
%token NL ASSIGN_OP PRINT COMMA DSYMTAB EXIT
%token <obj> INTEGER REAL STRING TRUE FALSE

%left AND OR

%type <obj> expr B E T F boolean args

%start keepi

%%

keepi :	{ return 42; }
	| statements NL { YYACCEPT; }
	;

statements :
	| statements statement { YYACCEPT; }
	;
                  
statement : expr NL { ; }
	| assign NL { ; }
	| instruction NL { ; }
	;

instruction : command
	;

command : print
	| DSYMTAB { __keepi->dsymtab(); }
	| EXIT { __keepi->_exit(); }
	;

print : PRINT args { std::cout << $2 << std::endl; }
	| PRINT args COMMA { std::cout << $2; }
	;

args : args COMMA expr { $$ = KObject::add($1, $3); }
	| expr { $$ = $1; }
	;

assign : IDENTIFIER ASSIGN_OP expr { __keepi->assign(*$1, $3); }
	;

expr :	B 			{ $$ = $1; std::cout << "result=" << $1 << "\n"; }
	;

B :	B AND B { $$ = KObject::_and($1, $3); }
  | B OR B { $$ = KObject::_or($1, $3); }
  | E

E : E '+' T 	{ $$ = KObject::add($1, $3); }
  | E '-' T 	{ $$ = KObject::sub($1, $3); }
  | T
  ;

T : T '*' F 	{ $$ = KObject::mul($1, $3); }
  | T '/' F 	{ $$ = KObject::div($1, $3); }
  | F
  ;

F : '(' B ')' 	{ $$ = $2; }
  | '-' F 		{ $$ = KObject::neg($2); }
  | INTEGER		{ $$ = $1; }
  | REAL		{ $$ = $1; }
  | STRING		{ $$ = $1; }
  | boolean		{ $$ = $1; }
  ;

boolean : TRUE { $$ = $1; }
	| FALSE { $$ = $1; }
	;

%%

/*

Todo mode interpretor live: ./Keepi (+prompt+reponse a chaque input comme python);
 or mode input from file: ./Keepi file.kp

*/

int		main(int ac, const char* av[])
{
	Keepi k(ac > 1);
	__keepi = &k;
	while (yyparse() != 42);
	return EXIT_SUCCESS;
}
