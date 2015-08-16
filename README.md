# alglib
algorithm lib by c/c++

�����㷨������OJ �п���ʹ�ã���������ϡ����к������Զ���ʹ�ã�
�ṩGoogle Test ���������������������ʹ�ã�

alg_string.h
	ALG_StringSplit 		�ַ����ָ��
	ALG_StringTrim 			�ַ���Trim
	ALG_StringTrimLeft	�ַ���Trim
	ALG_StringTrimRight	�ַ���Trim
alg_util.h
	ALG_Make2DArray			��̬������ά����
	ALG_Print2DArray		��ӡ��ά����
	ALG_Delete2DArray		�ͷ�֮ǰ��̬�����Ķ�ά����
alg_sequence.h
	ALG_LCS_vector			����������� LCS(Longest Common Subsequence)��Ԫ���������ڣ�ʱ�临�Ӷ�O(m*n)
	ALG_LCS_string			����������� LCS(Longest Common Subsequence)��Ԫ����������
	ALG_LNDS_vector			��Ǽ������У�Ԫ���������ڣ�ʱ�临�Ӷ�O(n*n)
	ALG_LIS_vector			����������У�Longest Increase Subsequence��Ԫ���������ڣ�ʱ�临�Ӷ�O(n*n)
	ALG_LCSS_string			������Ӵ� LCS(Longest Common Substring)��Ԫ�ر������ڣ�ʱ�临�Ӷ�O(n*n)
	ALG_LCSS_cstr				������Ӵ� LCS(Longest Common Substring)��Ԫ�ر������ڣ�ʱ�临�Ӷ�O(n*n)
	ALG_MaxSub_vector		��������� maximum subarray��Ҫ�ҳ�������ɵ�һά�����к��������������飬ʱ�临�Ӷ�O(n)
	ALG_MaxSub_array		��������� maximum subarray��Ҫ�ҳ�������ɵ�һά�����к��������������飬ʱ�临�Ӷ�O(n)
	ALG_MaxSubMatrix_array	����Ӿ���ʱ�临�Ӷ�O(m*m*n)
	ALG_EditDistance		�ַ����༭���룬�ַ������ƶ�
alg_search.h
	ALG_BinarySearch		����ָ��Ԫ���������е�λ�ã����ַ������㷨��ʱ�临�Ӷ� O(logN)
alg_math.h
	ALG_PermutationCalc	�������� P(n,m) = n!/(n-m)!
	ALG_CombinationCalc	������� C(n,m) = n!/m!/(n-m)!
	ALG_Permutation			����n�����[1..n] ��ȫ���У��Լ��������
	ALG_Combination			��[1..n] ������ѡm ������ϣ��Լ��������
	ALG_Gcd	���Լ��
	ALG_Lcm	��С������
	ALG_ExtendedEuclid	��չŷ������㷨
	ALG_IsPrime	�����ж�
	ALG_SievePrime	����ɸ��
	ALG_Euler	ŷ������
	ALG_ChangeRadix	������λ��ת��
alg_knapsack.h
	ALG_Knapsack_01	0-1��������
alg_graph_bipartite.h
	ALG_BipartiteMatch	����ͼ�����ƥ�䡪�������㷨
alg_other_dp.h
	ALG_ExtendedBottomUpCutRob	���㷨���ۡ�15.1 �����и�
	ALG_MatrixChain	���㷨���ۡ�15.2 �������˷��� ������ 3.1 ��������
	ALG_WIS	Weighted Interval Scheduling����Algorithm Design��Kleinberg 6.1
	ALG_WIS_All	Weighted Interval Scheduling����Algorithm Design��Kleinberg 6.1
