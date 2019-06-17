#ifndef __CPU_CLASS__
#define __CPU_CLASS__

#include "IMonitorModule.hpp"
#include <sys/sysctl.h>
#include <mach/processor_info.h>
#include <mach/mach_host.h>
#include <sstream>
#include <stdlib.h>

class Cpu : public IMonitorModule
{
private:
public:
    float getPercentage(void);
    //std::list<std::string> getInfo(void);
    Cpu(void);
    Cpu(Cpu const &copy);
    // std::list<std::string> getCpu(void);
    virtual std::list<std::string> getInfo();
    // Cpu &operator=(Cpu const &rhs);
    ~Cpu(void);
};

#endif /*CPU_CLASS*/