/*	Definition section */
%{
    #include <stdio.h>
    #include <string.h>
	#include "global.h"
    #include <stdbool.h>

typedef struct Entry Entry;
struct Entry {  //表中的一行
    int index;
    Value *id_ptr;
    Entry *next;
	char *Kind;
	int Scope;
	char *Attribute;
};

typedef struct Header Header;
struct Header { //一張表
    int depth;
	int entry_num;
    Entry *table_root;
    Entry *table_tail;
    Header *pre;
};
Header *header_root = NULL;
Header *cur_header = NULL;
int depth = 0;

extern int yylineno;
extern int yylex();
extern char* yytext;   // Get current token from lex
extern char buf[256];  // Get current code line from lex

/* Symbol table function - you can add new function if needed. */
int lookup_symbol(const Header *header, const char *id);
Header* create_symbol();
void insert_symbol(Header *header, Value *id_ptr);
void dump_symbol(const Header *header);

%}

/* Use variable or self-defined structure to represent
 * nonterminal and token type
 */
%union {
    struct Value val;
}

/* Token without return */
%token INC DEC MTE LTE EQ 
%token NE ADDASGN SUBASGN MULASGN DIVASGN MODASGN
%token AND OR STR_TYPE
%token PRINT IF ELSE FOR WHILE INT FLOAT VOID BOOL
%token TRUE FALSE RET CONT BREAK

/* Token with return, which need to sepcify type */
%token <val> I_CONST F_CONST STRING ID

/* Nonterminal with return, which need to sepcify type */
%type <val> primary_expression postfix_expression argument_expression_list unary_expression cast_expression 
%type <val> multiplicative_expression additive_expression shift_expression relational_expression
%type <val> equality_expression and_expression exclusive_or_expression inclusive_or_expression logical_and_expression
%type <val> logical_or_expression conditional_expression assignment_expression expression constant_expression declaration 
%type <val> init_declarator_list init_declarator declarator direct_declarator parameter_type_list parameter_list
%type <val> parameter_declaration identifier_list type_name abstract_declarator direct_abstract_declarator initializer
%type <val> initializer_list statement labeled_statement compound_statement declaration_list statement_list expression_statement
%type <val> selection_statement iteration_statement jump_statement external_declaration function_definition

/* Yacc will start at this nonterminal */
%start program

/* Grammar section */
%%

primary_expression
	: ID
	| I_CONST 
    | F_CONST
	| '"' STRING '"'
	| '(' expression ')'
	;

postfix_expression
	: primary_expression
	| postfix_expression '[' expression ']'
	| postfix_expression '(' ')'
	| postfix_expression '(' argument_expression_list ')'
	| postfix_expression '.' ID
	| postfix_expression INC
	| postfix_expression DEC
	;

argument_expression_list
	: assignment_expression
	| argument_expression_list ',' assignment_expression
	;

unary_expression
	: postfix_expression
	| INC unary_expression
	| DEC unary_expression
	| unary_operator cast_expression
	;

unary_operator
	: '&'
	| '*'
	| '+'
	| '-'
	| '~'
	| '!'
	;

cast_expression
	: unary_expression
	| '(' type_name ')' cast_expression
	;

multiplicative_expression
	: cast_expression
	| multiplicative_expression '*' cast_expression
	| multiplicative_expression '/' cast_expression
	| multiplicative_expression '%' cast_expression
	;

additive_expression
	: multiplicative_expression
	| additive_expression '+' multiplicative_expression
	| additive_expression '-' multiplicative_expression
	;

shift_expression
	: additive_expression
	;

relational_expression
	: shift_expression
	| relational_expression '<' shift_expression
	| relational_expression '>' shift_expression
	| relational_expression LTE shift_expression
	| relational_expression MTE shift_expression
	;

equality_expression
	: relational_expression
	| equality_expression EQ relational_expression
	| equality_expression NE relational_expression
	;

and_expression
	: equality_expression
	| and_expression '&' equality_expression
	;

exclusive_or_expression
	: and_expression
	| exclusive_or_expression '^' and_expression
	;

inclusive_or_expression
	: exclusive_or_expression
	| inclusive_or_expression '|' exclusive_or_expression
	;

logical_and_expression
	: inclusive_or_expression
	| logical_and_expression AND inclusive_or_expression
	;

logical_or_expression
	: logical_and_expression
	| logical_or_expression OR logical_and_expression
	;

conditional_expression
	: logical_or_expression
	| logical_or_expression '?' expression ':' conditional_expression
	;

assignment_expression
	: conditional_expression
	| unary_expression assignment_operator assignment_expression
	;

assignment_operator
	: '='
	| MULASGN
	| DIVASGN
	| MODASGN
	| ADDASGN
	| SUBASGN
	;

expression
	: assignment_expression
	| expression ',' assignment_expression
	| TRUE
	| FALSE
	| PRINT '(' print_arg ')'
	;

print_arg
	: '"' STRING '"' 
	| ID
	;

constant_expression
	: conditional_expression
	;

declaration
	: declaration_specifiers ';'
	| declaration_specifiers init_declarator_list ';'
	;

declaration_specifiers
	: type_specifier
	| type_specifier declaration_specifiers
	;

init_declarator_list
	: init_declarator
	| init_declarator_list ',' init_declarator
	;

init_declarator
	: declarator
	| declarator '=' initializer
	;

type_specifier
	: VOID
	| INT
	| FLOAT
	| BOOL 
	| STR_TYPE
	;

specifier_qualifier_list
	: type_specifier specifier_qualifier_list
	| type_specifier
	;

declarator
	: pointer direct_declarator
	| direct_declarator
	;

direct_declarator
	: ID
	| '(' declarator ')'
	| direct_declarator '[' constant_expression ']'
	| direct_declarator '[' ']'
	| direct_declarator '(' parameter_type_list ')'
	| direct_declarator '(' identifier_list ')'
	| direct_declarator '(' ')'
	;

pointer
	: '*'
	| '*' pointer
	;

parameter_type_list
	: parameter_list
	;

parameter_list
	: parameter_declaration
	| parameter_list ',' parameter_declaration
	;

parameter_declaration
	: declaration_specifiers declarator
	| declaration_specifiers abstract_declarator
	| declaration_specifiers
	;

identifier_list
	: ID
	| identifier_list ',' ID
	;

type_name
	: specifier_qualifier_list
	| specifier_qualifier_list abstract_declarator
	;

abstract_declarator
	: pointer
	| direct_abstract_declarator
	| pointer direct_abstract_declarator
	;

direct_abstract_declarator
	: '(' abstract_declarator ')'
	| '[' ']'
	| '[' constant_expression ']'
	| direct_abstract_declarator '[' ']'
	| direct_abstract_declarator '[' constant_expression ']'
	| '(' ')'
	| '(' parameter_type_list ')'
	| direct_abstract_declarator '(' ')'
	| direct_abstract_declarator '(' parameter_type_list ')'
	;

initializer
	: assignment_expression
	| '{' initializer_list '}'
	| '{' initializer_list ',' '}'
	;

initializer_list
	: initializer
	| initializer_list ',' initializer
	;

statement
	: labeled_statement
	| compound_statement
	| expression_statement
	| selection_statement
	| iteration_statement
	| jump_statement
	;

labeled_statement
	: ID ':' statement
	;

compound_statement
	: '{' '}'
	| '{' statement_list '}'
	| '{' declaration_list '}'
	| '{' declaration_list statement_list '}'
	;

declaration_list
	: declaration
	| declaration_list declaration
	;

statement_list
	: statement
	| statement_list statement
	;

expression_statement
	: ';'
	| expression ';'
	;

selection_statement
	: IF '(' expression ')' statement
	| IF '(' expression ')' statement ELSE statement
	;

iteration_statement
	: WHILE '(' expression ')' statement
	| FOR '(' expression_statement expression_statement ')' statement
	| FOR '(' expression_statement expression_statement expression ')' statement
	;

jump_statement
	: CONT ';'
	| BREAK ';'
	| RET ';'
	| RET expression ';'
	;

program
	: external_declaration
	| program external_declaration
	;

external_declaration
	: function_definition
	| declaration
	;

function_definition
	: declaration_specifiers declarator declaration_list compound_statement
	| declaration_specifiers declarator compound_statement
	| declarator declaration_list compound_statement
	| declarator compound_statement
	;

%%

/* C code section */
int main(int argc, char** argv)
{
    extern FILE *yyin;
    yyin = fopen(argv[1],"r");
    //yylineno = 0;
	printf("1: ");
    yyparse();
    extern int line_cnt;
	int act_line=line_cnt-2;
	printf("\nTotal lines: %d \n",act_line);

    return 0;
}

void yyerror(char *s)
{
    printf("\n|-----------------------------------------------|\n");
    printf("| Error found in line %d: %s\n", yylineno, buf);
    printf("| %s", s);
    printf("\n|-----------------------------------------------|\n\n");
}

Header* create_symbol() 
{
	Header *ptr = malloc(sizeof(Header)); //創新的table
	ptr->depth=depth++;
	ptr->table_root=malloc(sizeof(Entry));
	ptr->table_root->next = NULL;
	ptr->table_tail = ptr->table_root;
	ptr->pre = NULL;
	ptr->entry_num=-1;
	return ptr;
}
void insert_symbol(Header *header, Value *id_ptr) 
{
	if (cur_header == NULL) //無table
	{
        cur_header = create_symbol();
        header_root = cur_header;
        header = cur_header;
    }
    if (lookup_symbol(cur_header, id_ptr->id_name) == NULL) 
	{
        printf("Insert a symbol: %s\n", id_ptr->id_name);
        Entry *tmp = malloc(sizeof(Entry));
		cur_header->entry_num=(cur_header->entry_num)+1;
        tmp->index = cur_header->entry_num;
        tmp->id_ptr = id_ptr;
        tmp->next = NULL;
        header->table_tail->next = tmp;
        header->table_tail = header->table_tail->next;
    } 
	else 
	{
        char errmsg[64];
        sprintf(errmsg, "redefined variable \'%s\'", id_ptr->id_name);
        yyerror(errmsg);
    }
}
int lookup_symbol(const Header *header, const char *id) 
{
	if (header->table_root == NULL) 
	{
        return NULL;
    }
    Entry *cur = header->table_root->next;
    while (cur != NULL)
	{
        if (strcmp(cur->id_ptr->id_name, id) == 0)
		{
            return cur->index;
        }
        cur = cur->next;
    }
    return NULL;
}
void dump_symbol(const Header *header) 
{
    printf("\n%-10s%-10s%-12s%-10s%-10s%-10s\n\n",
           "Index", "Name", "Kind", "Type", "Scope", "Attribute");
	if (header->table_root == NULL) 
	{
        return;
    }

    Entry *cur = header->table_root->next;
    while (cur != NULL)
	{
		printf("\n%-10d%-10s%-12s%-10s%-10d%-10s\n",
           cur->index, cur->id_ptr->id_name, cur->Kind, cur->id_ptr->val_ptr->type, cur->Scope, cur->Attribute);
		   
        Entry *tmp = cur;
        cur = cur->next;
        free(tmp->id_ptr->val_ptr);
        tmp->id_ptr->val_ptr = NULL;
        free(tmp->id_ptr);
        tmp->id_ptr = NULL;
        free(tmp);
        tmp = NULL;
    }

}
