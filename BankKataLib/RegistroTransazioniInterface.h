#pragma once

class RegistroTransazioniInterface
{
public:
	virtual void AggiungiDeposito(int importo) = 0;
	virtual void AggiungiPrelievo(int importo) = 0;
	virtual ~RegistroTransazioniInterface() = default;
};