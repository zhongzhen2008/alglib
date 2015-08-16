#include "../include/alg_string.h"

#include <gtest/gtest.h>

TEST(StringTest, StringSplit_01)
{
	string str1 = "This is a test.";
	vector<string> vecRet = ALG_StringSplit(str1, " ");
	EXPECT_EQ(4, vecRet.size());
	EXPECT_STREQ("This", vecRet[0].c_str());
	EXPECT_STREQ("test.", vecRet[3].c_str());
}

TEST(StringTest, StringTrim_01)
{
    string str1 = "  This is a test.   ";
    ALG_StringTrimLeft(str1, ' ');
    EXPECT_STREQ("This is a test.   ", str1.c_str());
    ALG_StringTrimRight(str1, ' ');
    EXPECT_STREQ("This is a test.", str1.c_str());

    string str2 = "   ";
    ALG_StringTrimLeft(str2, ' ');
    EXPECT_STREQ("", str2.c_str());

    string str3 = "   ";
    ALG_StringTrimRight(str3, ' ');
    EXPECT_STREQ("", str3.c_str());

    string str4 = "  This is a test.   ";
    ALG_StringTrim(str4);
    EXPECT_STREQ("This is a test.", str4.c_str());

    string str5 = "aa  This is a test.   bca";
    ALG_StringTrim(str5, 'a');
    EXPECT_STREQ("  This is a test.   bc", str5.c_str());
}
