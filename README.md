# alglib
algorithm lib by c/c++

各种算法竞赛、OJ 中可以使用，函数松耦合、所有函数可以独立使用；
提供Google Test 用例，便于理解各函数如何使用；

alg_string.h
	ALG_StringSplit 		字符串分割函数
	ALG_StringTrim 			字符串Trim
	ALG_StringTrimLeft	字符串Trim
	ALG_StringTrimRight	字符串Trim
alg_util.h
	ALG_Make2DArray			动态创建二维数组
	ALG_Print2DArray		打印二维数组
	ALG_Delete2DArray		释放之前动态创建的二维数组
alg_sequence.h
	ALG_LCS_vector			最长公共子序列 LCS(Longest Common Subsequence)，元素无需相邻，时间复杂度O(m*n)
	ALG_LCS_string			最长公共子序列 LCS(Longest Common Subsequence)，元素无需相邻
	ALG_LNDS_vector			最长非减子序列，元素无需相邻，时间复杂度O(n*n)
	ALG_LIS_vector			最长递增子序列，Longest Increase Subsequence，元素无需相邻，时间复杂度O(n*n)
	ALG_LCSS_string			最长公共子串 LCS(Longest Common Substring)，元素必须相邻，时间复杂度O(n*n)
	ALG_LCSS_cstr				最长公共子串 LCS(Longest Common Substring)，元素必须相邻，时间复杂度O(n*n)
	ALG_MaxSub_vector		最大子数组 maximum subarray，要找出由数组成的一维数组中和最大的连续子数组，时间复杂度O(n)
	ALG_MaxSub_array		最大子数组 maximum subarray，要找出由数组成的一维数组中和最大的连续子数组，时间复杂度O(n)
	ALG_MaxSubMatrix_array	最大子矩阵，时间复杂度O(m*m*n)
	ALG_EditDistance		字符串编辑距离，字符串相似度
alg_search.h
	ALG_BinarySearch		查找指定元素在数组中的位置，二分法查找算法，时间复杂度 O(logN)
alg_math.h
	ALG_PermutationCalc	求排列数 P(n,m) = n!/(n-m)!
	ALG_CombinationCalc	求组合数 C(n,m) = n!/m!/(n-m)!
	ALG_Permutation			输入n，输出[1..n] 的全排列，以及输出总数
	ALG_Combination			从[1..n] 个数中选m 个的组合，以及输出总数
	ALG_Gcd	最大公约数
	ALG_Lcm	最小公倍数
	ALG_ExtendedEuclid	扩展欧几里德算法
	ALG_IsPrime	素数判断
	ALG_SievePrime	素数筛法
	ALG_Euler	欧拉函数
	ALG_ChangeRadix	整数进位制转换
alg_knapsack.h
	ALG_Knapsack_01	0-1背包问题
alg_graph_bipartite.h
	ALG_BipartiteMatch	二分图的最大匹配—匈牙利算法
alg_other_dp.h
	ALG_ExtendedBottomUpCutRob	《算法导论》15.1 钢条切割
	ALG_MatrixChain	《算法导论》15.2 矩阵链乘法； 王晓东 3.1 矩阵连乘
	ALG_WIS	Weighted Interval Scheduling，《Algorithm Design》Kleinberg 6.1
	ALG_WIS_All	Weighted Interval Scheduling，《Algorithm Design》Kleinberg 6.1
