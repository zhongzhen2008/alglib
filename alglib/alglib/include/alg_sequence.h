#ifndef ALG_SEQUENCE_H_
#define ALG_SEQUENCE_H_

#include "alg_util.h"
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/** ����������� LCS(Longest Common Subsequence)��Ԫ���������ڣ�ʱ�临�Ӷ�O(m*n)
*
*     @param[in] x ��1������
*     @param[in] y ��2������
*     @param[out] result ��������������
*     @return  ����������г���
*     @note  ��̬�滮�����ƹ�ʽ��
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

    // ��������ֵ
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

    // �������Ž�
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

/** ����������� LCS(Longest Common Subsequence)��Ԫ����������
*
*     @param[in] x ��1������
*     @param[in] y ��2������
*     @param[out] result ��������������
*     @return  ����������г���
*     @note  ��̬�滮�����ƹ�ʽ��
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

/** ��Ǽ������У�Ԫ���������ڣ�ʱ�临�Ӷ�O(n*n)
*
*     @param[in] x ��1������
*     @param[out] result �����Ǽ�������
*     @return  ��Ǽ������г���
*     @note  ˼·���ñ������½�һ�����飬�����鰴�Ǽ���������LCS ���
*/
template <class Type>
int ALG_LNDS_vector(vector<Type> x, vector<Type> &result)
{
    vector<Type> y(x);
    sort(y.begin(), y.end());

    int lenRet = ALG_LCS_vector(x, y, result);
    return lenRet;
}

/** ����������У�Longest Increase Subsequence��Ԫ���������ڣ�ʱ�临�Ӷ�O(n*n)
*
*     @param[in] x ��1������
*     @param[out] result ��������������
*     @return  ����������г���
*     @note  ˼·���ñ������½�һ��Set���ϣ����Զ�ȥ�ء�����������LCS ���
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
    //������������е�����Ԫ�أ�����С��������
    for (it = sety.begin(); it != sety.end(); ++it)
    {
        y.push_back(*it);
    }

    int lenRet = ALG_LCS_vector(x, y, result);
    return lenRet;
}

/** ������Ӵ� LCS(Longest Common Substring)��Ԫ�ر������ڣ�ʱ�临�Ӷ�O(n*n)
*
*     @param[in] x ��1���ַ���
*     @param[in] y ��2���ַ���
*     @param[out] result ���������Ӵ�
*     @return  ����������г���
*     @note  ��̬�滮
*     @note  http://blog.csdn.net/sunmeng_alex/article/details/8102154
*/
int ALG_LCSS_string(string x, string y, string &result)
{
    int lenx = x.length();  //��ȡ�ִ��ĳ���
    int leny = y.length();

    int **c;                //����c��¼������ƥ�����
    ALG_Make2DArray(c, lenx, leny);

    int start, end, len, i, j; //start����������Ӵ�����ʼ�㣬end����������Ӵ�����ֹ��
    end = len = 0;          //len����������Ӵ��ĳ���
    for (i = 0; i < lenx; i++) //����ʼ��ǰ���Ƚ�
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

    // ��¼������Ӵ�
    start = end - len + 1;
    result = y.substr(start, len);

    return len;
}

/** ������Ӵ� LCS(Longest Common Substring)��Ԫ�ر������ڣ�ʱ�临�Ӷ�O(n*n)
*
*     @param[in] x ��1���ַ���
*     @param[in] y ��2���ַ���
*     @param[out] result ���������Ӵ�����Ҫ�������÷�����������ͷ��㹻��С���ڴ�
*     @return  ����������г���
*     @note  ��̬�滮
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

/** ��������� maximum subarray��Ҫ�ҳ�������ɵ�һά�����к��������������飬ʱ�临�Ӷ�O(n)
*
*     @param[in] arr ����������
*     @param[out] begin �����������ʼ����
*     @param[out] end ����������������
*     @return  ���������ĺͣ�ȫ�����򷵻�0
*     @note  ����{5,-3,4,2}����������о��� {5,-3,4,2}�����ĺ���8,�ﵽ��󣻶�{5,-6,4,2}�������������{4,2}�����ĺ���6
*     @note  http://www.cnblogs.com/zhangchaoyang/articles/2012070.html
*     @note  ���㷨���ۡ�4.1�������֮��������������ᡷ
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

/** ��������� maximum subarray��Ҫ�ҳ�������ɵ�һά�����к��������������飬ʱ�临�Ӷ�O(n)
*
*     @param[in] n ���������鳤��
*     @param[in] a ����������
*     @return  ���������ĺͣ�ȫ�����򷵻�0
*     @note  ����{5,-3,4,2}����������о��� {5,-3,4,2}�����ĺ���8,�ﵽ��󣻶�{5,-6,4,2}�������������{4,2}�����ĺ���6
*     @note  ��������������㷨����������P57
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

/** ����Ӿ���ʱ�临�Ӷ�O(m*m*n)
*
*     @param[in] m ��������
*     @param[in] n ��������
*     @param[in] a ���������󣬶�ά����
*     @return  ����Ӿ���ĺͣ�ȫ�����򷵻�0
*     @note  ��������������㷨����������P57�������֮����
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

/** �ַ����༭���룬�ַ������ƶ�
*
*     @param[string] x ԭʼ�ַ���
*     @param[string] y Ŀ���ַ���
*     @return  �ַ����༭����
*     @note  http://blog.csdn.net/orbit/article/details/6649322��
*     @note  �����֮����3.3
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
                dis[i][j] = dis[i - 1][j - 1]; //����Ҫ�༭����
            }
            else
            {
                int edIns = dis[i][j - 1] + 1;      //x �����ַ�
                int edDel = dis[i - 1][j] + 1;      //x ɾ���ַ�
                int edRep = dis[i - 1][j - 1] + 1;  //x �滻�ַ�

                dis[i][j] = min(min(edIns, edDel), edRep);
            }
        }
    }

    int ret = dis[lenx][leny];
    ALG_Delete2DArray(dis, lenx);

    return ret;
}

#endif