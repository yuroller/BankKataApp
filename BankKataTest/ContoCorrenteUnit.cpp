#include "stdafx.h"
#include "gmock/gmock.h"

#include "ContoCorrente.h"
#include "MockRegistroTransazioni.h"

using namespace testing;

class ContoCorrenteUnit : public Test
{
public:
	ContoCorrenteUnit()
		: conto(registro)
	{ }

protected:
	MockRegistroTransazioni registro;
	ContoCorrente conto;
};

TEST_F(ContoCorrenteUnit, DepositaMemorizzaUnaTransazioneDiDeposito)
{
	EXPECT_CALL(registro, AggiungiDeposito(1000));

	conto.Deposita(1000);
}

TEST_F(ContoCorrenteUnit, DepositaMemorizzaUnaTransazioneDiPrelievo)
{
	EXPECT_CALL(registro, AggiungiPrelievo(200));

	conto.Preleva(200);
}