#include "Map.hpp"

Map::Map() : _beg_x(0), _beg_y(0)
{
    initscr();
    noecho();
    curs_set(FALSE);
    getDim(stdscr);
    return ;
}

Map::Map(int len, int w, int beg_y, int beg_x) : _beg_x(beg_x), _beg_y(beg_y),  _len(len), _w(w)
{
    return ;
}


Map::Map(Map const &src)
{
    *this = src;
    return ;
}

Map::~Map()
{
    getch();
    endwin();
    delwin(_win
    );
    return ;
}

Map&    Map::operator=(Map const &rhs)
{
    if (this != &rhs)
    {
        yMax = rhs.yMax;
        xMax = rhs.xMax;
        _win = rhs._win;
        _len = rhs._len;
        _w = rhs._w;
        _beg_x = rhs._beg_x;
        _beg_y = rhs._beg_y;
    }
    return *this;
}

void    Map::getDim(WINDOW *win)
{
    getmaxyx(win, yMax, xMax);
    return ;
}

void    Map::mapBox() const
{
    box(_win, 0, 0);
    wrefresh(_win);
    return ;
}


void    Map::newWindow()
{
    _win = newwin(_len, _w, _beg_y, _beg_x);
    return ;
}

WINDOW    *Map::getWindow() const
{
    return _win;
}

void    Map::display() const
{
    clear();
    wrefresh(stdscr);
    wrefresh(_win);
}

void    Map::fillMeIn(std::list<std::string> stuff_from_file)
{
    int i = 1;
    /*
	 * MAKE function for opening and reading stuff from files!
	 * add date to end of list, TBD
	 * create iterators to navigate list and then display contents
	*/

	std::list<std::string>::const_iterator 		it = stuff_from_file.begin();
	std::list<std::string>::const_iterator		ite = stuff_from_file.end();
	while ( it != ite )
	{
		mvwprintw(_win, i, 1, static_cast<std::string>(*it).c_str());
		it++;
        i++;
	}
}
