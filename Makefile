.PHONY: all clean install check

CFLAGS= -Wall -Wextra -std=c99
CPPFLAGS= -I./include
LDFLAGS= -O2
LDLIBS=

OBJS=\
src/Client.o \
src/Output.o \
src/Group.o \
src/ListClients.o \
src/Config.o \
src/main.o \
src/Lexer.yy.c

all: phiChat

phiChat: $(OBJS)
	gcc -o phiChat $(OBJS) $(LDFLAGS)

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS) $(CPPFLAGS)

%.yy.c: %.l
	lex -o$@ $<

clean:
	rm phiChat
	rm $(OBJS)

install:
	sudo cp phiChat /bin

check:
	cd test && ./runtest.sh
