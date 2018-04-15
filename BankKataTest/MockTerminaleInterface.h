#pragma once

#include "TerminaleInterface.h"
#include "gmock/gmock.h"

class MockTerminaleInterface : public TerminaleInterface {
public:
	MOCK_METHOD1(StampaLinea,
		void(const std::string& testo));
};
