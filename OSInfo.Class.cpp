#include "OSInfo.Class.hpp"

OSInfo::OSInfo(void){}

OSInfo::OSInfo(OSInfo const &copy)
{
    *this = copy;
    return;
}

std::list<std::string> OSInfo::getInfo(void)
{
    std::ifstream 				file_from_stream("osinfo.log");
	std::string 				line;
	std::list<std::string>		stuff_from_file;

    /*
	 * delete file, has all the info about sys
	 * needs refining
	*/
    if ( file_from_stream.good() )
		system("rm osinfo.log");
    system("sw_vers >> osinfo.log");

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

// OSInfo& OSInfo::operator=(OSInfo const &rhs)
// {
//     *this = rhs;
//     return (*this);
// }

OSInfo::~OSInfo(void){}