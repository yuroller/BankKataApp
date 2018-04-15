#include "stdafx.h"
#include "ContoCorrente.h"
#include "MockTerminaleInterface.h"
#include "gmock/gmock.h"

using namespace testing;

TEST(Accettazione, StampaMovimentiInOrdineCronologicoInverso)
{
	MockTerminaleInterface terminale;
	
	{
		InSequence stampaCronologica;
		EXPECT_CALL(terminale, StampaLinea("DATA       | IMPORTO | SALDO"));
		EXPECT_CALL(terminale, StampaLinea("10/04/2014 |     500 |  1400"));
		EXPECT_CALL(terminale, StampaLinea("02/04/2014 |    -100 |   900"));
		EXPECT_CALL(terminale, StampaLinea("01/04/2014 |    1000 |  1000"));
	}

	ContoCorrente conto;

	conto.Deposita(1000);
	conto.Preleva(100);
	conto.Deposita(500);

	conto.StampaMovimenti();
}