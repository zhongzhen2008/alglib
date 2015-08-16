#ifndef ALG_SEARCH_H_
#define ALG_SEARCH_H_

/** ����ָ��Ԫ���������е�λ�ã����ַ������㷨��ʱ�临�Ӷ� O(logN)
*
*     @param a[] Ŀ�����飬�Ѵ�С���������
*     @param x �����ҵ�Ԫ��
*     @param left �����±���߽磨��0��ʼ��
*     @param right �����±��ұ߽磨����������
*     @return    Ԫ��x������a�е��±꣨��0��ʼ�������û���ѵ��򷵻�-1
*/
template <class Type>
int ALG_BinarySearch(Type a[], Type x, int left, int right)
{
    int mid;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (x == a[mid]) 
        { 
            return mid; 
        }
        else
        {
            if (x < a[mid]) 
            { 
                right = mid - 1; 
            }
            if (x > a[mid]) 
            { 
                left = mid + 1; 
            }
        }
    }
    return -1;
}

#endif