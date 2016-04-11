/**
 * @file Output.h
 * @brief In this file are declared the functions for output.
 */

#ifndef PhiChat_OUTPUT
#define PhiChat_OUTPUT

#include <Errors.h>
#include <Defines.h>

#include <stddef.h>

void InitOutput(void);
void PrintMessage(__IN__ const char*);
void ActivatesTerminal(void);
void DeactivatesTerminal(void);
void PrintError(__IN__ enum PhiChatErrors, __IN__ size_t, __IN__ const char*);

#endif

