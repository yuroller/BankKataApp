#include "stdafx.h"
#include "Orologio.h"

#include <sstream>
#include <iomanip>
#include <ctime>

std::string Orologio::DataComeStringa()
{
	auto in_time_t = std::chrono::system_clock::to_time_t(Data());
	std::stringstream ss;
	ss << std::put_time(std::localtime(&in_time_t), "%d/%m/%Y");
	return ss.str();
}

std::chrono::system_clock::time_point Orologio::Data()
{
	return std::chrono::system_clock::now();
}