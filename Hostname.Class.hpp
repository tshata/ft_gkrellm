#ifndef __HOSTNAME_CLASS__
#define __HOSTNAME_CLASS__

#include "IMonitorModule.hpp"

class Hostname : public IMonitorModule
{
    private:
    public:
        Hostname(void);
        Hostname(Hostname const &copy);
        std::list<std::string> getInfo(void);
        // Hostname &operator=(Hostname const &rhs);
        ~Hostname(void);
};

#endif /*HOSTNAME_CLASS*/