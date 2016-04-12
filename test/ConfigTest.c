#include <Config.h>
#include <Errors.h>
#include <cut.h>
#include <stdlib.h>

CUT_DEFINE_TEST(NewConfigTest)
{
    CUT_CHECK(NewConfig(NULL) == POINTER_NULL);
    struct Config* config = NULL;
    CUT_CHECK(NewConfig(&config) == NO_ERROR);
    CUT_CHECK(config->port == DEFAULT_PORT);
    CUT_CHECK(config->respawn == DEFAULT_RESPAWN);
    CUT_CHECK(config->maxConnections == DEFAULT_MAX_CONNECTIONS);
    CUT_CHECK(config->databaseHost == NULL);
    free(config);
}

CUT_DEFINE_TEST(DeleteConfigTest)
{
    struct Config* config = NULL;
    CUT_CHECK(DeleteConfig(NULL) == POINTER_NULL);
    CUT_CHECK(DeleteConfig(&config) == CONFIG_NULL);
    config = malloc(sizeof(struct Config));
    config->port = 0;
    config->maxConnections = 0;
    config->databaseHost = NULL;
    config->databaseUser = NULL;
    config->databasePassword = NULL;
    config->databaseName = NULL;
    config->logfileName = NULL;
    config->end = 0;
    config->respawn = 0;
    CUT_CHECK(DeleteConfig(&config) == NO_ERROR);
}

CUT_DEFINE_MODULE(ConfigTest)
    CUT_CALL_TEST(NewConfigTest);
    CUT_CALL_TEST(DeleteConfigTest);
CUT_END_MODULE
