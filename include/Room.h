#ifndef PhiChat_ROOM
#define PhiChat_ROOM

#include <Defines.h>
#include <Exceptions.h>
#include <Client.h>

#include <cstdint>
#include <list>
#include <array>

class Room
{
    private:
        uint64_t id;
        char name[ROOM_MAX_LENGTH_NAME];
        uint8_t status;
        std::list<std::pair<std::array<Client*, MAX_CLIENTS_IN_NODE>, uint64_t>> clients;

    public:
        Room(uint64_t, const char*, uint8_t);

        bool operator==(const uint64_t&) const;
        bool operator==(const char*) const;
        void operator+=(Client*);
        void operator-=(Client*);
};

#endif

