#ifndef C_UNIT_TESTING_FRAMEWORK
#define C_UNIT_TESTING_FRAMEWORK

#include <stdio.h>

#ifdef __linux__
#define RED     "\x1B[31m"
#define GREEN   "\x1B[32m"
#define NORMAL  "\x1B[0m"
#define BOLD    "\x1B[1m"
#else
#define RED     ""
#define GREEN   ""
#define NORMAL  ""
#define BOLD    ""
#endif



#define CUT_DEFINE_TEST(x)                                                      \
    void x()                                                                    \



#define CUT_CALL_TEST(x)                                                        \
    do                                                                          \
    {                                                                           \
        printf("%s: ", #x);                                                     \
        CUT_resetFirstFailedCheck();                                            \
        x();                                                                    \
        if (CUT_getFirstFailedCheck() == 0)                                     \
        {                                                                       \
            CUT_incrementPassedTests();                                         \
            printf("%s%sPASSED%s\n", GREEN, BOLD, NORMAL);                      \
        }                                                                       \
        else                                                                    \
        {                                                                       \
            CUT_incrementFailedTests();                                         \
        }                                                                       \
    } while (0)



#define CUT_DEFINE_MAIN                                                         \
    int main(void)                                                              \
    {



#define CUT_END_MAIN                                                            \
        printf("\n");                                                           \
        printf("Failed tests:  %llu\n", CUT_getFailedTests());                  \
        printf("Passed tests:  %llu\n", CUT_getPassedTests());                  \
        printf("Failed checks: %llu\n", CUT_getFailedChecks());                 \
        printf("Passed checks: %llu\n", CUT_getPassedChecks());                 \
        return 0;                                                               \
    }                                                                           \



#define CUT_CHECK(x)                                                            \
    if (x)                                                                      \
    {                                                                           \
        CUT_incrementPassedChecks();                                            \
    }                                                                           \
    else                                                                        \
    {                                                                           \
        CUT_incrementFailedChecks();                                            \
        CUT_incrementFirstFailedCheck();                                        \
        if (CUT_getFirstFailedCheck() == 1)                                     \
            printf("%s%sFAILED%s\n", RED, BOLD, NORMAL);                        \
        printf("%s(%d): \"%s\" %sfailed%s\n", __FILE__, __LINE__, #x,           \
                RED, NORMAL);                                                   \
    }



#define CUT_DEFINE_MODULE(x)                                                    \
    void x(void)                                                                \
    {



#define CUT_END_MODULE                                                          \
    }



#define CUT_INCLUDE_MODULE(x)                                                   \
    void x(void)



#define CUT_CALL_TESTS_FROM_MODULE(x)                                           \
    x()



void CUT_incrementPassedChecks(void);
void CUT_incrementFailedChecks(void);
void CUT_incrementPassedTests(void);
void CUT_incrementFailedTests(void);
void CUT_incrementFirstFailedCheck(void);
void CUT_resetFirstFailedCheck(void);
int CUT_getFirstFailedCheck(void);
unsigned long long int CUT_getPassedChecks(void);
unsigned long long int CUT_getFailedChecks(void);
unsigned long long int CUT_getPassedTests(void);
unsigned long long int CUT_getFailedTests(void);

#endif

