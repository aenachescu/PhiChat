#include <Config.h>
#include <Defines.h>
#include <Lexer.h>

#include <stdio.h>
#include <stdlib.h>

extern int yylex();
extern int yylineno;
extern char* yytext;
extern FILE* yyin;

enum PhiChatErrors NewConfig(__OUT__ struct Config** conf)
{
    if (conf == NULL) {
        return POINTER_NULL;
    }

    *conf = malloc(sizeof(struct Config));
    (*conf)->port = DEFAULT_PORT;
    (*conf)->maxConnections = DEFAULT_MAX_CONNECTIONS;
    (*conf)->databaseHost = NULL;
    (*conf)->databaseUser = NULL;
    (*conf)->databasePassword = NULL;
    (*conf)->databaseName = NULL;
    (*conf)->logfileName = NULL;
    (*conf)->end = 0;
    (*conf)->respawn = DEFAULT_RESPAWN;

    return NO_ERROR;
}

enum PhiChatErrors DeleteConfig(__IN__ struct Config** conf)
{
    if (conf == NULL) {
        return POINTER_NULL;
    }

    if (*conf == NULL) {
        return POINTER_NULL;
    }

    free(*conf);
    return NO_ERROR;
}

enum PhiChatErrors ReadConfig(__IN__ struct Config* conf, __IN__ const char* name)
{
    if (conf == NULL) {
        return POINTER_NULL;
    }

    yyin = fopen(name, "r");
    fclose(yyin);

    return NO_ERROR;
}
