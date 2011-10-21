#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <parser.hpp>
#include <TableDesIdentificateurs.hpp>

extern FILE* yyin;
extern int yyleng;
extern char* yytext;
extern int yylex();
extern int yyparse();
extern TableDesIdentificateurs TDI;

int main(int argc, char *argv[])
{
    yyin = NULL;

    if(argc == 2) {
        yyin = fopen( argv[1], "r" );
        if (yyin == NULL) {
                std::cout << argv[1] << " : Impossible d'ouvrir le fichier"<<std::endl;
                return EXIT_SUCCESS;
        }
    }
    else {
        std::cout << "Utilisation : ding SOURCE.PAS"<<std::endl<<
                     "Compile source.pas."<<std::endl;
        return EXIT_SUCCESS;
    }
    
    yyparse ();
    
    TDI.afficher(std::cout);
    
    return EXIT_SUCCESS;
}
