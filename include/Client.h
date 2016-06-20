#ifndef PhiChat_CLIENT
#define PhiChat_CLIENT

#include <Defines.h>
#include <Exceptions.h>

#include <cstdint>

class Client
{
    private:
        char name[CLIENT_MAX_LENGTH_NAME];
        uint32_t socket;
        uint64_t id;

    public:
        explicit Client(const uint32_t&);

        ~Client()                           = default;
        Client()                            = delete;
        Client(const Client&)               = delete;
        Client(Client&&)                    = delete;
        Client& operator=(const Client&)    = delete;
        Client& operator=(Client&&)         = delete;
};

#endif

