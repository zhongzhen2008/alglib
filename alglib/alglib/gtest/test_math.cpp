#include "../include/alg_math.h"

#include <gtest/gtest.h>

TEST(MathTest, PermutationCalc_01)
{
    EXPECT_EQ(12, ALG_PermutationCalc(4, 2));
}

TEST(MathTest, CombinationCalc_01)
{
    EXPECT_EQ(6, ALG_CombinationCalc(4, 2));
}

TEST(MathTest, Permutation_01)
{
    EXPECT_EQ(24, ALG_Permutation(4));
}

TEST(MathTest, Combination_01)
{
    EXPECT_EQ(6, ALG_Combination(4, 2));
}

TEST(MathTest, Gcd_01)
{
    EXPECT_EQ(195, ALG_Gcd(64155, 66300));
    EXPECT_EQ(12, ALG_Gcd(0, 12));
    EXPECT_EQ(12, ALG_Gcd(12, 12));
}

TEST(MathTest, Lcm_01)
{
    EXPECT_EQ(21812700, ALG_Lcm(64155, 66300));
    EXPECT_EQ(0, ALG_Lcm(0, 12));
    EXPECT_EQ(12, ALG_Lcm(12, 12));
}

TEST(MathTest, IsPrime_01)
{
    EXPECT_EQ(false, ALG_IsPrime(1));
    EXPECT_EQ(true, ALG_IsPrime(2));
    EXPECT_EQ(true, ALG_IsPrime(3));
    EXPECT_EQ(true, ALG_IsPrime(13));
    EXPECT_EQ(false, ALG_IsPrime(15));
    EXPECT_EQ(true, ALG_IsPrime(997));
}

TEST(MathTest, SievePrime_01)
{
    ALG_SievePrime();
    EXPECT_EQ(false, primeMark[1]);
    EXPECT_EQ(true, primeMark[2]);
    EXPECT_EQ(true, primeMark[3]);
    EXPECT_EQ(true, primeMark[13]);
    EXPECT_EQ(false, primeMark[15]);
    EXPECT_EQ(true, primeMark[997]);
}

TEST(MathTest, ChangeRadix_01)
{
    char strIn[] = "123456";
    char strOut[100] = {0};
    ALG_ChangeRadix(strIn, strOut, 10, 8);
    EXPECT_STREQ("361100", strOut);
}

TEST(MathTest, Euler_01)
{
    EXPECT_EQ(6, ALG_Euler(7));
    EXPECT_EQ(4, ALG_Euler(12));
}