#pragma once
#include "StampatoreDiMovimentiInterface.h"
#include "gtest/gtest.h"

class MockStampatoreDiMovimenti : public StampatoreDiMovimentiInterface {
public:
	MOCK_METHOD1(Stampa,
		void(const std::vector<Transazione>& transazioni));
};
