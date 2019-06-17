
#include "Map.hpp"
#include "RAM.Class.hpp"
#include "CPU.Class.hpp"
#include "Date.Class.hpp"
#include "OSInfo.Class.hpp"
#include "Hostname.Class.hpp"

int		main(void)
{
/* ************************************************************************** */
	//								WINDOW
	int	input;//,yMax, xMax;
	Map			map;
	Cpu			cpu;
	Hostname	hst;
	OSInfo		os;
	Date		date;
	Ram			ram;


	Map		scr1(20, 60, 3, 3);
	Map		scr2(20, 60, 3, 63);
	Map		scr3(20, 60, 3, 125);
	map.newWindow();
	scr1.newWindow();
	scr2.newWindow();
	scr3.newWindow();
	nodelay(stdscr, true);
	while((input = getch()) != 'q')
	{
		scr1.mapBox();
		scr2.mapBox();
		scr3.mapBox();
		scr1.fillMeIn(cpu.getInfo());
		scr2.fillMeIn(hst.getInfo());
		scr3.fillMeIn(os.getInfo());
		mvwprintw(scr2.getWindow(), 2, 1, static_cast<std::string>(*(date.getInfo().begin())).c_str());
		mvwprintw(scr2.getWindow(), 3, 1, static_cast<std::string>(*(ram.getInfo().begin())).c_str());
		refresh();
		map.display();
		scr1.display();
		scr2.display();
		scr3.display();
		clear();
	}
	
	getch();
	delwin(stdscr);
/* ************************************************************************** */
	return (0);
}