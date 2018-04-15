#pragma once

#include "RegistroTransazioniInterface.h"
#include "gmock/gmock.h"

class MockRegistroTransazioni : public RegistroTransazioniInterface {
public:
	MOCK_METHOD1(AggiungiDeposito,
		void(int importo));
	MOCK_METHOD1(AggiungiPrelievo,
		void(int importo));
	MOCK_METHOD0(TutteLeTransazioni,
		std::vector<Transazione>());
};
