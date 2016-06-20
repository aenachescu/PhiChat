#ifndef PhiChat_CLIENT
#define PhiChat_CLIENT

#include <Defines.h>
#include <Exceptions.h>

#include <cstdint>

class Client
{
    private:
        char name[CLIENT_MAX_LENGTH_NAME];
        uint32_t sockfd;
        uint64_t id;

    public:
        explicit Client(const uint32_t& _sockfd) :
            sockfd(_sockfd), id(0)
        {
        }

        const char* GetName() const __attribute__((always_inline))
        {
            return name;
        }

        uint32_t GetSocket() const __attribute__((always_inline))
        {
            return sockfd;
        }

        uint64_t GetId() const __attribute__((always_inline))
        {
            return id;
        }

        ~Client()                           = default;
        Client()                            = delete;
        Client(const Client&)               = delete;
        Client(Client&&)                    = delete;
        Client& operator=(const Client&)    = delete;
        Client& operator=(Client&&)         = delete;
};

#endif

