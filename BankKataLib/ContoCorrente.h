#pragma once

class ContoCorrente
{
public:
	ContoCorrente();

	void Deposita(int importo);
	void Preleva(int importo);
	void StampaMovimenti();
};