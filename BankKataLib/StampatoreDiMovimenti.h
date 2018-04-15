#pragma once

#include "StampatoreDiMovimentiInterface.h"

class StampatoreDiMovimenti : public StampatoreDiMovimentiInterface
{
public:
	// Inherited via StampatoreDiMovimentiInterface
	virtual void Stampa(const std::vector<Transazione>& transazioni) override;
};