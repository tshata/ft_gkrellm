#include "Date.Class.hpp"

Date::Date(void){}

Date::Date(Date const &copy)
{
    *this = copy;
    return;
}

std::list<std::string> Date::getInfo(void)
{
    std::ifstream 				file_from_stream("date.log");
	std::string 				line;
	std::list<std::string>		stuff_from_file;

    /*
	 * delete file, has all the info about sys
	 * needs refining
	*/
    if ( file_from_stream.good() )
		system("rm date.log");
    system("date >> date.log");

	/*
	 * check if filestream is open and read contents
	 * into list container
	*/
	if ( file_from_stream.is_open() )
		while ( getline ( file_from_stream, line) ) 
			stuff_from_file.push_back(line);
    /*
	 * clean up
	 * clear list and close filestream
	 */
    file_from_stream.close();
    return  (stuff_from_file);
}

// Date& Date::operator=(Date const &rhs)
// {
//     *this = rhs;
//     return (*this);
// }

Date::~Date(void){}