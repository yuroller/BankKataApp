#pragma once

#include "OrologioInterface.h"
#include <chrono>

class Orologio : public OrologioInterface
{
public:
	virtual std::string DataComeStringa() override;
};