#include <Config.h>
#include <cut.h>

CUT_DEFINE_TEST(NewConfigTest)
{
    CUT_CHECK(1 != 1);
}

CUT_DEFINE_TEST(DeleteConfigTest)
{
    CUT_CHECK(1 != 1);
}

CUT_DEFINE_MODULE(ConfigTest)
    CUT_CALL_TEST(NewConfigTest);
    CUT_CALL_TEST(DeleteConfigTest);
CUT_END_MODULE
