#include "stdafx.h"
#include "Orologio.h"
#include "gmock/gmock.h"
#include <ctime>

using namespace testing;

class OrologioTestabile : public Orologio
{
protected:
	std::chrono::system_clock::time_point Data() {
		std::tm tm = { 0 };
		tm.tm_mday = 14;
		tm.tm_mon = 4 - 1;
		tm.tm_year = 2018 - 1900;
		tm.tm_isdst = -1;

		std::time_t tt = mktime(&tm);
		return std::chrono::system_clock::from_time_t(tt);
	}
};

TEST(OrologioUnit, DataComeStringa_RestituisceDataInFormatoDDMMYYYY)
{
	OrologioTestabile orologio;
	EXPECT_THAT(orologio.DataComeStringa(), Eq("14/04/2018"));
}