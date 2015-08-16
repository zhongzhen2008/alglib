#include "../include/alg_search.h"

#include <gtest/gtest.h>

TEST(SearchTest, BinarySearch_Success)
{
    int a[] = {3, 7, 10, 15, 19, 22};
    EXPECT_EQ(2, ALG_BinarySearch(a, 10, 0, 5));
}

TEST(SearchTest, BinarySearch_Fail)
{
    int a[] = {3, 7, 10, 15, 19, 22};
    EXPECT_EQ(-1, ALG_BinarySearch(a, 11, 0, 5));
}