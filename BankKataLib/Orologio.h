#pragma once

#include "OrologioInterface.h"
#include <chrono>

class Orologio : public OrologioInterface
{
public:
	virtual std::string DataComeStringa() override;

protected:
	virtual std::chrono::system_clock::time_point Data();
};