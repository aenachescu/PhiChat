#include <Server.h>
#include <Config.h>
#include <Output.h>

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void ReadFromKeyboard(void)
{
    char buffer[128];
    size_t size = 128;

    int x;
    while (1)
    {
        x = getline(&buffer, &size, stdin);
        printf("%s %d\n",buffer, x);
        if (strcmp(buffer, "exit") == 0)
            break;
    }
}

int main(int argc, char **argv)
{
    printf("Initializing output mode...\n");
    InitOutput();
    PrintMessage("Output mode was initialized successfully\n");

    if (argc > 2)
    {
        PrintMessage("Too many arguments from command line.\n");
        return EXIT_FAILURE;
    }

    if (argc < 1)
    {
        PrintMessage("Something's wrong with argc.\n");
        return EXIT_FAILURE;
    }

    struct Config *config = NULL;
    enum PhiChatErrors err;

    err = NewConfig(&config);
    if (err != NO_ERROR)
    {
        PrintError(err, __LINE__, __FILE__);
        return EXIT_FAILURE;
    }

    PrintMessage("Reading configuration file...\n");
    if (argc == 1)
    {
        err = ReadConfig(config, "server.config");
        if (err != NO_ERROR)
        {
            PrintError(err, __LINE__, __FILE__);
            return EXIT_FAILURE;
        }
    }
    else
    {
        err = ReadConfig(config, argv[1]);
        if (err != NO_ERROR)
        {
            PrintError(err, __LINE__, __FILE__);
            return EXIT_FAILURE;
        }
    }
    PrintMessage("Configuration file is right\n");

    ReadFromKeyboard();

    return EXIT_SUCCESS;
}

