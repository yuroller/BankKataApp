#pragma once
#include "Transazione.h"
#include <vector>

class StampatoreDiMovimentiInterface
{
public:
	virtual void Stampa(const std::vector<Transazione>& transazioni) = 0;
	virtual ~StampatoreDiMovimentiInterface() = default;
};