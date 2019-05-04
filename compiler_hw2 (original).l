/* Definition section */
%{
	#include "y.tab.h"
	#include <stdio.h>
	#include <stdlib.h>
	void C_comment();
	void CPP_comment();
	void str_const();
	int line_cnt=0;
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

/* Rules section */
%%

"+" 	{ printf("%s \t ADD\n", yytext); }
"-"		{ printf("%s \t SUB\n", yytext); }
"*"		{ printf("%s \t MUL\n", yytext); }
"/"		{ printf("%s \t DIV\n", yytext); }
"%"		{ printf("%s \t MOD\n", yytext); }
"++"		{ printf("%s \t INC\n", yytext); }
"--"		{ printf("%s \t DEC\n", yytext); }
">"		{ printf("%s \t MT\n", yytext); }
"<"		{ printf("%s \t LT\n", yytext); }
">="		{ printf("%s \t MTE\n", yytext); }
"<="		{ printf("%s \t LTE\n", yytext); }
"=="		{ printf("%s \t EQ\n", yytext); }
"!="		{ printf("%s \t NE\n", yytext); }
"="		{ printf("%s \t ASGN\n", yytext); }
"+="		{ printf("%s \t ADDASGN\n", yytext); }
"-="		{ printf("%s \t SUBASGN\n", yytext); }
"*="		{ printf("%s \t MULASGN\n", yytext); }
"/="		{ printf("%s \t DIVASGN\n", yytext); }
"%="		{ printf("%s \t MODASGN\n", yytext); }
"&&"		{ printf("%s \t AND\n", yytext); }
"||"		{ printf("%s \t OR\n", yytext); }
"!"		{ printf("%s \t NOT\n", yytext); }
"("		{ printf("%s \t LB\n", yytext); }
")"		{ printf("%s \t RB\n", yytext); }
"{"		{ printf("%s \t LCB\n", yytext);}
"}"		{ printf("%s \t RCB\n", yytext); }
"["		{ printf("%s \t LSB\n", yytext); }
"]"		{ printf("%s \t RSB\n", yytext); }
","		{ printf("%s \t COMMA\n", yytext); }
";"		{ printf("%s \t SEMICOLON\n", yytext); }
"\""		{ str_const(); }
"print"		{ printf("%s \t PRINT\n", yytext); }
"if"		{ printf("%s \t IF\n", yytext); }
"else"		{ printf("%s \t ELSE\n", yytext); }
"for"		{ printf("%s \t FOR\n", yytext); }
"while"		{ printf("%s \t WHILE\n", yytext); }
"string"		{ printf("%s \t STRING\n", yytext); }
"int"		{ printf("%s \t INT\n", yytext); }
"float"		{ printf("%s \t FLOAT\n", yytext); }
"void"		{ printf("%s \t VOID\n", yytext); }
"bool"		{ printf("%s \t BOOL\n", yytext); }
"true"		{ printf("%s \t TRUE\n", yytext); }
"false"		{ printf("%s \t FALSE\n", yytext); }
"return"		{ printf("%s \t RET\n", yytext); }
"continue"		{ printf("%s \t CONT\n", yytext); }
"break"		{ printf("%s \t BREAK\n", yytext); }
{number}		{ printf("%s \t I_CONST\n", yytext); }
{number}"."{number}		{ printf("%s \t F_CONST\n", yytext); }

"/*"		{ C_comment(); }
"//"		{ CPP_comment(); }

{id}	{ printf("%s \t ID\n", yytext); }
\n			{ line_cnt++; } 
.			{ /* ignore bad characters */ }

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
