#include "stdafx.h"
#include "gmock/gmock.h"
#include "RegistroTransazioni.h"
#include "MockOrologio.h"

using namespace testing;

class RegistroTransazioniUnit : public Test
{
protected:
	RegistroTransazioniUnit() 
	: registro(orologio)
	{}

	MockOrologio orologio;
	RegistroTransazioni registro;
};

TEST_F(RegistroTransazioniUnit, CreaEMemorizzaUnaTransazioneDiDeposito)
{
	ON_CALL(orologio, DataComeStringa())
		.WillByDefault(Return("20/02/2018"));

	registro.AggiungiDeposito(300);

	auto transazioni = registro.TutteLeTransazioni();
	EXPECT_THAT(transazioni, ElementsAre(Transazione(300, "20/02/2018")));
}

TEST_F(RegistroTransazioniUnit, CreaEMemorizzaUnaTransazioneDiPrelievo)
{
	ON_CALL(orologio, DataComeStringa())
		.WillByDefault(Return("15/03/2018"));

	registro.AggiungiPrelievo(50);

	auto transazioni = registro.TutteLeTransazioni();
	EXPECT_THAT(transazioni, ElementsAre(Transazione(-50, "15/03/2018")));
}