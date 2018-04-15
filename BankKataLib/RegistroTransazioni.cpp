#include "stdafx.h"
#include "RegistroTransazioni.h"
#include <stdexcept>

void RegistroTransazioni::AggiungiDeposito(int importo)
{
	throw std::logic_error("Non implementato");
}

void RegistroTransazioni::AggiungiPrelievo(int importo)
{
	throw std::logic_error("Non implementato");
}

const std::vector<Transazione>& RegistroTransazioni::TutteLeTransazioni()
{
	throw std::logic_error("Non implementato");
}
