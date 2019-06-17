#include "Hostname.Class.hpp"

Hostname::Hostname(void){}

Hostname::Hostname(Hostname const &copy)
{
    *this = copy;
    return;
}

std::list<std::string> Hostname::getInfo(void)
{
    std::ifstream 				file_from_stream("Hostname.log");
	std::string 				line;
	std::list<std::string>		stuff_from_file;

    /*
	 * delete file, has all the info about sys
	 * needs refining
	*/
    if ( file_from_stream.good() )
		system("rm Hostname.log");
    system("hostname >> Hostname.log");

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

// Hostname& Hostname::operator=(Hostname const &rhs)
// {
//     *this = rhs;
//     return (*this);
// }

Hostname::~Hostname(void){}