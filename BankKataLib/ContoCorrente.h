#pragma once

class RegistroTransazioniInterface;
class StampatoreDiMovimentiInterface;

class ContoCorrente
{
public:
	ContoCorrente(RegistroTransazioniInterface& registro,
		StampatoreDiMovimentiInterface& stampatore);

	void Deposita(int importo);
	void Preleva(int importo);
	void StampaMovimenti();

private:
	RegistroTransazioniInterface& registro_;
	StampatoreDiMovimentiInterface& stampatore_;
};