#ifndef PhiChat_GROUP
#define PhiChat_GROUP

#include <Exceptions.h>
#include <Defines.h>
#include <Client.h>

#include <thread>
#include <array>
#include <cstdint>

class Group final
{
    private:
        uint32_t clientsNumber;
        uint8_t state;
        std::thread *__thread;
        std::array<Client*, MAX_CLIENTS_IN_GROUP> clients;
};

#endif

