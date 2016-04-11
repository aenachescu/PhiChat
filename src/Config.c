#include <Config.h>
#include <Defines.h>
#include <Lexer.h>

#include <stdio.h>

extern int yylex();
extern int yylineno;
extern char* yytext;

enum PhiChatErrors NewConfig(__OUT__ struct Config** conf)
{

}

enum PhiChatErrors DeleteConfig(__IN__ struct Config** conf)
{
    if (conf == NULL) {
        return POINTER_NULL;
    }
}

enum PhiChatErrors ReadConfig(__IN__ struct Config* conf, __IN__ const char* name)
{
    if (conf == NULL) {
        return POINTER_NULL;
    }
}
