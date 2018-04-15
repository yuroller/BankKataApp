#include "stdafx.h"
#include "gmock/gmock.h"

#include "ContoCorrente.h"
#include "Transazione.h"
#include "MockRegistroTransazioni.h"
#include "MockStampatoreDiMovimenti.h"

using namespace testing;

class ContoCorrenteUnit : public Test
{
public:
	ContoCorrenteUnit()
		: conto(registro, stampatore)
	{ }

protected:
	MockRegistroTransazioni registro;
	MockStampatoreDiMovimenti stampatore;
	ContoCorrente conto;
};

TEST_F(ContoCorrenteUnit, Deposita_MemorizzaUnaTransazioneDiDeposito)
{
	EXPECT_CALL(registro, AggiungiDeposito(1000));

	conto.Deposita(1000);
}

TEST_F(ContoCorrenteUnit, Preleva_MemorizzaUnaTransazioneDiPrelievo)
{
	EXPECT_CALL(registro, AggiungiPrelievo(200));

	conto.Preleva(200);
}

TEST_F(ContoCorrenteUnit, StampaMovimenti)
{
	std::vector<Transazione> transazioni;
	ON_CALL(registro, TutteLeTransazioni())
		.WillByDefault(Return(transazioni));

	EXPECT_CALL(stampatore, Stampa(ContainerEq(transazioni)));

	conto.StampaMovimenti();
}