#include "stdafx.h"
#include "ContoCorrente.h"
#include "RegistroTransazioni.h"
#include "StampatoreDiMovimenti.h"
#include "MockOrologio.h"
#include "MockTerminale.h"
#include "gmock/gmock.h"

using namespace testing;

TEST(Accettazione, StampaMovimentiInOrdineCronologicoInverso)
{
	MockOrologio orologio;
	RegistroTransazioni registro(orologio);
	StampatoreDiMovimenti stampatore;
	MockTerminale terminale;

	EXPECT_CALL(orologio, DataComeStringa())
		.WillOnce(Return("01/04/2014"))
		.WillOnce(Return("02/04/2014"))
		.WillOnce(Return("10/04/2014"));

	{
		InSequence stampaCronologica;
		EXPECT_CALL(terminale, StampaLinea("DATA       | IMPORTO | SALDO"));
		EXPECT_CALL(terminale, StampaLinea("10/04/2014 |     500 |  1400"));
		EXPECT_CALL(terminale, StampaLinea("02/04/2014 |    -100 |   900"));
		EXPECT_CALL(terminale, StampaLinea("01/04/2014 |    1000 |  1000"));
	}

	ContoCorrente conto(registro, stampatore);

	conto.Deposita(1000);
	conto.Preleva(100);
	conto.Deposita(500);

	conto.StampaMovimenti();
}