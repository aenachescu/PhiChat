%{
#include "../include/Lexer.h"
%}


%%
=                               return ASSIGN;
:                               return COLON;
$                               return EXPAND;
"SERVER_PORT"                   return PORT;
"SERVER_MAX_CONNECTIONS"        return MAX_CONNECTIONS;
"SERVER_LOG"                    return LOG;
"FILENAME"                      return LOG_FILENAME;
"DAILY"                         return LOG_DAILY;
"SERVER_DATABASE"               return DATABASE;
"HOST"                          return DATABASE_HOST;
"USER"                          return DATABASE_USER;
"PASSWORD"                      return DATABASE_PASSWORD;
"NAME"                          return DATABASE_NAME;
[a-zA-Z][_a-zA-Z0-9]*           return IDENTIFIER;
[1-9][0-9]*                     return INTEGER;
[ \t\n]                         return ;
.                               printf("Unexpected character!\n");
%%

int yywrap(void)
{
    return 1;
}
