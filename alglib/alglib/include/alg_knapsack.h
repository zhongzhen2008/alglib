#ifndef ALG_KNAPSACK_H_
#define ALG_KNAPSACK_H_

#include <algorithm>

using namespace std;

// 缺省用动态申请的解法，下面是用全局变量的解法
//const int MAX_LIMIT_WEIGHT = 1010;  // 背包最大重量的上限，注意预留少量空间
//const int MAX_SIZE = 110;           // 物品数量的上限，注意预留少量空间
//int knap[MAX_SIZE][MAX_LIMIT_WEIGHT];

/** 0-1背包问题：ALG_Knapsack_01   
*   
*     @param size 物品数量   
*     @param weight 物品重量，[1..size] 数组从1开始
*     @param value 物品价值，[1..size] 数组从1开始
*     @param limitWeight 背包最大重量  
*     @return    背包可纳入的最大价值和  */
template <class Type>
Type ALG_Knapsack_01(int size, int weight[], Type value[], int limitWeight)
{
    //memset(knap, 0, sizeof(knap));

    // 动态创建二维数组
    Type **knap;
    knap = new Type*[size + 5]; //行 //申请行的空间
    for (int i = 0; i < size + 5; i++)
    {
        knap[i] = new Type[limitWeight + 5];
    }

    // 核心算法
    for (int i = size; i >= 1; i--)
    {
        for (int j = 0; j <= limitWeight; j++)
        {
            if (i == size)
            {
                if (j >= weight[i])
                {
                    knap[i][j] = value[i];
                }
                else
                {
                    knap[i][j] = 0;
                }
            }
            else
            {
                if (j >= weight[i])
                {
                    knap[i][j] = max(knap[i + 1][j], knap[i + 1][j - weight[i]] + value[i]);
                }
                else
                {
                    knap[i][j] = knap[i + 1][j];
                }
            }
        }
    }

    Type result = knap[1][limitWeight];


    //删除刚才申请的二维数组内存
    for (int i = 0; i < size + 5; i++)
    {
        delete [] knap[i];
    }
    delete [] knap;

    return result;
}

#endif