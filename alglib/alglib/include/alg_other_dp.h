#ifndef ALG_OTHER_DP_H_
#define ALG_OTHER_DP_H_

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

const int INF_NEG = -10000;

/** ���㷨���ۡ�15.1 �����и�
*
*     @param a[] �����۸������Ч��Χ[1..n]
*     @param n ���鳤��
*     @return  ���и�����õ������������
*/
int ALG_ExtendedBottomUpCutRob(int p[], int n)
{
    int *r = new int[n + 1];        // �������
    int *s = new int[n + 1];        // �и��

    r[0] = 0;

    for (int j = 1; j <= n; j++)
    {
        int q = INF_NEG;
        for (int i = 1; i <= j; i++)
        {
            if (q < p[i] + r[j - i])
            {
                q = p[i] + r[j - i];
                s[j] = i;
            }
            r[j] = q;
        }
    }

    int maxr = r[n];

    cout << endl << "���㷨���ۡ�15.1 �����и�" << endl;
    while (n > 0)
    {
        cout << s[n] << " ";
        n -= s[n];
    }
    cout << endl;

    delete[] r;
    delete[] s;

    return maxr;
}

/** ���㷨���ۡ�15.2 �������˷��� ������ 3.1 ��������
*
*     @param p[] ����ά����[0,1,..,n]��Ai��ά����(Pi-1*Pi)
*     @param n �������
*     @return  ��С�˷�����
*/
int ALG_MatrixChain(int *p, int n, int **m, int **s)
{
    for (int i = 1; i <=n; i++)
    {
        m[i][i] = 0;
    }

    for (int r = 2; r <= n; r++)
    {
        for (int i = 1; i <= n - r + 1; i++)
        {
            int j = i + r - 1;
            m[i][j] = m[i + 1][j] + p[i - 1] * p[i] * p[j];
            s[i][j] = i;
            for (int k = i + 1; k < j; k++)
            {
                int t = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (t < m[i][j])
                {
                    m[i][j] = t;
                    s[i][j] = k;
                }
            }
        }
    }

    return m[1][n];
}

void ALG_MatrixTraceback(int i, int j, int **s)
{
    if (i == j)
    {
        cout << "A" << i;
    }
    else
    {
        cout << "(";
        ALG_MatrixTraceback(i, s[i][j], s);
        ALG_MatrixTraceback(s[i][j] + 1, j, s);
        cout << ")";
    }
}

// ---------- Weighted Interval Scheduling����Algorithm Design��Kleinberg 6.1
typedef struct  
{
    int id;
    int start;
    int finish;
    int weight;
} STU_INTERVAL;

bool wisComp(STU_INTERVAL a, STU_INTERVAL b) 
{
    return a.finish < b.finish;
}

int wisCalcP(vector<STU_INTERVAL> intervals, int index)
{
    if (index <= 1)
    {
        return 0;
    }

    for (int i = index - 2; i >= 0; i--)
    {
        if (intervals[i].finish <= intervals[index - 1].start)
        {
            return i + 1;   // �ҵ�
        }
    }

    return 0;   // δ�ҵ�
}

/** Weighted Interval Scheduling����Algorithm Design��Kleinberg 6.1
*
*     @param intervals ������ʱ���
*     @param results ���Ž�ʱ��ε�id����
*     @return  ����ֵ
*/
int ALG_WIS(vector<STU_INTERVAL> intervals, vector<int> &results)
{
    // �Խ���ʱ����������
    sort(intervals.begin(), intervals.end(), wisComp);

    // ����ÿһ��p(i)
    vector<int> p;
    p.push_back(0);
    int len = intervals.size();
    for (int i = 1; i <= len; i++)
    {
        int pTmp = wisCalcP(intervals, i);
        p.push_back(pTmp);
    }

    // ��̬�滮��ֵ
    int *opt = new int[len + 1]();
    memset(opt, 0, len + 1);
    int *path = new int[len + 1]();
    memset(path, 0, len + 1);

    for (int i = 1; i <= len; i++)
    {
        int v1 = intervals[i - 1].weight + opt[p[i]];
        int v2 = opt[i - 1];
        //opt[i] = max(v1, v2);
        if (v1 > v2)
        {
            opt[i] = v1;
            path[i] = 1;
        }
        else if (v1 < v2)
        {
            opt[i] = v2;
            path[i] = 2;
        }
        else
        {
            opt[i] = v1;
            path[i] = 3;            
        }
    }
    int retWis = opt[len];

    // �������Ž�
    int trace = len;
    while (trace > 0)
    {
        //int v1 = intervals[trace - 1].weight + opt[p[trace]];
        //int v2 = opt[trace - 1];
        if (path[trace] == 1)
        {
            results.insert(results.begin(), intervals[trace - 1].id);
            trace = p[trace];
        }
        else
        {
            trace--;
        }
    }

    delete[] opt;
    delete[] path;
    return retWis;
}

int ALG_WIS_TraceAll(vector<STU_INTERVAL> intervals, vector<int> p, int path[], int t, vector<vector<int>> &resultAll, vector<int> &resultOne)
{
    if (t == 0)
    {
        vector<int> vecOne;
        int resultLen = resultOne.size();
        for (int i = 0; i < resultLen; i++)
        {
            if (resultOne[i] != 0)
            {
                vecOne.push_back(intervals[i - 1].id);
            }
        }
        if (vecOne.size() > 0)
        {
            resultAll.push_back(vecOne);
        }
    } 
    else
    {
        if (path[t] == 1)
        {
            int tmp = resultOne[t];
            resultOne[t] = 1;
            ALG_WIS_TraceAll(intervals, p, path, p[t], resultAll, resultOne);
            resultOne[t] = tmp;
        } 
        else if (path[t] == 2)
        {
            int tmp = resultOne[t];
            resultOne[t] = 0;
            ALG_WIS_TraceAll(intervals, p, path, t - 1, resultAll, resultOne);
            resultOne[t] = tmp;
        }
        else if (path[t] == 3)
        {
            int tmp = resultOne[t];
            resultOne[t] = 1;
            ALG_WIS_TraceAll(intervals, p, path, p[t], resultAll, resultOne);
            resultOne[t] = tmp;

            tmp = resultOne[t];
            resultOne[t] = 0;
            ALG_WIS_TraceAll(intervals, p, path, t - 1, resultAll, resultOne);
            resultOne[t] = tmp;
        }
    }    

    return 0;
}

bool wisCompResultAll(vector<int> a, vector<int> b) 
{
    return a[0] < b[0];
}

/** Weighted Interval Scheduling����Algorithm Design��Kleinberg 6.1
*
*     @param intervals ������ʱ���
*     @param resultAll ȫ�����Ž�
*     @return  ����ֵ
*/
int ALG_WIS_All(vector<STU_INTERVAL> intervals, vector<vector<int>> &resultAll)
{
    // �Խ���ʱ����������
    sort(intervals.begin(), intervals.end(), wisComp);

    // ����ÿһ��p(i)
    vector<int> p;
    p.push_back(0);
    int len = intervals.size();
    for (int i = 1; i <= len; i++)
    {
        int pTmp = wisCalcP(intervals, i);
        p.push_back(pTmp);
    }

    // ��̬�滮��ֵ
    int *opt = new int[len + 1]();
    memset(opt, 0, len + 1);
    int *path = new int[len + 1]();
    memset(path, 0, len + 1);

    for (int i = 1; i <= len; i++)
    {
        int v1 = intervals[i - 1].weight + opt[p[i]];
        int v2 = opt[i - 1];
        //opt[i] = max(v1, v2);
        if (v1 > v2)
        {
            opt[i] = v1;
            path[i] = 1;
        }
        else if (v1 < v2)
        {
            opt[i] = v2;
            path[i] = 2;
        }
        else
        {
            opt[i] = v1;
            path[i] = 3;            
        }
    }
    int retWis = opt[len];

    // �������Ž�
    vector<int> resultOne(len + 1);
    ALG_WIS_TraceAll(intervals, p, path, len, resultAll, resultOne);
    sort(resultAll.begin(), resultAll.end(), wisCompResultAll);

    delete[] opt;
    delete[] path;
    return retWis;
}


// ---------- Weighted Interval Scheduling����Algorithm Design��Kleinberg 6.1



#endif