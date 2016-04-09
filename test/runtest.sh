# Run tests on Linux

gcc -std=c99 -o                                 \
    tests Tests.c                               \
    ClientTest.c ../src/Client.c                \
    CUT/src/cut.c                               \
    -I../include -ICUT/include

valgrind ./tests

rm tests
