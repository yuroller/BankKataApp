#include "stdafx.h"
#include "RegistroTransazioni.h"
#include "OrologioInterface.h"

RegistroTransazioni::RegistroTransazioni(OrologioInterface& orologio)
	: orologio_(orologio)
{
}

void RegistroTransazioni::AggiungiDeposito(int importo)
{
	transazioni_.emplace_back(importo, orologio_.DataComeStringa());
}

void RegistroTransazioni::AggiungiPrelievo(int importo)
{
	transazioni_.emplace_back(-importo, orologio_.DataComeStringa());
}

std::vector<Transazione> RegistroTransazioni::TutteLeTransazioni()
{
	return transazioni_;
}
