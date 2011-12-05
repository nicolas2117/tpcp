%{
#include <cstddef>
#include <string>
#include <queue>
#include <TableDesSymboles.hpp>
#include <SymboleProgramme.hpp>
#include <SymboleFonction.hpp>
#include <SymboleProcedure.hpp>
#include <Code3ad.hpp>
#include <SymboleVariable.hpp>
#include <SymboleParametre.hpp>
#include <iostream>
#include <Type.hpp>
#include <GenerateurType.hpp>
#include <Instruction.hpp>
#include <ConteneurCode.hpp>
#include <Operande.hpp>

extern int yyerror ( char* );
extern int yylex ();

TableDesSymboles tableDesSymbolesDuProgramme;
TableDesSymboles *tableDesSymbolesCourante = &tableDesSymbolesDuProgramme;

ConteneurCode conteneurCodeDuProgramme;
ConteneurCode *conteneurCodeCourant = &conteneurCodeDuProgramme;

SymboleProcedure *symboleProcedure;
SymboleFonction *symboleFonction;

Symbole *symbole;

TableDesSymboles *tableDesSymboles;
bool nouvelleFonction = false; // Nouvelle fonction ou procédure

int arite = 0;

std::queue<int> fileId; // File d'identifiant

%}

%union{
	Operande *operande;
    int id;
	int valeurInteger;
    double valeurReal;
    bool valeurBoolean;
    std::string* valeurString;
    Type *type;
	
}

%token KW_PROGRAM
%token KW_CONST
%token KW_TYPE
%token KW_VAR
%token KW_ARRAY
%token KW_OF
%token KW_RECORD
%token KW_BEGIN
%token KW_END
%token KW_DIV
%token KW_MOD
%token KW_AND
%token KW_OR
%token KW_XOR
%token KW_NOT
%token KW_IF
%token KW_THEN
%token KW_ELSE
%token KW_WHILE
%token KW_DO
%token KW_REPEAT
%token KW_UNTIL
%token KW_FOR
%token KW_TO
%token KW_DOWNTO
%token KW_PROC
%token KW_FUNC
%token KW_NIL
%token <type> KW_INTEGER
%token <type> KW_REAL
%token <type> KW_BOOLEAN
%token <type> KW_CHAR
%token <type> KW_STRING

%token SEP_SCOL
%token SEP_DOT
%token SEP_DOTS
%token SEP_DOTDOT
%token SEP_COMMA
%token SEP_CO
%token SEP_CF
%token SEP_PO
%token SEP_PF

%token OP_EQ
%token OP_NEQ
%token OP_LT
%token OP_LTE
%token OP_GT
%token OP_GTE
%token OP_ADD
%token OP_SUB
%token OP_MUL
%token OP_SLASH
%token OP_EXP
%token OP_PTR
%token OP_AFFECT

%token <id> TOK_IDENT
%token <valeurInteger> TOK_INTEGER
%token <valeurReal> TOK_REAL
%token <valeurBoolean> TOK_BOOLEAN
%token <valeurString> TOK_STRING

%type <id> FuncIdent ProcIdent
%type <type> Type UserType BaseType FuncResult
%type <operande> Expression MathExpr CompExpr BoolExpr AtomExpr VarExpr Call

%start Program

%nonassoc OP_EQ OP_NEQ OP_GT OP_LT OP_GTE OP_LTE
%left OP_ADD OP_SUB KW_OR KW_XOR
%left OP_MUL OP_SLASH KW_AND KW_DIV KW_MOD
%right KW_NOT OP_NEG OP_POS
%left OP_EXP
%nonassoc OP_PTR
%nonassoc OP_DOT
%left SEP_CO

%nonassoc KW_IFX
%nonassoc KW_ELSE

%%

Program	        :   ProgramHeader SEP_SCOL Block SEP_DOT
				;

ProgramHeader   :   KW_PROGRAM TOK_IDENT 
                    { 
                        tableDesSymbolesDuProgramme.ajouterSymbole(new SymboleProgramme($2)); 
						tableDesSymbolesDuProgramme.setIdContexte($2);
                    }
				;

Block			:	BlockDeclConst BlockDeclType BlockDeclVar BlockDeclFunc BlockCode
				;

/*******************************************************************************

	Déclaration des constantes.

*******************************************************************************/

BlockDeclConst	:	KW_CONST ListDeclConst
			 	|
			 	;

ListDeclConst	:	ListDeclConst DeclConst
			 	|	DeclConst
			 	;

DeclConst		:	TOK_IDENT OP_EQ Expression SEP_SCOL
			 	;

/*******************************************************************************

	Déclaration des types.

*******************************************************************************/

BlockDeclType	:	KW_TYPE ListDeclType
			 	|
			 	;

ListDeclType	:	ListDeclType DeclType
			 	|	DeclType
			 	;

DeclType		:	TOK_IDENT OP_EQ Type SEP_SCOL
			 	;

/*******************************************************************************

	Déclaration des variables.

*******************************************************************************/

BlockDeclVar	:	KW_VAR ListDeclVar
			 	|
			 	;

ListDeclVar		:	ListDeclVar DeclVar
			 	|	DeclVar
			 	;

DeclVar			:	ListIdent SEP_DOTS Type SEP_SCOL 
                    { 
                        while(!fileId.empty())
                            { 
                                tableDesSymbolesCourante->ajouterSymbole(new SymboleVariable(fileId.front(), $3));                      
                                fileId.pop();
                            } 
                    }
			 	;

ListIdent		:	ListIdent SEP_COMMA TOK_IDENT 
                    { 
                        fileId.push($3); 
                    }
			 	|	TOK_IDENT 
                    { 
                        fileId.push($1); 
                    }
			 	;

/*******************************************************************************

	Définition des fonctions/procédures.

*******************************************************************************/

BlockDeclFunc	:	ListDeclFunc SEP_SCOL
			 	|
			 	;

ListDeclFunc	:	ListDeclFunc SEP_SCOL DeclFunc
			 	|	DeclFunc
			 	;

DeclFunc		:	ProcDecl
			 	|	FuncDecl
			 	;

/*******************************************************************************

	Définition des procédures.

*******************************************************************************/

ProcDecl		:	ProcHeader SEP_SCOL Block
					{
						// On quitte la procédure, on revient à la table des symboles parent.
						tableDesSymbolesCourante = tableDesSymbolesCourante->getParent();
					}
			 	;

ProcHeader		:	ProcIdent
					{
						// Déclaration d'une procedure sans parametre.
						tableDesSymboles = new TableDesSymboles(tableDesSymbolesCourante);
						tableDesSymboles->setIdContexte($1);
						symboleProcedure =  new SymboleProcedure($1, 0, tableDesSymboles);
						tableDesSymbolesCourante->ajouterSymbole(symboleProcedure);
						tableDesSymbolesCourante = symboleProcedure->getTableDesSymboles();  
					}
			 	|	ProcIdent FormalArgs
					{
						// Déclaration d'une procedure avec parametre.
						symboleProcedure =  new SymboleProcedure($1, arite, tableDesSymbolesCourante);
						tableDesSymbolesCourante->setIdContexte($1);
						tableDesSymbolesCourante->getParent()->ajouterSymbole(symboleProcedure);
						nouvelleFonction = false;
						arite = 0;
					}
			 	;

ProcIdent		:	KW_PROC TOK_IDENT {$$ = $2}
			 	;

/*******************************************************************************

	Liste des arguments d'une fonction/procédure.

*******************************************************************************/

FormalArgs		:	SEP_PO ListFormalArgs SEP_PF
			 	;

ListFormalArgs	:	ListFormalArgs SEP_SCOL FormalArg
			 	|	FormalArg
			 	;

FormalArg		:	ValFormalArg
			 	|	VarFormalArg
			 	;

ValFormalArg	:	ListIdent SEP_DOTS BaseType
					{
						if (!nouvelleFonction) 
						{
							nouvelleFonction = true;
							tableDesSymbolesCourante = new TableDesSymboles(tableDesSymbolesCourante);
						}
						// Arguments passé par valeur 
                        while(!fileId.empty())
                            { 
                                tableDesSymbolesCourante->ajouterSymbole(new SymboleParametre(fileId.front(), $3, true));                      
                                fileId.pop();
                                arite++;
                            } 
					}
			 	;

VarFormalArg	:	KW_VAR ListIdent SEP_DOTS BaseType
					{
						if (!nouvelleFonction) 
						{
							nouvelleFonction = true;
							tableDesSymbolesCourante = new TableDesSymboles(tableDesSymbolesCourante);
						}
						// Arguments passé par adresse
                        while(!fileId.empty())
                            { 
                                tableDesSymbolesCourante->ajouterSymbole(new SymboleParametre(fileId.front(), $4, false));                      
                                fileId.pop();
                                arite++;
                            } 
					}
			 	;

/*******************************************************************************

	Définition des fonctions.

*******************************************************************************/

FuncDecl		:	FuncHeader SEP_SCOL Block
					{
						// On quitte la fonction, on revient à la table des symboles parent.
						tableDesSymbolesCourante = tableDesSymbolesCourante->getParent();
					}
			 	;

FuncHeader		:	FuncIdent FuncResult
					{
						// Déclaration d'une fonction sans parametre.
						tableDesSymboles = new TableDesSymboles(tableDesSymbolesCourante);
						tableDesSymboles->setIdContexte($1);
						symboleFonction = new SymboleFonction($1, $2, 0, tableDesSymboles);
						tableDesSymbolesCourante->ajouterSymbole(symboleFonction);
						tableDesSymbolesCourante = symboleFonction->getTableDesSymboles();  
					}
			 	|	FuncIdent FormalArgs FuncResult
					{
						// Déclaration d'une fonction avec parametres.
						symboleFonction =  new SymboleFonction($1, $3, arite, tableDesSymbolesCourante);
						tableDesSymbolesCourante->setIdContexte($1);
						tableDesSymbolesCourante->getParent()->ajouterSymbole(symboleFonction);
						nouvelleFonction = false;
						arite = 0;
					}
			 	;

FuncIdent		:	KW_FUNC TOK_IDENT {$$ = $2}
			 	;

FuncResult		:	SEP_DOTS BaseType {$$ = $2}
			 	;

/*******************************************************************************

	Types.

*******************************************************************************/

Type			:	UserType {$$ = $1}
			 	|	BaseType {$$ = $1}
			 	;

UserType		:	EnumType {$$ = 0}
			 	|	InterType {$$ = 0}
			 	|	ArrayType {$$ = 0}
			 	|	RecordType {$$ = 0}
			 	|	PointerType {$$ = 0}
			 	;

BaseType	    :   TOK_IDENT {$$ = 0}
			 	|	KW_INTEGER {$$ = GenerateurType::creerTypeEntier();}
				|	KW_REAL {$$ = GenerateurType::creerTypeReel();}
				|	KW_BOOLEAN {$$ = GenerateurType::creerTypeBool();}
				|	KW_CHAR {$$ = GenerateurType::creerTypeCaractere();}
				|	KW_STRING {$$ = 0}
				;

EnumType		:	SEP_PO ListEnumValue SEP_PF
			 	;

ListEnumValue	:	ListEnumValue SEP_COMMA TOK_IDENT
			 	|	TOK_IDENT
			 	;

InterType		:	InterBase SEP_DOTDOT InterBase
			 	;

InterBase		:	NSInterBase
			 	|	OP_SUB NSInterBase
			 	;

NSInterBase		:	TOK_IDENT
			 	|	TOK_INTEGER
			 	;

ArrayType		:	KW_ARRAY SEP_CO ListArrayIndex SEP_CF KW_OF Type
			 	;

ListArrayIndex	:	ListArrayIndex SEP_COMMA ArrayIndex
				|	ArrayIndex
				;

ArrayIndex		:	TOK_IDENT
			 	|	InterType
			 	;

RecordType		:	KW_RECORD RecordFields KW_END
			 	;

RecordFields	:	RecordFields SEP_SCOL RecordField
			 	|	RecordField
			 	;

RecordField		:	ListIdent SEP_DOTS Type
			 	;

PointerType		:	OP_PTR Type
			 	;

/*******************************************************************************

	Code.

*******************************************************************************/

BlockCode		:	KW_BEGIN ListInstr KW_END
				|	KW_BEGIN ListInstr SEP_SCOL KW_END
				|	KW_BEGIN KW_END
			 	;

ListInstr		:	ListInstr SEP_SCOL Instr
			 	|	Instr
			 	;

Instr			:	KW_WHILE Expression KW_DO Instr
			 	|	KW_REPEAT ListInstr KW_UNTIL Expression
			 	|	KW_FOR TOK_IDENT OP_AFFECT Expression ForDirection Expression KW_DO Instr
			 	|	KW_IF Expression KW_THEN Instr %prec KW_IFX
			 	|	KW_IF Expression KW_THEN Instr KW_ELSE Instr
			 	|	VarExpr OP_AFFECT Expression
			 	|	Call
			 	|	BlockCode
			 	;

ForDirection	:	KW_TO
			 	|	KW_DOWNTO
			 	;

Expression		:	MathExpr
			 	|	CompExpr
			 	|	BoolExpr
			 	|	AtomExpr
			 	|	VarExpr
				|	Call
			 	;

MathExpr		:	Expression OP_ADD Expression
					{
						conteneurCodeCourant->ajouterCode(new Instruction($1, $3, NULL, OPCODE_ADD));
						//$$ = $1;
					}
			 	|	Expression OP_SUB Expression
					{
						//conteneurCodeCourant->ajouterCode(new Instruction());
					}
			 	|	Expression OP_MUL Expression
					{
						//conteneurCodeCourant->ajouterCode(new Instruction());
					}
			 	|	Expression OP_SLASH Expression
			 	|	Expression KW_DIV Expression
					{
						//conteneurCodeCourant->ajouterCode(new Instruction());
					}
			 	|	Expression KW_MOD Expression
			 	|	Expression OP_EXP Expression
			 	|	OP_SUB Expression %prec OP_NEG
			 	|	OP_ADD Expression %prec OP_POS
			 	;

CompExpr		:	Expression OP_EQ Expression
			 	|	Expression OP_NEQ Expression
			 	|	Expression OP_LT Expression
			 	|	Expression OP_LTE Expression
			 	|	Expression OP_GT Expression
			 	|	Expression OP_GTE Expression
			 	;

BoolExpr		:	Expression KW_AND Expression
					{
						//conteneurCodeCourant->ajouterCode(new Instruction());
					}
			 	|	Expression KW_OR Expression
			 		{
						//conteneurCodeCourant->ajouterCode(new Instruction());
					}
			 	|	Expression KW_XOR Expression
					{
						//conteneurCodeCourant->ajouterCode(new Instruction());
					}
			 	|	KW_NOT Expression
					{
						//conteneurCodeCourant->ajouterCode(new Instruction());
					}
			 	;

AtomExpr		:	SEP_PO Expression SEP_PF { $$ = 0 }
			 	|	TOK_INTEGER { $$ = new Operande(new Valeur($1)); }
			 	|	TOK_REAL { $$ = new Operande(new Valeur($1)); }
			 	|	TOK_BOOLEAN { $$ = new Operande(new Valeur($1)); }
			 	|	KW_NIL { $$ = 0 }
			 	|	TOK_STRING { $$ = 0 }
			 	;

VarExpr			:	TOK_IDENT 
					{
						symbole = tableDesSymbolesCourante->getSymbole($1);
						if(symbole == NULL) 
						{
							yyerror("Identifiant non déclaré");
						}
						$$ = new Operande($1);
					}
				|	VarExpr SEP_CO ListIndices SEP_CF
				|	VarExpr SEP_DOT TOK_IDENT %prec OP_DOT
				|	VarExpr OP_PTR
				;

/*******************************************************************************

	Appel de fonction.

*******************************************************************************/

Call			:	TOK_IDENT Parameters
					{
						// Appel d'une fonction
						// On vérifie que la fonction existe
						symbole = (SymboleFonction *) tableDesSymbolesCourante->getSymbole($1);
						if (symbole == NULL)
						{
							yyerror("La fonction n'est pas déclaré");
						}
						/*if (typeid(symbole) == typeid())
						{
		
						}*/
						// On vérifie le nombre d'arguments de la fonction
						/*if (symbole->getArite() != arite)
						{
							yyerror("Mauvaise arite de la fonction");
						}*/
						arite = 0;
					}
				;

Parameters		:	SEP_PO ListParameters SEP_PF
				|	SEP_PO SEP_PF
				;

ListIndices		:	ListIndices SEP_COMMA Expression
				|	Expression
				;

ListParameters	:	ListParameters SEP_COMMA Expression
					{
						arite++;
					}
				|	Expression
					{
						arite++;
					}
				;

%%
