#include "../include/alg_knapsack.h"

#include <gtest/gtest.h>

TEST(KnapsackTest, Knapsack_int)
{
    int size = 5;
    int limitWeight = 100;
    int weight[] = {0, 77, 22, 29, 50, 99};
    int value[] = {0, 92, 22, 87, 46, 90};
    EXPECT_EQ(133, ALG_Knapsack_01(size, weight, value, limitWeight));
}

TEST(KnapsackTest, Knapsack_double)
{
    int size = 5;
    int limitWeight = 100;
    int weight[] = {0, 77, 22, 29, 50, 99};
    double value[] = {0, 92.1, 22.2, 87.3, 46.8, 90.9};
    EXPECT_DOUBLE_EQ(134.1, ALG_Knapsack_01(size, weight, value, limitWeight));
}
