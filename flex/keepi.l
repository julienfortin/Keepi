%{

#include	<iostream>
#include 	<cstdlib>
#include	"KObject.hpp"
#include 	"keepi.tab.h"

%}

%%

"exit"					{ return EXIT; }
"print"					{ return PRINT; }
"DSYMTAB"				{ return DSYMTAB; }

"true"					{ yylval.obj = new KObject(true); return TRUE; }
"false"					{ yylval.obj = new KObject(false); return FALSE; }

"&&"					{ std::cout<< "AND\n"; return AND; }
"||"					{ std::cout<< "OR\n"; return OR; }

","						{ return COMMA; }

[0-9]*					{ yylval.obj = new KObject((long long int)atoi(yytext)); return INTEGER; }
[0-9]+(\.[0-9]+)		{ yylval.obj = new KObject(atof(yytext)); return REAL; } 

[_a-zA-Z][_a-zA-Z0-9]*	{ 
							yylval.id = new std::string(yytext);
							return IDENTIFIER;
						}

":="					{ return ASSIGN_OP; }

\n 					{ return NL; }
[-+(/)*&|]			{ return yytext[0]; }
[ \t\f\v\n]			{ ; }

\"(\\.|[^"])*\"		{ yylval.obj = new KObject(++yytext); return STRING; }

.					{ std::cerr << "Invalid character" << std::endl; }
%%

int		yywrap() { return 1; }

/*

B :	B '&' E { std::cout << "AND\n"; }
  | B '|' E { std::cout << "OR\n"; }
  | E


  */