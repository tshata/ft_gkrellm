#include "RAM.Class.hpp"

Ram::Ram(void) {}

Ram::Ram(Ram const &copy)
{
	*this = copy;
	return;
}

std::list<std::string> Ram::getInfo(void)
{
	std::ifstream file_from_stream("Ram.log");
	std::string line;
	std::list<std::string> stuff_from_file;

	int64_t _mem = 2;
	uint64_t _page_size = 1;

	/*
	 * delete file, has all the info about sys
	 * needs refining
	*/
	mach_msg_type_number_t count = HOST_VM_INFO_COUNT;
	vm_statistics_data_t vmstat;
	host_statistics(
		mach_host_self(),
		HOST_VM_INFO,
		reinterpret_cast<host_info_t>(&vmstat),
		&count);
	int perc = ((vmstat.active_count + vmstat.inactive_count + vmstat.wire_count) * _page_size) / _mem * 100;
	std::string perc_str = std::to_string(perc / 10000) + " MB";
	stuff_from_file.push_back("Memory Usage: " + perc_str);
	if (file_from_stream.good())
		system("rm Ram.log");
	system("system_profiler SPHardwareDataType | grep Memory >> Ram.log");

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
	file_from_stream.close();
	return (stuff_from_file);
}

// Ram& Ram::operator=(Ram const &rhs)
// {
//     *this = rhs;
//     return (*this);
// }

Ram::~Ram(void) {}
