#pragma once

#include "RegistroTransazioniInterface.h"

class RegistroTransazioni : public RegistroTransazioniInterface
{
public:
	// Inherited via RegistroTransazioniInterface
	virtual void AggiungiDeposito(int importo) override;
	virtual void AggiungiPrelievo(int importo) override;
};