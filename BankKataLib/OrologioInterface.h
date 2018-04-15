#pragma once

#include <string>

class OrologioInterface
{
public:
	virtual std::string DataComeStringa() = 0;
	virtual ~OrologioInterface() = default;
};