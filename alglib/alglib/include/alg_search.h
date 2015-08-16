#ifndef ALG_SEARCH_H_
#define ALG_SEARCH_H_

/** 查找指定元素在数组中的位置，二分法查找算法，时间复杂度 O(logN)
*
*     @param a[] 目标数组，已从小到大排序好
*     @param x 待查找的元素
*     @param left 数组下标左边界（从0开始）
*     @param right 数组下标右边界（包含此数）
*     @return    元素x在数组a中的下标（从0开始），如果没有搜到则返回-1
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