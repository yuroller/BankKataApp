// BankKataApp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ContoCorrente.h"
#include "RegistroTransazioni.h"
#include "StampatoreDiMovimenti.h"
#include "Orologio.h"
#include "Terminale.h"

int main()
{
	Orologio orologio;
	Terminale terminale;
	RegistroTransazioni registro(orologio);
	StampatoreDiMovimenti stampatore(terminale);
	ContoCorrente conto(registro, stampatore);

	conto.Deposita(1000);
	conto.Preleva(100);
	conto.Deposita(500);

	conto.StampaMovimenti();

    return 0;
}

