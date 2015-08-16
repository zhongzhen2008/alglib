#ifndef ALG_KNAPSACK_H_
#define ALG_KNAPSACK_H_

#include <algorithm>

using namespace std;

// ȱʡ�ö�̬����Ľⷨ����������ȫ�ֱ����Ľⷨ
//const int MAX_LIMIT_WEIGHT = 1010;  // ����������������ޣ�ע��Ԥ�������ռ�
//const int MAX_SIZE = 110;           // ��Ʒ���������ޣ�ע��Ԥ�������ռ�
//int knap[MAX_SIZE][MAX_LIMIT_WEIGHT];

/** 0-1�������⣺ALG_Knapsack_01   
*   
*     @param size ��Ʒ����   
*     @param weight ��Ʒ������[1..size] �����1��ʼ
*     @param value ��Ʒ��ֵ��[1..size] �����1��ʼ
*     @param limitWeight �����������  
*     @return    ���������������ֵ��  */
template <class Type>
Type ALG_Knapsack_01(int size, int weight[], Type value[], int limitWeight)
{
    //memset(knap, 0, sizeof(knap));

    // ��̬������ά����
    Type **knap;
    knap = new Type*[size + 5]; //�� //�����еĿռ�
    for (int i = 0; i < size + 5; i++)
    {
        knap[i] = new Type[limitWeight + 5];
    }

    // �����㷨
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


    //ɾ���ղ�����Ķ�ά�����ڴ�
    for (int i = 0; i < size + 5; i++)
    {
        delete [] knap[i];
    }
    delete [] knap;

    return result;
}

#endif