#include "stdafx.h"
#include "gmock/gmock.h"
#include "StampatoreDiMovimenti.h"
#include "MockTerminale.h"

using namespace testing;

class StampatoreDiMovimentiUnit : public Test
{
protected:
	StampatoreDiMovimentiUnit()
	: stampatore(terminale) {}

	MockTerminale terminale;
	StampatoreDiMovimenti stampatore;
};

TEST_F(StampatoreDiMovimentiUnit, StampaSempreIntestazione)
{
	EXPECT_CALL(terminale, StampaLinea("DATA       | IMPORTO | SALDO"));

	std::vector<Transazione> transazioni;
	stampatore.Stampa(transazioni);
}

TEST_F(StampatoreDiMovimentiUnit, StampaTransazioniInOrdineCronologicoInverso)
{
	{
		InSequence stampaCronologica;
		EXPECT_CALL(terminale, StampaLinea("DATA       | IMPORTO | SALDO"));
		EXPECT_CALL(terminale, StampaLinea("10/04/2014 |     500 |  1400"));
		EXPECT_CALL(terminale, StampaLinea("02/04/2014 |    -100 |   900"));
		EXPECT_CALL(terminale, StampaLinea("01/04/2014 |    1000 |  1000"));
	}

	std::vector<Transazione> transazioni = {
		{ 1000, "01/04/2014" },
		{ -100, "02/04/2014" },
		{  500, "10/04/2014" }
	};

	stampatore.Stampa(transazioni);
}