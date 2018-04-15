#pragma once

#include <vector>
#include "Transazione.h"

class RegistroTransazioniInterface
{
public:
	virtual void AggiungiDeposito(int importo) = 0;
	virtual void AggiungiPrelievo(int importo) = 0;
	virtual const std::vector<Transazione>& TutteLeTransazioni() = 0;

	virtual ~RegistroTransazioniInterface() = default;
};