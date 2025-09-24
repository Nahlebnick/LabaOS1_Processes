#include "pch.h"
#include "../employee.h"

TEST(EmployeeTest, ConstructorTest)
{
	employee emp{ 10, 25.4 , "Stepan"};
	EXPECT_EQ(emp.num, 10);
	EXPECT_EQ(emp.hours, 25.4);
	EXPECT_EQ(std::strcmp(emp.name, "Stepan"), 0);
}

TEST(EmployeeTest, InputEmployeeTest)
{
	std::istringstream iss("45 Stepan 25.4");
	employee emp;
	ASSERT_NO_FATAL_FAILURE({ iss >> emp; });
	EXPECT_EQ(emp.num, 45);
	EXPECT_EQ(emp.hours, 25.4);
	EXPECT_EQ(std::strcmp(emp.name, "Stepan"), 0);
}

TEST(EmployeeTest, CompareEmployeesTest)
{
	employee emp1{ 5, 40.5, "Stepan" };
	employee emp2{ 2, 35.8, "Timofey" };
	EXPECT_TRUE(emp1 > emp2);
	EXPECT_FALSE(emp1 < emp2);
}




