#include "CPU.Class.hpp"

Cpu::Cpu(void) {}

Cpu::Cpu(Cpu const &copy)
{
	*this = copy;
	return;
}
/* Get information */
/* Needs to be modified */
std::list<std::string> Cpu::getInfo(void)
{
	//_info.push_back(cores_string.str());

	std::ifstream file_from_stream("Cpu.log");
	std::string line;
	std::list<std::string> stuff_from_file;

	//stuff_from_file.push_back(std::to_string(perc) + "%");
	/*
	 * delete file, has all the info about sys
	 * needs refining
	*/

	if (file_from_stream.good())
		system("rm Cpu.log");
	system("system_profiler SPHardwareDataType >> Cpu.log");

	/*
	 * check if filestream is open and read contents
	 * into list container
	*/

	if (file_from_stream.is_open())
		while (getline(file_from_stream, line))
			stuff_from_file.push_back(line);

	/*
	 * clean up
	 * clear list and close filestream
	 */
	// file_from_stream.close();
	return (stuff_from_file);
}

// Cpu& Cpu::operator=(Cpu const &rhs)
// {
//     *this = rhs;
//     return (*this);
// }

Cpu::~Cpu(void) {}
