#pragma once

#include "RegistroTransazioniInterface.h"
#include "Transazione.h"
#include <vector>

class OrologioInterface;

class RegistroTransazioni : public RegistroTransazioniInterface
{
public:
	RegistroTransazioni(OrologioInterface& orologio);

	// Inherited via RegistroTransazioniInterface
	virtual void AggiungiDeposito(int importo) override;
	virtual void AggiungiPrelievo(int importo) override;
	virtual std::vector<Transazione> TutteLeTransazioni() override;

private:
	OrologioInterface& orologio_;
	std::vector<Transazione> transazioni_;
};