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
	char Kind[50];
	int Scope;
	char Attribute[50];
	char type[50];
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
void insert_symbol(Header *header, Value *t_ptr, Value *id_ptr,char *kind);
void dump_symbol(Header *header);
void new_scope();
void dump_scope();
void dump_all_scopes();

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
%type <val> type_specifier declaration_specifiers

/* Yacc will start at this nonterminal */
%start program

/* Grammar section */
%%

primary_expression
	: ID {$$ = yylval.val;printf("333");}
	| I_CONST {$$=yylval.val;}
    | F_CONST {$$=yylval.val;}
	| '"' STRING '"' {$$=yylval.val;}
	| '('expression ')'
	;

postfix_expression
	: primary_expression {$$=$1;}
	| postfix_expression '[' expression ']'
	| postfix_expression '(' ')'
	| postfix_expression '('argument_expression_list ')'
	| postfix_expression '.' ID
	| postfix_expression INC
	| postfix_expression DEC
	;

argument_expression_list
	: assignment_expression
	| argument_expression_list ',' assignment_expression
	;

unary_expression
	: postfix_expression {$$=$1;}
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
	: unary_expression {$$=$1;}
	| '(' type_name ')' cast_expression
	;

multiplicative_expression
	: cast_expression {$$=$1;}
	| multiplicative_expression '*' cast_expression
	| multiplicative_expression '/' cast_expression
	| multiplicative_expression '%' cast_expression
	;

additive_expression
	: multiplicative_expression {$$=$1;}
	| additive_expression '+' multiplicative_expression
	| additive_expression '-' multiplicative_expression
	;

shift_expression
	: additive_expression {$$=$1;}
	;

relational_expression
	: shift_expression {$$=$1;}
	| relational_expression '<' shift_expression
	| relational_expression '>' shift_expression
	| relational_expression LTE shift_expression
	| relational_expression MTE shift_expression
	;

equality_expression
	: relational_expression {$$=$1;}
	| equality_expression EQ relational_expression
	| equality_expression NE relational_expression
	;

and_expression
	: equality_expression {$$=$1;}
	| and_expression '&' equality_expression
	;

exclusive_or_expression
	: and_expression {$$=$1;}
	| exclusive_or_expression '^' and_expression
	;

inclusive_or_expression
	: exclusive_or_expression {$$=$1;}
	| inclusive_or_expression '|' exclusive_or_expression
	;

logical_and_expression
	: inclusive_or_expression {$$=$1;}
	| logical_and_expression AND inclusive_or_expression
	;

logical_or_expression
	: logical_and_expression {$$=$1;}
	| logical_or_expression OR logical_and_expression
	;

conditional_expression
	: logical_or_expression {$$=$1;}
	| logical_or_expression '?' expression ':' conditional_expression
	;

assignment_expression
	: conditional_expression {$$=$1;}
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
	| declaration_specifiers init_declarator_list ';' {Value *v1=&$1;Value *v2=&$2; insert_symbol(cur_header,v1,v2,"variable");}
	;

declaration_specifiers
	: type_specifier {$$=$1;}
	| type_specifier declaration_specifiers  
	;

init_declarator_list
	: init_declarator {$$=$1;}
	| init_declarator_list ',' init_declarator
	;

init_declarator
	: declarator {$$=$1;}
	| declarator '=' initializer {$$=$1;}
	;

type_specifier
	: VOID { $$ = yylval.val;printf("222"); }
	| INT { $$ = yylval.val;printf("222"); }
	| FLOAT { $$ = yylval.val;printf("222"); }
	| BOOL  { $$ = yylval.val;printf("222");}
	| STR_TYPE { $$ = yylval.val;printf("222"); }
	;

specifier_qualifier_list
	: type_specifier specifier_qualifier_list 
	| type_specifier
	;

declarator
	: pointer direct_declarator
	| direct_declarator {$$=$1;}
	;

direct_declarator
	: ID {$$ = yylval.val;printf("111");}
	| '(' declarator ')'
	| direct_declarator '[' constant_expression ']'
	| direct_declarator '[' ']'
	| direct_declarator '(' {new_scope();} parameter_type_list ')'
	| direct_declarator '(' identifier_list ')'
	| direct_declarator '(' {new_scope();}  ')'
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
	: declaration_specifiers declarator {Value *v1=&$1;Value *v2=&$2; insert_symbol(cur_header,v1,v2,"parameter");}
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
	: assignment_expression {$$=$1;}
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
	: function_definition{dump_scope();}
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

	yylineno = 0;
    yyparse();
    extern int line_cnt;

	dump_all_scopes();
	printf("\nTotal lines: %d \n",yylineno);

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
	ptr->depth=depth;
	depth++;
	ptr->table_root=malloc(sizeof(Entry));
	ptr->table_root->next = NULL;
	ptr->table_tail = ptr->table_root;
	ptr->pre = NULL;
	ptr->entry_num=-1;
	return ptr;
}
void insert_symbol(Header *header, Value *t_ptr, Value *id_ptr,char *kind) 
{
	if (cur_header == NULL) //無table
	{
        cur_header = create_symbol();
        header_root = cur_header;
        header = cur_header;
    }
    if (lookup_symbol(cur_header, id_ptr->id_name) == NULL) 
	{
        
        Entry *tmp = malloc(sizeof(Entry));
		header->entry_num=(header->entry_num)+1;
        tmp->index = header->entry_num;
        tmp->id_ptr = id_ptr;
		printf("Insert a symbol: %s in table %d\n", tmp->id_ptr->id_name, header->depth);
        tmp->next = NULL;
		tmp->Scope=header->depth;
		strcpy(tmp->Kind,kind);
		if(strcmp(kind,"function")==0)
		{

		}
		else //只有kind為function的,Attribute才有內容
		{
			strcat(tmp->Attribute,"");
		}

		//TYPE
		if(t_ptr->type==V_T)
		{
			strcat(tmp->type,"void");
		}	
		else if(t_ptr->type==I_T)
		{
			strcat(tmp->type,"int");
		}	
		else if(t_ptr->type==F_T)
		{
			strcat(tmp->type,"float");
		}
		else if(t_ptr->type==S_T)
		{
			strcat(tmp->type,"string");
		}
		else if(t_ptr->type==B_T)
		{
			strcat(tmp->type,"bool");
		}

        header->table_tail->next = tmp;
        header->table_tail = header->table_tail->next;
    } 
	else 
	{
		//printf("lookup_symbol=%d\n",lookup_symbol(cur_header, id_ptr->id_name));
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
		printf("\nindex:%d\n",cur->index);
		printf("\n%s\n",id);
		printf("\n%s\n",cur->id_ptr->id_name);
        if (strcmp(cur->id_ptr->id_name, id) == 0)
		{
            return cur->index;
        }
        cur = cur->next;
    }
    return NULL;
}
void dump_symbol(Header *header) 
{
    printf("\n\n%-10s%-10s%-12s%-10s%-10s%-10s\n\n",
           "Index", "Name", "Kind", "Type", "Scope", "Attribute");
	if (header->table_root == NULL) 
	{
        return;
    }

    Entry *cur = header->table_root->next;
    while (cur != NULL)
	{
		printf("\n%-10d%-10s%-12s%-10s%-10d%-10s",
		cur->index, cur->id_ptr->id_name, cur->Kind, cur->type, cur->Scope, cur->Attribute);
		//printf("\n%d %s\n",cur->index, cur->id_ptr->id_name);
        Entry *tmp = cur;
        cur = cur->next;
		
		/*free(tmp->id_ptr->val_ptr);
        tmp->id_ptr->val_ptr = NULL;
		
		free(tmp->id_ptr);
        tmp->id_ptr = NULL;*/
		
		free(tmp);
        tmp = NULL;
    }
	printf("\n");
}

void new_scope()
{
    Header *ptr = create_symbol();
    ptr->pre = cur_header;
    cur_header = ptr;
}

void dump_scope()
{
    Header *tmp = cur_header;
	printf("\ndump_scope: %d",tmp->depth);
    cur_header = cur_header->pre;
    dump_symbol(tmp);
    free(tmp);
    tmp = NULL;
    depth--;
}

void dump_all_scopes()
{
	while (cur_header != NULL) 
	{
        dump_scope();
    }
}

