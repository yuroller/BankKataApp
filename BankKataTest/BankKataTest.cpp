// BankKataTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "gmock/gmock.h"
using namespace testing;

// Bank kata
// =========

// https://github.com/sandromancuso/Bank-kata
// https://www.youtube.com/watch?v=XHnuMjah6ps

// Creare una semplice applicazione bancaria con le seguenti funzionalità:
// * deposito in un conto corrente
// * prelievo da un conto corrente
// * stampare i movimenti del conto corrente sul terminale

// Criteri di accettazione:
// la stampa dei movimenti ha il seguente formato

// DATA       | IMPORTO | SALDO
// 10/04/2014 |     500 |  1400
// 02/04/2014 |    -100 |   900
// 01/04/2014 |    1000 |  1000

// Vincoli:
// * utilizzare una classe con questa struttura:
//    class ContoCorrente
//    {
//    public:
//	    void Deposita(int importo);
//	    void Preleva(int importo);
//	    void StampaMovimenti();
//    };
// * non puoi aggiungere metodi pubblici alla classe
// * per mantenere le cose semplici usiamo int per gli importi e std::string per le date
// * la spaziatura nella stampa dei movimenti non è vincolante
