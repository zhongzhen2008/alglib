#ifndef ALG_MATH_H_
#define ALG_MATH_H_

#include <math.h>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

/**
*   �������� P(n,m) = n!/(n-m)!
*/
unsigned int ALG_PermutationCalc(unsigned int n, unsigned int m)
{
    unsigned int i, Ans;
    Ans = 1;
    for (i = 1; i <= m; i++)
    {
        Ans = Ans * n;
        n--;
    }
    return Ans;
}

/**
*   ������� C(n,m) = n!/m!/(n-m)!
*/
unsigned int ALG_CombinationCalc(unsigned int n, unsigned int m)
{
    unsigned int i, Ans;
    Ans = 1;
    for (i = 1; i <= m; i++)
    {
        Ans = Ans * n;
        n--;
    }
    for (i = 2; i <= m; i++)
    {
        Ans = Ans / i;
    }
    return Ans;
}

/**
*   ����n�����[1..n] ��ȫ���У��Լ��������
*/
unsigned int ALG_Permutation(unsigned int n)
{
    vector <unsigned int> vec1;
    unsigned int result = 0;
    for (unsigned int i = 1; i <= n; i++)
    {
        vec1.push_back(i);
    }

    bool hasNext = true;
    while (hasNext)
    {
        result++;
        for (unsigned int i = 0; i < n; i++)
        {
            cout << vec1[i] << " ";
        }
        cout << endl;

        hasNext = next_permutation(vec1.begin(), vec1.end());
    }

    return result;
}

/**
*   ��[1..n] ������ѡm ������ϣ��Լ��������
*/
unsigned int ALG_Combination(unsigned int n, unsigned int m)
{
    unsigned int result = 0;

    unsigned int *a = new unsigned int[n + 1];
    //unsigned int i, j;
    a[0] = 1;
    for (unsigned int i = 1; i <= m; i++)
    {
        a[i] = i;
    }
    while (a[0] == 1)
    {
        result++;
        for (unsigned int i = 1; i <= m; i++)
        {
            cout << a[i] << ' ';    //�����ǰ����
        }
        cout << '\n';

        unsigned int j = m;
        while (a[j] == n - m + j && j > 0)
        {
            j--;
        }
        a[j]++;
        for (unsigned int i = j + 1; i <= n; i++)
        {
            a[i] = a[i - 1] + 1;
        }
    }

    delete[] a;

    return result;
}

/** ���Լ��
*
*     @param x ��һ����
*     @param y �ڶ�����
*     @return ���Լ��
*/
int ALG_Gcd(int x, int y)
{
    while (y  >  0)
    {
        int t = x % y;
        x = y;
        y = t;
    }
    return  x;
}

/** ��С������
*
*     @param x ��һ����
*     @param y �ڶ�����
*     @return ��С������
*/
int ALG_Lcm(int x, int y)
{
    int gcd = ALG_Gcd(x, y);
    int lcm = x / gcd * y;
    return  lcm;
}

/** ��չŷ������㷨
*
*     @param[in] a,b
*     @param[in] x,y
*     @return gcd(a,b)
*     @note ���GCD(a,b) = d, �����x, y, ʹd = ax + by; extended_euclid(a, b) = ax + by
*     @note ��Ԫһ�β�������ax+by=c���н����Ҫ������(a,b)|c�����x0 y0 ��һ��⣬��ȫ���⣺
*     @note  x = x0 + b/(a,b) * t, y = y0 - a/(a,b) * t, (t����Z)
*/
int ALG_ExtendedEuclid(int a, int b, int &x, int &y)
{
    int d;
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    d = ALG_ExtendedEuclid(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

/** �����ж�
*
*     @param u ���жϵķǸ�����
*     @return �жϽ��
*/
bool  ALG_IsPrime(int u)
{
    if (u == 0 || u == 1)
    {
        return false;
    }
    if (u == 2)
    {
        return true;
    }
    if (u % 2 == 0)
    {
        return false ;
    }
    for (int i = 3;  i <= sqrt((double)u); i += 2)
    {
        if (u % i == 0)
        {
            return false;
        }
    }
    return  true;
}

/** ����ɸ��
*
*     @param u ���жϵķǸ�����
*     @return �жϽ��
*/
const int MAX_PRIME_SIEVE = 1000;
bool primeMark[MAX_PRIME_SIEVE];  // true: prime number
void ALG_SievePrime()
{
    memset(primeMark, true, sizeof(primeMark));
    primeMark[0] = primeMark[1] = false;
    for (int i = 2; i <= sqrt((double)MAX_PRIME_SIEVE); i++)
    {
        if (primeMark[i])
        {
            for (int j = i * i; j < MAX_PRIME_SIEVE; j += i)
            {
                primeMark[j] = false;
            }
        }
    }
}

/** ŷ������
*
*     @param n
*     @return 1..n-1����n�������ĸ���
*/
int ALG_Euler(int n)
{
    int ans = 1;
    for (int i = 2; i * i <= n ; i++)
    {
        if (n % i == 0)
        {
            n /= i;
            ans *= i - 1;
            while (n % i == 0)
            {
                n /= i;
                ans *= i;
            }
        }
    }
    if (n > 1)
    {
        ans *= n - 1;
    }
    return ans;
}

/** ������λ��ת��
*
*     @param[in] s[] �������ֵ��ַ�����ʽ
*     @param[in] r1 �������ֵĽ���
*     @param[out] ans[] ������ֵ��ַ�����ʽ
*     @param[out] r2 ������ֵĽ���
*     @return ��
*     @note ժ����������ACM/ICPC�㷨ѵ���̡̳�P117
*/
void ALG_ChangeRadix(char s[], char ans[], int r1, int r2)
{
    int res = 0;
    int len = strlen(s);
    for (int i = 0; i < len; i++)
    {
        res *= r1;
        res += (s[i] - '0');
    }

    int index = 0;
    while (res)
    {
        ans[index++] = res % r2 + '0';
        res /= r2;
    }
    ans[index] = '\0';

    len = strlen(ans);
    for (int i = 0; i < len / 2; i++)
    {
        swap(ans[i], ans[len - 1 - i]);
    }
}

#endif