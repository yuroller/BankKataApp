#pragma once

class RegistroTransazioniInterface;

class ContoCorrente
{
public:
	ContoCorrente(RegistroTransazioniInterface& registro);

	void Deposita(int importo);
	void Preleva(int importo);
	void StampaMovimenti();

private:
	RegistroTransazioniInterface& registro_;
};