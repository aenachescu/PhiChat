#include <cut.h>

static unsigned long long int CUT_PASSED_CHECKS      = 0, CUT_FAILED_CHECKS = 0;
static unsigned long long int CUT_PASSED_TESTS       = 0, CUT_FAILED_TESTS  = 0;
static                    int CUT_FIRST_FAILED_CHECK = 0;

void CUT_incrementPassedChecks(void)
{
    CUT_PASSED_CHECKS++;
}

void CUT_incrementFailedChecks(void)
{
    CUT_FAILED_CHECKS++;
}

void CUT_incrementPassedTests(void)
{
    CUT_PASSED_TESTS++;
}

void CUT_incrementFailedTests(void)
{
    CUT_FAILED_TESTS++;
}

void CUT_incrementFirstFailedCheck(void)
{
    CUT_FIRST_FAILED_CHECK++;
}

void CUT_resetFirstFailedCheck(void)
{
    CUT_FIRST_FAILED_CHECK = 0;
}

int CUT_getFirstFailedCheck(void)
{
    return CUT_FIRST_FAILED_CHECK;
}

unsigned long long int CUT_getPassedChecks(void)
{
    return CUT_PASSED_CHECKS;
}

unsigned long long int CUT_getFailedChecks(void)
{
    return CUT_FAILED_CHECKS;
}

unsigned long long int CUT_getPassedTests(void)
{
    return CUT_PASSED_TESTS;
}

unsigned long long int CUT_getFailedTests(void)
{
    return CUT_FAILED_TESTS;
}

