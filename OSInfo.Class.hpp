#ifndef __OSINFO_CLASS__
#define __OSINFO_CLASS__

#include <list>
#include <string>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include "IMonitorModule.hpp"

class OSInfo : public IMonitorModule
{
    private:
    public:
        OSInfo(void);
        OSInfo(OSInfo const &copy);
        std::list<std::string> getInfo(void);
        // OSInfo &operator=(OSInfo const &rhs);
        ~OSInfo(void);
};

#endif /*OSINFO_CLASS*/