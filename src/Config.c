#include <Config.h>
#include <Defines.h>
#include <Lexer.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

extern int yylex();
extern int yylineno;
extern char* yytext;
extern FILE* yyin;

enum PhiChatErrors NewConfig(__OUT__ struct Config **conf)
{
    if (conf == NULL)
    {
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

enum PhiChatErrors DeleteConfig(__IN__ struct Config **conf)
{
    if (conf == NULL)
    {
        return POINTER_NULL;
    }

    if (*conf == NULL)
    {
        return CONFIG_NULL;
    }

    if ((*conf)->databaseHost != NULL)
        free((*conf)->databaseHost);

    if ((*conf)->databaseUser != NULL)
        free((*conf)->databaseUser);

    if ((*conf)->databasePassword != NULL)
        free((*conf)->databasePassword);

    if ((*conf)->databaseName != NULL)
        free((*conf)->databaseName);

    if ((*conf)->logfileName != NULL)
        free((*conf)->logfileName);

    free(*conf);
    *conf = NULL;

    return NO_ERROR;
}

enum PhiChatErrors ReadConfig(__IN__ struct Config *conf,
                              __IN__ const char *name)
{
    if (conf == NULL)
    {
        return CONFIG_NULL;
    }

    if (name == NULL)
    {
        return CONFIG_FILENAME_NULL;
    }

    yyin = fopen(name, "r");

    int ntoken = yylex();
    int vtoken;

    while (ntoken)
    {
        if (ntoken == LOG)
        {
            vtoken = yylex();
            if (vtoken != COLON)
            {
                printf("':' was expected on line %d, but we got '%s'.\n",
                        yylineno, yytext);
                DeleteConfig(&conf);
            }
        }
        else
            if (ntoken == DATABASE)
            {
                vtoken = yylex();
                if (vtoken != COLON)
                {
                    printf("':' was expected on line %d, but we got '%s'.\n",
                            yylineno, yytext);
                    DeleteConfig(&conf);
                }
            }
            else
            {
                vtoken = yylex();
                if (vtoken != ASSIGN)
                {
                    printf("'=' was expected on line %d, but we got '%s'.\n",
                            yylineno, yytext);
                    DeleteConfig(&conf);
                    return CONFIG_EXPECTED_ASSIGN;
                }

                vtoken = yylex();
                switch (ntoken)
                {
                    int tokenLen;
                    case PORT:
                        if (vtoken != INTEGER)
                        {
                            printf("Was expected an integer on line %d, but we got '%s'.\n",
                                    yylineno, yytext);
                            DeleteConfig(&conf);
                            return CONFIG_INTEGER_EXPECTED;
                        }

                        conf->port = strtoumax(yytext, NULL, 10);
                        break;

                    case MAX_CONNECTIONS:
                        if (vtoken != INTEGER)
                        {
                            printf("Was expected an integer on line %d, but we got '%s'.\n",
                                    yylineno, yytext);
                            DeleteConfig(&conf);
                            return CONFIG_INTEGER_EXPECTED;
                        }

                        conf->maxConnections = strtoumax(yytext, NULL, 10);
                        break;

                    case LOG_FILENAME:
                        if (vtoken != IDENTIFIER)
                        {
                            printf("Was expected an identifier on line %d, but we got '%s'.\n",
                                    yylineno, yytext);
                            DeleteConfig(&conf);
                            return CONFIG_EXPECTED_IDENTIFIER;
                        }

                        tokenLen = strlen(yytext);
                        conf->logfileName = malloc(tokenLen + 1);
                        memcpy(conf->logfileName, yytext, tokenLen);
                        conf->logfileName[tokenLen] = '\0';
                        break;

                    case LOG_DAILY:
                        if (vtoken != IDENTIFIER)
                        {
                            printf("Was expected an identifier on line %d, but we got '%s'.\n",
                                    yylineno, yytext);
                            DeleteConfig(&conf);
                            return CONFIG_EXPECTED_IDENTIFIER;
                        }

                        if (!strcmp(yytext, "YES"))
                        {
                            conf->respawn = 24;
                        }

                        break;

                    case DATABASE_HOST:
                        if (vtoken != IDENTIFIER)
                        {
                            printf("Was expected an identifier on line %d, but we got '%s'.\n",
                                    yylineno, yytext);
                            DeleteConfig(&conf);
                            return CONFIG_EXPECTED_IDENTIFIER;
                        }

                        tokenLen = strlen(yytext);
                        conf->databaseHost = malloc(tokenLen + 1);
                        memcpy(conf->databaseHost, yytext, tokenLen);
                        conf->databaseHost[tokenLen] = '\0';
                        break;

                    case DATABASE_USER:
                        if (vtoken != IDENTIFIER)
                        {
                            printf("Was expected an identifier on line %d, but we got '%s'.\n",
                                    yylineno, yytext);
                            DeleteConfig(&conf);
                            return CONFIG_EXPECTED_IDENTIFIER;
                        }

                        tokenLen = strlen(yytext);
                        conf->databaseUser = malloc(tokenLen + 1);
                        memcpy(conf->databaseUser, yytext, tokenLen);
                        conf->databaseUser[tokenLen] = '\0';
                        break;

                    case DATABASE_PASSWORD:
                        if (vtoken != IDENTIFIER)
                        {
                            printf("Was expected an identifier on line %d, but we got '%s'.\n",
                                    yylineno, yytext);
                            DeleteConfig(&conf);
                            return CONFIG_EXPECTED_IDENTIFIER;
                        }

                        tokenLen = strlen(yytext);
                        conf->databasePassword = malloc(tokenLen + 1);
                        memcpy(conf->databasePassword, yytext, tokenLen);
                        conf->databasePassword[tokenLen] = '\0';
                        break;

                    case DATABASE_NAME:
                        if (vtoken != IDENTIFIER)
                        {
                            printf("Was expected an identifier on line %d, but we got '%s'.\n",
                                    yylineno, yytext);
                            DeleteConfig(&conf);
                            return CONFIG_EXPECTED_IDENTIFIER;
                        }

                        tokenLen = strlen(yytext);
                        conf->databaseName = malloc(tokenLen + 1);
                        memcpy(conf->databaseName, yytext, tokenLen);
                        conf->databaseName[tokenLen] = '\0';
                        break;

                    default:
                        printf("Unexpected token '%s' on line %d.\n",
                                yytext, yylineno);
                        DeleteConfig(&conf);
                        return CONFIG_UNEXPECTED;
                        break;
                }
            }

        ntoken = yylex();
    }

    fclose(yyin);

    return NO_ERROR;
}
