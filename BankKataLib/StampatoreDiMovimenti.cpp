#include "stdafx.h"
#include "StampatoreDiMovimenti.h"
#include "TerminaleInterface.h"
#include "Transazione.h"
#include <sstream>
#include <iomanip>
#include <numeric>

StampatoreDiMovimenti::StampatoreDiMovimenti(TerminaleInterface& terminale)
	: terminale_(terminale)
{
}

void StampatoreDiMovimenti::Stampa(const std::vector<Transazione>& transazioni)
{
	terminale_.StampaLinea("DATA       | IMPORTO | SALDO");
	
	int saldo = std::accumulate(transazioni.begin(), transazioni.end(), 0,
		[](int acc, const Transazione& tr) { return acc + tr.importo(); });
	for (auto it = transazioni.rbegin(); it != transazioni.rend(); ++it) {
		std::stringstream ss;
		ss << it->data() << " | "
			<< std::setw(7) << it->importo() << " | "
			<< std::setw(5) << saldo;
		saldo -= it->importo();
		terminale_.StampaLinea(ss.str());
	}
}
