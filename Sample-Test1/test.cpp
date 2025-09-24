#include "pch.h"
#include "../FileUtils/FileUitls.h" 

TEST(GetFilenameTest, AddsDefautExtansion)
{
	std::istringstream in("report");
	EXPECT_EQ(getFilename(in,".txt"), "report.txt");
}

TEST(GetFilenameTest, HandlesUserExtansion)
{
	std::istringstream in("file.bin");
	EXPECT_EQ(getFilename(in, ".txt"), "file.bin");
}

TEST(IOEmployeesTest, ReadEmployees)
{
	std::stringstream ss(std::ios::in | std::ios::out | std::ios::binary);
	employee emp1{ 1, 40.5, "Stepan"};
	employee emp2{ 2, 35.8, "Timofey"};
	ss.write((char*)&emp1, sizeof(employee));
	ss.write((char*)&emp2, sizeof(employee));

	ss.seekg(0);
	auto employees = readEmployees(ss);

	ASSERT_EQ(employees.size(), 2);
	EXPECT_EQ(employees[0].num, 1);
	EXPECT_EQ(employees[1].hours, 35.8);
}

TEST(IOEmployeesTest, WrtieEmployees)
{
	std::stringstream ss(std::ios::in | std::ios::out | std::ios::binary);
	employee emp1{ 1, 40.5, "Stepan" };
	employee emp2{ 2, 35.8, "Timofey" };
	std::vector<employee> emps;
	emps.push_back(emp1);
	emps.push_back(emp2);

	writeEmployees(ss, emps);
	
	ss.seekg(0);
	auto employees = readEmployees(ss);
	ASSERT_EQ(employees.size(), 2);
	EXPECT_EQ(employees[0].num, 1);
	EXPECT_EQ(employees[1].hours, 35.8);
}

