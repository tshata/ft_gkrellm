#ifndef __RAM_CLASS__
#define __RAM_CLASS__

#include "IMonitorModule.hpp"
#include <sys/sysctl.h>
#include <sstream>
#include <mach/mach_host.h>

class Ram : public IMonitorModule
{
private:
public:
    Ram(void);
    Ram(Ram const &copy);
    std::list<std::string> getInfo(void);
    // Ram &operator=(Ram const &rhs);
    ~Ram(void);
};

#endif /*RAM_CLASS*/