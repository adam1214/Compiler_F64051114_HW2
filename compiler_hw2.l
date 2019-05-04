/* Definition section */
%{
	#include "y.tab.h"
	#include <stdio.h>
	#include <stdlib.h>
	void C_comment();
	void CPP_comment();
	void str_const();
	int line_cnt=1;
	int comm_cnt=0;

	extern YYSTYPE yylval; //YYSTYPE
	char buf[256];

	/* This macro is used to record code line */
	#define CONCAT { strncat(buf, yytext, 256 - strlen(buf) - 1); }
%}

/* Define regular expression label */

letter [a-zA-Z]
digit [0-9]
id {letter}+({letter}|{digit})*
number {digit}+

%option yylineno

%x COMMENT STRING_STATE

/* Rules section */
%%

"+" 	{ /*printf("%s \t ADD\n", yytext);*/ if(line_cnt==1){printf("1: ");}  printf("%s", yytext); return ADD;}
"-"		{ /*printf("%s \t SUB\n", yytext);*/ if(line_cnt==1){printf("1: ");}  printf("%s", yytext); return SUB;}
"*"		{ /*printf("%s \t MUL\n", yytext);*/ if(line_cnt==1){printf("1: ");}  printf("%s", yytext); return MUL;}
"/"		{ /*printf("%s \t DIV\n", yytext);*/ if(line_cnt==1){printf("1: ");}  printf("%s", yytext); return DIV;}
"%"		{ /*printf("%s \t MOD\n", yytext);*/ if(line_cnt==1){printf("1: ");}  printf("%s", yytext); return MOD;}
"++"		{ /*printf("%s \t INC\n", yytext);*/ if(line_cnt==1){printf("1: ");}  printf("%s", yytext); return INC;}
"--"		{ /*printf("%s \t DEC\n", yytext);*/ if(line_cnt==1){printf("1: ");}  printf("%s", yytext); return DEC;}
">"		{ /*printf("%s \t MT\n", yytext);*/ if(line_cnt==1){printf("1: ");}  printf("%s", yytext); return MT;}
"<"		{ /*printf("%s \t LT\n", yytext);*/ if(line_cnt==1){printf("1: ");}  printf("%s", yytext); return LT;}
">="		{ /*printf("%s \t MTE\n", yytext);*/ if(line_cnt==1){printf("1: ");}  printf("%s", yytext); return MTE;}
"<="		{ /*printf("%s \t LTE\n", yytext);*/ if(line_cnt==1){printf("1: ");}  printf("%s", yytext); return LTE;}
"=="		{ /*printf("%s \t EQ\n", yytext);*/ if(line_cnt==1){printf("1: ");}  printf("%s", yytext); return EQ;}
"!="		{ /*printf("%s \t NE\n", yytext);*/ if(line_cnt==1){printf("1: ");}  printf("%s", yytext); return NE;}
"="		{ /*printf("%s \t ASGN\n", yytext);*/ if(line_cnt==1){printf("1: ");}  printf("%s", yytext); return ASGN;}
"+="		{ /*printf("%s \t ADDASGN\n", yytext);*/ if(line_cnt==1){printf("1: ");}  printf("%s", yytext); return ADDASGN;}
"-="		{ /*printf("%s \t SUBASGN\n", yytext);*/ if(line_cnt==1){printf("1: ");}  printf("%s", yytext); return SUBASGN;}
"*="		{ /*printf("%s \t MULASGN\n", yytext);*/ if(line_cnt==1){printf("1: ");}  printf("%s", yytext); return MULASGN;}
"/="		{ /*printf("%s \t DIVASGN\n", yytext);*/ if(line_cnt==1){printf("1: ");}  printf("%s", yytext); return DIVASGN;}
"%="		{ /*printf("%s \t MODASGN\n", yytext);*/ if(line_cnt==1){printf("1: ");}  printf("%s", yytext); return MODASGN;}
"&&"		{ /*printf("%s \t AND\n", yytext);*/ if(line_cnt==1){printf("1: ");}  printf("%s", yytext); return AND;}
"||"		{ /*printf("%s \t OR\n", yytext);*/ if(line_cnt==1){printf("1: ");}  printf("%s", yytext); return OR;}

"!"		{ /*printf("%s \t NOT\n", yytext);*/ if(line_cnt==1){printf("1: ");}  printf("%s", yytext); return NOT;}
"("		{ /*printf("%s \t LB\n", yytext);*/ if(line_cnt==1){printf("1: ");}  printf("%s", yytext); return LB;}
")"		{ /*printf("%s \t RB\n", yytext);*/ if(line_cnt==1){printf("1: ");}  printf("%s", yytext); return RB;}
"{"		{ /*printf("%s \t LCB\n", yytext);*/ if(line_cnt==1){printf("1: ");}  printf("%s", yytext); return LCB;}
"}"		{ /*printf("%s \t RCB\n", yytext);*/ if(line_cnt==1){printf("1: ");}  printf("%s", yytext); return RCB;}
"["		{ /*printf("%s \t LSB\n", yytext);*/ if(line_cnt==1){printf("1: ");}  printf("%s", yytext); return LSB;}
"]"		{ /*printf("%s \t RSB\n", yytext);*/ if(line_cnt==1){printf("1: ");}  printf("%s", yytext); return RSB;}
","		{ /*printf("%s \t COMMA\n", yytext);*/ if(line_cnt==1){printf("1: ");}  printf("%s", yytext); return COMMA;}
";"		{ /*printf("%s \t SEMICOLON\n", yytext);*/ if(line_cnt==1){printf("1: ");}  printf("%s", yytext); return SEMICOLON;}

"print"		{ /*printf("%s \t PRINT\n", yytext);*/ if(line_cnt==1){printf("1: ");}  printf("%s", yytext); return PRINT;}
"if"		{ /*printf("%s \t IF\n", yytext);*/ if(line_cnt==1){printf("1: ");}  printf("%s", yytext); return IF;}
"else"		{ /*printf("%s \t ELSE\n", yytext);*/ if(line_cnt==1){printf("1: ");}  printf("%s", yytext); return ELSE;}
"for"		{ /*printf("%s \t FOR\n", yytext);*/ if(line_cnt==1){printf("1: ");}  printf("%s", yytext); return FOR;}
"while"		{ /*printf("%s \t WHILE\n", yytext);*/ if(line_cnt==1){printf("1: ");}  printf("%s", yytext); return WHILE;}
"string"		{ /*printf("%s \t STRING\n", yytext);*/ if(line_cnt==1){printf("1: ");}  printf("%s", yytext); return STRING;}
"int"		{ /*printf("%s \t INT\n", yytext);*/ if(line_cnt==1){printf("1: ");}  printf("%s", yytext);return INT;}
"float"		{ /*printf("%s \t FLOAT\n", yytext);*/ if(line_cnt==1){printf("1: ");}  printf("%s", yytext);return FLOAT;}
"void"		{ /*printf("%s \t VOID\n", yytext);*/ if(line_cnt==1){printf("1: ");}  printf("%s", yytext); return VOID;}
"bool"		{ /*printf("%s \t BOOL\n", yytext);*/ if(line_cnt==1){printf("1: ");}  printf("%s", yytext); return BOOL;}
"true"		{ /*printf("%s \t TRUE\n", yytext);*/ if(line_cnt==1){printf("1: ");}  printf("%s", yytext); return TRUE;}
"false"		{ /*printf("%s \t FALSE\n", yytext);*/ if(line_cnt==1){printf("1: ");}  printf("%s", yytext); return FALSE;}
"return"		{ /*printf("%s \t RET\n", yytext);*/ if(line_cnt==1){printf("1: ");}  printf("%s", yytext); return RET;}
"continue"		{ /*printf("%s \t CONT\n", yytext);*/ if(line_cnt==1){printf("1: ");}  printf("%s", yytext); return CONT;}
"break"		{ /*printf("%s \t BREAK\n", yytext);*/ if(line_cnt==1){printf("1: ");}  printf("%s", yytext); return BREAK;}
{number}		{ /*printf("%s \t I_CONST\n", yytext);*/ if(line_cnt==1){printf("1: ");}  printf("%s", yytext);yylval.i_val=atoi(yytext); return I_CONST;}
{number}"."{number}		{ /*printf("%s \t F_CONST\n", yytext);*/ if(line_cnt==1){printf("1: ");}  printf("%s", yytext); yylval.f_val=atoi(yytext); return F_CONST;}

"/*"		{ /*C_comment();*/ if(line_cnt==1){printf("1: ");} printf("%s", yytext);}
"//"		{ /*CPP_comment();*/ if(line_cnt==1){printf("1: ");}  printf("%s", yytext);}

{id}	{ /*printf("%s \t ID\n", yytext);*/ if(line_cnt==1){printf("1: ");}  printf("%s", yytext); printf("%s", yytext);yylval.string=strdup(yytext); return ID;}
\n			{ /*line_cnt++;*/ printf("%s%d: ", yytext,++line_cnt); return NEWLINE;} 
[ \t]		{ if(line_cnt==1){printf("1: ");} printf("%s", yytext); }
.			{ /* ignore bad characters */ }

"\""				        { BEGIN STRING_STATE; return QUOTA; }
<STRING_STATE>"\""		{ BEGIN INITIAL; return QUOTA; }
<STRING_STATE>[^\"]*		{ yylval.string=strdup(yytext); return STRING;}

%%

/* C Code section */
void C_comment()
{
	char c, c1;
	printf("/*");

loop:
	while ((c = input()) != '*' && c != 0)
	{
		putchar(c);
		if(c=='\n')
		{
			comm_cnt++;
		}
	}

	if ((c1 = input()) != '/' && c != 0) /*	註解內部的星號 */
	{
		unput(c1);
		putchar(c);
		goto loop;
	}

	if (c != 0)
	{
		printf("*/ \t C Comment\n");
		comm_cnt++;
		line_cnt--;
	}
}

void CPP_comment()
{
	char c;
	printf("//");
	while ((c = input()) != '\n' && c != 0)
	{
		putchar(c);
	}
	comm_cnt++;

	printf(" \t C++ Comment\n");
}

void str_const()
{
	printf("\" \t QUOTA\n");

	char c;
	while ((c = input()) != '\"' && c != 0)
	{
		putchar(c);
	}
	printf(" \t STR_CONST\n");

	printf("\" \t QUOTA\n");
}

int yywrap(void)
{
    return 1;
}

/*int main(int argc,char *argv[])
{
	yyin = fopen(argv[1],"r");
	yylex();
	printf("\nParse over, the line number is %d.\n\n",comm_cnt+line_cnt);
	printf("comment: %d lines\n\n",comm_cnt);

	return 0;
}*/
