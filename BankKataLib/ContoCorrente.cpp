#include "stdafx.h"
#include "ContoCorrente.h"
#include "RegistroTransazioniInterface.h"

#include <stdexcept>

ContoCorrente::ContoCorrente(RegistroTransazioniInterface& registro)
	: registro_(registro)
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
	throw std::logic_error("Non implementato");
}
