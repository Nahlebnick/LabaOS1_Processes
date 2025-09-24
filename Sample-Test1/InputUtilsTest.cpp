#include "pch.h"
#include "../InputUtils/InputUtils.h"

TEST(InputTest, IntWrongInputTest)
{
	std::istringstream iss("Name");
	int n;
	ASSERT_DEATH({ n = getIntValue(iss);}, "Error while entering Int value");
}

TEST(InputTest, IntInputTest)
{
	std::istringstream iss("19");
	int n = getIntValue(iss);
	EXPECT_EQ(n, 19);
}

TEST(InputTest, DoubleWrongInputTest)
{
	std::istringstream iss("Name");
	double n;
	ASSERT_DEATH({ n = getDoubleValue(iss); }, "Error while entering Double value");
}

TEST(InputTest, DoubleInputTest)
{
	std::istringstream iss("2.5489");
	double n = getDoubleValue(iss);
	EXPECT_EQ(n, 2.5489);
}
