/*	Definition section */
%{
    #include <stdio.h>
    #include <string.h>
    #include <stdbool.h>
extern int yylineno;
extern int yylex();
extern char* yytext;   // Get current token from lex
extern char buf[256];  // Get current code line from lex

/* Symbol table function - you can add new function if needed. */
int lookup_symbol();
void create_symbol();
void insert_symbol();
void dump_symbol();

%}

/* Use variable or self-defined structure to represent
 * nonterminal and token type
 */
%union {
    int i_val;
    double f_val;
    char* string;
}

/* Token without return */
%token ADD SUB MUL DIV MOD INC DEC MT LT MTE LTE EQ 
%token NE ASGN ADDASGN SUBASGN MULASGN DIVASGN MODASGN
%token AND OR NOT LB RB LCB RCB LSB RSB COMMA SEMICOLON
%token PRINT IF ELSE WHILE INT FLOAT VOID BOOL
%token TRUE FALSE RET CONT BREAK ID NEWLINE QUOTA FOR

/* Token with return, which need to sepcify type */
%token <i_val> I_CONST
%token <f_val> F_CONST
%token <string> STRING

/* Nonterminal with return, which need to sepcify type */
/*%type <f_val> stat*/

/* Yacc will start at this nonterminal */
%start program

/* Grammar section */
%%

program
    : program stat
    |
;

stat
    : declaration
    /*| compound_stat
    | expression_stat
    | print_func*/
;

declaration
    : /*type ID '=' initializer SEMICOLON
    | type ID SEMICOLON*/
;

/* actions can be taken when meet the token or rule */
/*type
    : INT { $$ = $1; }
    | FLOAT { $$ = $1; }
    | BOOL  { $$ = $1; }
    | STRING { $$ = $1; }
    | VOID { $$ = $1; }
;*/

%%

/* C code section */
int main(int argc, char** argv)
{
    extern FILE *yyin;
    yyin = fopen(argv[1],"r");
    //yylineno = 0;

    yyparse();
    extern int line_cnt;
	printf("\nTotal lines: %d \n",--line_cnt);

    return 0;
}

void yyerror(char *s)
{
    printf("\n|-----------------------------------------------|\n");
    printf("| Error found in line %d: %s\n", yylineno, buf);
    printf("| %s", s);
    printf("\n|-----------------------------------------------|\n\n");
}

void create_symbol() {}
void insert_symbol() {}
int lookup_symbol() {}
void dump_symbol() {
    printf("\n%-10s%-10s%-12s%-10s%-10s%-10s\n\n",
           "Index", "Name", "Kind", "Type", "Scope", "Attribute");
}
