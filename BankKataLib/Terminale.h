#pragma once

#include "TerminaleInterface.h"

class Terminale : public TerminaleInterface
{
public:
	// Inherited via TerminaleInterface
	virtual void StampaLinea(const std::string & testo) override;
};