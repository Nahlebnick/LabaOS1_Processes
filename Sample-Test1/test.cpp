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

