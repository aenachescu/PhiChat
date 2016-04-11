#include <Config.h>
#include <Defines.h>
#include <Lexer.h>

#include <stdio.h>

extern int yylex();
extern int yylineno;
extern char* yytext;

enum PhiChatErrors NewConfig(__OUT__ struct Config** conf)
{
    *conf = malloc(sizeof(struct Config));
    (*conf)->port = DEFAULT_PORT;
    (*conf)->maxConnections = DEFAULT_MAX_CONNECTIONS;
    (*conf)->databaseHost = NULL;
    (*conf)->databaseUser = NULL;
    (*conf)->databasePassword = NULL;
    (*conf)->databaseName = NULL;
    (*conf)->logfileName = NULL;
    (*conf)->end = 0;
    (*conf)->respawn = 0;

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

    FILE *f = fopen(name, "r");
    fclose(f);
}
