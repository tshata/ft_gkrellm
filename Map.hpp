#ifndef _MAP_HPP_
# define _MAP_HPP_

# include <iostream>
# include <ncurses.h>
# include <string>
#include <list>


class Map 
{
    public:
        int     yMax;
        int     xMax;
        int     _beg_x;
        int     _beg_y;

        Map();
        Map(int, int, int, int);
        Map(Map const &);      
        ~Map();
        Map &operator=(Map const &);

        void    mapBox() const;
        void    newWindow();
        WINDOW    *getWindow() const;
        void    getDim(WINDOW *);
        void    display() const;
        void    fillMeIn(std::list<std::string>);

    protected:
        int     _len;
        int     _w;
        WINDOW  *_win;
};

#endif