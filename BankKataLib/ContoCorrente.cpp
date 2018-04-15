#include "stdafx.h"
#include "ContoCorrente.h"
#include <stdexcept>

ContoCorrente::ContoCorrente()
{
}

void ContoCorrente::Deposita(int importo)
{
	throw std::logic_error("Non implementato");
}

void ContoCorrente::Preleva(int importo)
{
	throw std::logic_error("Non implementato");
}

void ContoCorrente::StampaMovimenti()
{
	throw std::logic_error("Non implementato");
}
