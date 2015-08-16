#ifndef ALG_SEQUENCE_H_
#define ALG_SEQUENCE_H_

#include "alg_util.h"
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/** 最长公共子序列 LCS(Longest Common Subsequence)，元素无需相邻，时间复杂度O(m*n)
*
*     @param[in] x 第1个序列
*     @param[in] y 第2个序列
*     @param[out] result 输出最长公共子序列
*     @return  最长公共子序列长度
*     @note  动态规划，递推公式：
*     @note       c[i][j] = 0                           (i=0, or j=0)
*     @note       c[i][j] = c[i-1][j-1] + 1             (i,j>0; x[i] = y[j])
*     @note       c[i][j] = max{c[i][j-1], c[i-1][j]}   (i,j>0; x[i] != y[j])
*/
template <class Type>
int ALG_LCS_vector(vector<Type> x, vector<Type> y, vector<Type> &result)
{
    int lenx = x.size();
    int leny = y.size();
    if (lenx == 0 || leny == 0)
    {
        return 0;
    }

    result.clear();

    int **c;
    int **b;
    ALG_Make2DArray(c, lenx + 1, leny + 1);
    ALG_Make2DArray(b, lenx + 1, leny + 1);

    // 计算最优值
    for (int i = 0; i <= lenx; i++)
    {
        c[i][0] = 0;
        b[i][0] = 0;
    }
    for (int j = 0; j <= leny; j++)
    {
        c[0][j] = 0;
        b[0][j] = 0;
    }

    for (int i = 1; i <= lenx; i++)
    {
        for (int j = 1; j <= leny; j++)
        {
            if (x[i - 1] == y[j - 1])
            {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = 1;
            }
            else if (c[i - 1][j] >= c[i][j - 1])
            {
                c[i][j] = c[i - 1][j];
                b[i][j] = 2;
            }
            else
            {
                c[i][j] = c[i][j - 1];
                b[i][j] = 3;
            }
        }
    }

    int lenRet = c[lenx][leny];

    //ALG_Print2DArray(c, lenx + 1, leny + 1);
    //ALG_Print2DArray(b, lenx + 1, leny + 1);

    // 构造最优解
    int tracei = lenx;
    int tracej = leny;
    while (tracei != 0 && tracej != 0)
    {
        if (b[tracei][tracej] == 1)
        {
            result.insert(result.begin(), x[tracei - 1]);
            tracei -= 1;
            tracej -= 1;
        }
        else if (b[tracei][tracej] == 2)
        {
            tracei -= 1;
        }
        else
        {
            tracej -= 1;
        }
    }

    ALG_Delete2DArray(b, lenx + 1);
    ALG_Delete2DArray(c, lenx + 1);

    return lenRet;
}

/** 最长公共子序列 LCS(Longest Common Subsequence)，元素无需相邻
*
*     @param[in] x 第1个序列
*     @param[in] y 第2个序列
*     @param[out] result 输出最长公共子序列
*     @return  最长公共子序列长度
*     @note  动态规划，递推公式：
*     @note       c[i][j] = 0                           (i=0, or j=0)
*     @note       c[i][j] = c[i-1][j-1] + 1             (i,j>0; x[i] = y[j])
*     @note       c[i][j] = max{c[i][j-1], c[i-1][j]}   (i,j>0; x[i] != y[j])
*/
int ALG_LCS_string(string x, string y, string &result)
{
    vector <char> vecx;
    vector <char> vecy;
    vector <char> vecRet;
    vecx.assign(x.begin(), x.end());
    vecy.assign(y.begin(), y.end());

    int lenRet = ALG_LCS_vector(vecx, vecy, vecRet);
    result.assign(vecRet.begin(), vecRet.end());
    return lenRet;
}

/** 最长非减子序列，元素无需相邻，时间复杂度O(n*n)
*
*     @param[in] x 第1个序列
*     @param[out] result 输出最长非减子序列
*     @return  最长非减子序列长度
*     @note  思路：用本数组新建一个数组，新数组按非减排序，再用LCS 求解
*/
template <class Type>
int ALG_LNDS_vector(vector<Type> x, vector<Type> &result)
{
    vector<Type> y(x);
    sort(y.begin(), y.end());

    int lenRet = ALG_LCS_vector(x, y, result);
    return lenRet;
}

/** 最长递增子序列，Longest Increase Subsequence，元素无需相邻，时间复杂度O(n*n)
*
*     @param[in] x 第1个序列
*     @param[out] result 输出最长递增子序列
*     @return  最长递增子序列长度
*     @note  思路：用本数组新建一个Set集合，可自动去重、并排序，再用LCS 求解
*/
template <class Type>
int ALG_LIS_vector(vector<Type> x, vector<Type> &result)
{
    set<Type> sety;
    int lenx = x.size();
    for (int i = 0; i < lenx; i++)
    {
        sety.insert(x[i]);
    }

    vector<Type> y;
    set<int>::iterator it;
    //中序遍历集合中的所有元素，即从小到大排序
    for (it = sety.begin(); it != sety.end(); ++it)
    {
        y.push_back(*it);
    }

    int lenRet = ALG_LCS_vector(x, y, result);
    return lenRet;
}

/** 最长公共子串 LCS(Longest Common Substring)，元素必须相邻，时间复杂度O(n*n)
*
*     @param[in] x 第1个字符串
*     @param[in] y 第2个字符串
*     @param[out] result 输出最长公共子串
*     @return  最长公共子序列长度
*     @note  动态规划
*     @note  http://blog.csdn.net/sunmeng_alex/article/details/8102154
*/
int ALG_LCSS_string(string x, string y, string &result)
{
    int lenx = x.length();  //获取字串的长度
    int leny = y.length();

    int **c;                //矩阵c记录两串的匹配情况
    ALG_Make2DArray(c, lenx, leny);

    int start, end, len, i, j; //start表明最长公共子串的起始点，end表明最长公共子串的终止点
    end = len = 0;          //len表明最长公共子串的长度
    for (i = 0; i < lenx; i++) //串开始从前向后比较
    {
        for (j = 0; j < leny; j++)
        {
            if (x[i] == y[j])
            {
                if (i == 0 || j == 0)
                {
                    c[i][j] = 1;
                }
                else
                {
                    c[i][j] = c[i - 1][j - 1] + 1;
                }
            }
            else
            {
                c[i][j] = 0;
            }
            if (c[i][j] > len)
            {
                len = c[i][j];
                end = j;
            }
        }
    }

    ALG_Delete2DArray(c, lenx);

    // 记录最长公共子串
    start = end - len + 1;
    result = y.substr(start, len);

    return len;
}

/** 最长公共子串 LCS(Longest Common Substring)，元素必须相邻，时间复杂度O(n*n)
*
*     @param[in] x 第1个字符串
*     @param[in] y 第2个字符串
*     @param[out] result 输出最长公共子串，需要函数调用方负责申请和释放足够大小的内存
*     @return  最长公共子序列长度
*     @note  动态规划
*     @note  http://blog.csdn.net/sunmeng_alex/article/details/8102154
*/
int ALG_LCSS_cstr(char *x, char *y, char *result)
{
    string sx(x);
    string sy(y);
    string sret;

    int len = ALG_LCSS_string(sx, sy, sret);
    strcpy(result, sret.c_str());
    return len;
}

/** 最大子数组 maximum subarray，要找出由数组成的一维数组中和最大的连续子数组，时间复杂度O(n)
*
*     @param[in] arr 待分析数组
*     @param[out] begin 最大子数组起始索引
*     @param[out] end 最大子数组结束索引
*     @return  最大子数组的和，全负数则返回0
*     @note  比如{5,-3,4,2}的最大子序列就是 {5,-3,4,2}，它的和是8,达到最大；而{5,-6,4,2}的最大子序列是{4,2}，它的和是6
*     @note  http://www.cnblogs.com/zhangchaoyang/articles/2012070.html
*     @note  《算法导论》4.1，《编程之美》，《编程珠玑》
*     @note  http://blog.kingsamchen.com/archives/743
*     @note  http://www.cnblogs.com/waytofall/archive/2012/04/10/2439820.html
*     @note  http://blog.nlogn.cn/programming-pearls-the-maximum-sum-of-substring/
*     @note  http://blog.163.com/chenhao0528@yeah/blog/static/172439055201191810272699/
*/
int ALG_MaxSub_vector(const vector<int> arr, int &begin, int &end)
{
    int maxSum = 0;
    int currSum = 0;
    int newbegin = 0;

    begin = end = 0;

    int len = arr.size();
    for (int i = 0; i < len; ++i)
    {
        currSum += arr[i];
        if (currSum > maxSum)
        {
            maxSum = currSum;
            begin = newbegin;
            end = i;
        }
        if (currSum < 0)
        {
            currSum = 0;
            newbegin = i + 1;
        }
    }

    return maxSum;
}

/** 最大子数组 maximum subarray，要找出由数组成的一维数组中和最大的连续子数组，时间复杂度O(n)
*
*     @param[in] n 待分析数组长度
*     @param[in] a 待分析数组
*     @return  最大子数组的和，全负数则返回0
*     @note  比如{5,-3,4,2}的最大子序列就是 {5,-3,4,2}，它的和是8,达到最大；而{5,-6,4,2}的最大子序列是{4,2}，它的和是6
*     @note  王晓东《计算机算法设计与分析》P57
*/
int ALG_MaxSub_array(int n, int *a)
{
    int sum = 0;
    int b = 0;
    for (int i = 0; i < n; i++)
    {
        if (b > 0)
        {
            b += a[i];
        }
        else
        {
            b = a[i];
        }

        if (b > sum)
        {
            sum = b;
        }
    }
    return sum;
}

/** 最大子矩阵，时间复杂度O(m*m*n)
*
*     @param[in] m 矩阵行数
*     @param[in] n 矩阵列数
*     @param[in] a 待分析矩阵，二维数组
*     @return  最大子矩阵的和，全负数则返回0
*     @note  王晓东《计算机算法设计与分析》P57，《编程之美》
*/
int ALG_MaxSubMatrix_array(int m, int n, int** a)
{
    int sum = 0;
    int *b = new int[n];
    for (int i = 0; i < m; i++)
    {
        for (int k = 0; k < n; k++)
        {
            b[k] = 0;
        }

        for (int j = i; j < m; j++)
        {
            for (int k = 0; k < n; k++)
            {
                b[k] += a[j][k];
            }
            int max = ALG_MaxSub_array(n, b);
            if (max > sum)
            {
                sum = max;
            }
        }
    }
    delete[] b;

    return sum;
}

/** 字符串编辑距离，字符串相似度
*
*     @param[string] x 原始字符串
*     @param[string] y 目标字符串
*     @return  字符串编辑距离
*     @note  http://blog.csdn.net/orbit/article/details/6649322，
*     @note  《编程之美》3.3
*/
int ALG_EditDistance(string x, string y)
{
    int lenx = x.size();
    int leny = y.size();
    if (lenx == 0 || leny == 0)
    {
        return 0;
    }

    int **dis;
    ALG_Make2DArray(dis, lenx + 1, leny + 1);

    for (int i = 0; i <= lenx; i++)
    {
        dis[i][0] = i;
    }
    for (int j = 0; j <= leny; j++)
    {
        dis[0][j] = j;
    }

    for (int i = 1; i <= lenx; i++)
    {
        for (int j = 1; j <= leny; j++)
        {
            if ((x[i - 1] == y[j - 1]))
            {
                dis[i][j] = dis[i - 1][j - 1]; //不需要编辑操作
            }
            else
            {
                int edIns = dis[i][j - 1] + 1;      //x 插入字符
                int edDel = dis[i - 1][j] + 1;      //x 删除字符
                int edRep = dis[i - 1][j - 1] + 1;  //x 替换字符

                dis[i][j] = min(min(edIns, edDel), edRep);
            }
        }
    }

    int ret = dis[lenx][leny];
    ALG_Delete2DArray(dis, lenx);

    return ret;
}

#endif