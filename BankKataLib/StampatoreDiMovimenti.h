#pragma once

#include "StampatoreDiMovimentiInterface.h"

class TerminaleInterface;

class StampatoreDiMovimenti : public StampatoreDiMovimentiInterface
{
public:
	StampatoreDiMovimenti(TerminaleInterface& terminale);

	// Inherited via StampatoreDiMovimentiInterface
	virtual void Stampa(const std::vector<Transazione>& transazioni) override;

private:
	TerminaleInterface& terminale_;
};