#ifndef __IMONITOR__
#define __IMONITOR__
#include <list>
#include <string>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <ncurses.h>
#include <cstdlib>

class IMonitorModule
{
public:
    virtual std::list<std::string> getInfo() = 0;
};

#endif