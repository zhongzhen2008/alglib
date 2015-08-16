#include "../include/alg_sequence.h"

#include <gtest/gtest.h>

TEST(SequenceTest, LCS_string_01)
{
    string x = "abcbdab";
    string y = "bdcaba";
    string ret;
    EXPECT_EQ(4, ALG_LCS_string(x, y, ret));
    EXPECT_STREQ("bcba", ret.c_str());
}

TEST(SequenceTest, LCS_vector_01)
{
    char arr1[7] = {'a', 'b', 'c', 'b', 'd', 'a', 'b'};
    char arr2[6] = {'b', 'd', 'c', 'a', 'b', 'a'};
    vector <char> vec1(arr1, arr1 + 7);
    vector <char> vec2(arr2, arr2 + 6);
    vector <char> vecRet;

    EXPECT_EQ(4, ALG_LCS_vector(vec1, vec2, vecRet));
    EXPECT_EQ('b', vecRet[0]);
    EXPECT_EQ('c', vecRet[1]);
    EXPECT_EQ('b', vecRet[2]);
    EXPECT_EQ('a', vecRet[3]);
}

TEST(SequenceTest, LCSS_cstr_01)
{
    char x[] = "abcbdab";
    char y[] = "bdcaba";
    char ret[20] = {0};
    EXPECT_EQ(2, ALG_LCSS_cstr(x, y, ret));
    EXPECT_STREQ("ab", ret);
}

TEST(SequenceTest, LCSS_string_01)
{
    string x = "abcbdab";
    string y = "bdcaba";
    string ret;
    EXPECT_EQ(2, ALG_LCSS_string(x, y, ret));
    EXPECT_STREQ("ab", ret.c_str());
}

TEST(SequenceTest, MaxSub_vector_01)
{
    int arr1[9] = { -2, 1, -3, 4, -1, 2, 1, -5, 4};
    vector <int> vec1(arr1, arr1 + 9);
    int begin, end;

    EXPECT_EQ(6, ALG_MaxSub_vector(vec1, begin, end));
    EXPECT_EQ(3, begin);
    EXPECT_EQ(6, end);
}

TEST(SequenceTest, MaxSub_vector_02)
{
    int arr1[4] = { -1, -2, -3, -4};
    vector <int> vec1(arr1, arr1 + 4);
    int begin, end;

    EXPECT_EQ(0, ALG_MaxSub_vector(vec1, begin, end));
    EXPECT_EQ(0, begin);
    EXPECT_EQ(0, end);
}

TEST(SequenceTest, MaxSub_array_01)
{
    int arr1[9] = { -2, 1, -3, 4, -1, 2, 1, -5, 4};
    EXPECT_EQ(6, ALG_MaxSub_array(9, arr1));
}

TEST(SequenceTest, MaxSub_array_02)
{
    int arr1[4] = { -1, -2, -3, -4};
    EXPECT_EQ(0, ALG_MaxSub_array(4, arr1));
}

TEST(SequenceTest, MaxSubMatrix_array_01)
{
    int arr1[4][4] = {{0, -2, -7, 0},
        {9, 2, -6, 2},
        { -4, 1, -4, 1},
        { -1, 8, 0, -2}
    };
    int *arr2[4];
    arr2[0] = &arr1[0][0];
    arr2[1] = &arr1[1][0];
    arr2[2] = &arr1[2][0];
    arr2[3] = &arr1[3][0];

    EXPECT_EQ(15, ALG_MaxSubMatrix_array(4, 4, arr2));
}

TEST(SequenceTest, LNDS_vector_01)
{
    int arr1[] = {1, 9, 3, 8, 11, 4, 5, 6, 4, 19, 7, 1, 7};
    vector <int> vec1(arr1, arr1 + 13);
    vector <int> vec2;

    EXPECT_EQ(7, ALG_LNDS_vector(vec1, vec2));
    EXPECT_EQ(1, vec2[0]);
    EXPECT_EQ(7, vec2[5]);
    EXPECT_EQ(7, vec2[6]);
}

TEST(SequenceTest, LIS_vector_01)
{
    int arr1[] = {1, 9, 3, 8, 11, 4, 5, 6, 4, 19, 7, 1, 7};
    vector <int> vec1(arr1, arr1 + 13);
    vector <int> vec2;

    EXPECT_EQ(6, ALG_LIS_vector(vec1, vec2));
    EXPECT_EQ(1, vec2[0]);
    EXPECT_EQ(19, vec2[5]);
}

TEST(SequenceTest, EditDistance_01)
{
    string str1 = "abcdefg";
    string str2 = "bdffh";
    EXPECT_EQ(4, ALG_EditDistance(str1, str2));

    str1 = "a";
    str2 = "b";
    EXPECT_EQ(1, ALG_EditDistance(str1, str2));
}