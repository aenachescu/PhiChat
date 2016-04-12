# Run tests on Linux

gcc -std=c99 -o                                     \
    tests Tests.c                                   \
    ClientTest.c ../src/Client.c                    \
    GroupTest.c ../src/Group.c                      \
    ListClientsTest.c ../src/ListClients.c          \
    ConfigTest.c ../src/Config.c ../src/Lexer.yy.c  \
    CUT/src/cut.c                                   \
    -I../include -ICUT/include

valgrind ./tests

rm tests
