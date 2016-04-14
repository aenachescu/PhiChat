# Run tests on Linux

gcc -std=gnu99 -DPhiChat_TEST_MODE -o               \
    tests Tests.c                                   \
    ClientTest.c ../src/Client.c                    \
    GroupTest.c ../src/Group.c                      \
    ListClientsTest.c ../src/ListClients.c          \
    DatabaseTest.c ../src/Database.c                \
    ConfigTest.c ../src/Config.c ../src/Lexer.yy.c  \
    CUT/src/cut.c                                   \
    -I../include -ICUT/include `mysql_config --cflags --libs`

valgrind ./tests

rm tests
