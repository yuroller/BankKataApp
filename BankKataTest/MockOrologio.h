#pragma once

#include "OrologioInterface.h"
#include "gmock/gmock.h"

class MockOrologio : public OrologioInterface {
public:
	MOCK_METHOD0(DataComeStringa,
		std::string());
};
