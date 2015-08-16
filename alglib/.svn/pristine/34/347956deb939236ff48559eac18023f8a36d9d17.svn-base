#ifndef ALG_UTIL_H_
#define ALG_UTIL_H_

#include <iostream>

using namespace std;

/** 动态创建二维数组
*
*     @param x 将要创建的二维数组
*     @param rows 二维数组行数
*     @param cols 二维数组列数
*     @return  无
*/
template <class Type>
void ALG_Make2DArray(Type** &x, int rows, int cols)
{
    x = new Type*[rows];
    for (int i = 0; i < rows; i++)
    {
        x[i] = new Type[cols]();
    }
}

/** 释放之前动态创建的二维数组
*
*     @param x 将要创建的二维数组
*     @param rows 二维数组行数
*     @return  无
*/
template <class Type>
void ALG_Delete2DArray(Type** &x, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        delete[] x[i];
    }
    delete[] x;
    x = 0;
}
template <class Type>
void ALG_Print2DArray(Type** x, int rows, int cols)
{
    cout << endl << "Print 2DArray:" << endl;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << x[i][j] << " ";
        }
        cout << endl;
    }
}


#endif