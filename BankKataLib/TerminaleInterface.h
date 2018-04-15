#pragma once

#include <string>

class TerminaleInterface
{
public:
	virtual void StampaLinea(const std::string& testo) = 0;
	virtual ~TerminaleInterface() = default;
};