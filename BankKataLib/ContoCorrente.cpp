#include "stdafx.h"
#include "ContoCorrente.h"
#include "RegistroTransazioniInterface.h"
#include "StampatoreDiMovimentiInterface.h"

#include <stdexcept>

ContoCorrente::ContoCorrente(RegistroTransazioniInterface& registro,
	StampatoreDiMovimentiInterface& stampatore)
	: registro_(registro), stampatore_(stampatore)
{
}

void ContoCorrente::Deposita(int importo)
{
	registro_.AggiungiDeposito(importo);
}

void ContoCorrente::Preleva(int importo)
{
	registro_.AggiungiPrelievo(importo);
}

void ContoCorrente::StampaMovimenti()
{
	stampatore_.Stampa(registro_.TutteLeTransazioni());
}
