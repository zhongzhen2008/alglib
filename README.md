# alglib
algorithm lib by c/c++<br />
<br />
各种算法竞赛、OJ 中可以使用，函数松耦合、所有函数可以独立使用、也可以全部拿去include使用；<br />

<p>
	提供Google Test &nbsp;测试用例，便于理解各函数如何使用；
</p>
核心代码目录在：\alglib\alglib\include<br />
<br />
alg_string.h<br />
<span style="white-space:pre">	</span>ALG_StringSplit <span style="white-space:pre">			</span>字符串分割函数<br />
<span style="white-space:pre">	</span>ALG_StringTrim <span style="white-space:pre">			</span>字符串Trim<br />
<span style="white-space:pre">	</span>ALG_StringTrimLeft<span style="white-space:pre">		</span>字符串Trim<br />

<p>
	<span style="white-space:pre">	</span>ALG_StringTrimRight<span style="white-space:pre">		</span>字符串Trim
</p>
<p>
	<br />
	
</p>
alg_util.h<br />
<span style="white-space:pre">	</span>ALG_Make2DArray<span style="white-space:pre">		</span>动态创建二维数组<br />
<span style="white-space:pre">	</span>ALG_Print2DArray<span style="white-space:pre">		</span>打印二维数组<br />

<p>
	<span style="white-space:pre">	</span>ALG_Delete2DArray<span style="white-space:pre">		</span>释放之前动态创建的二维数组
</p>
<p>
	<br />
	
</p>
alg_sequence.h<br />
<span style="white-space:pre">	</span>ALG_LCS_vector<span style="white-space:pre">			</span>最长公共子序列 LCS(Longest Common Subsequence)，元素无需相邻，时间复杂度O(m*n)<br />
<span style="white-space:pre">	</span>ALG_LCS_string<span style="white-space:pre">			</span>最长公共子序列 LCS(Longest Common Subsequence)，元素无需相邻<br />
<span style="white-space:pre">	</span>ALG_LNDS_vector<span style="white-space:pre">		</span>最长非减子序列，元素无需相邻，时间复杂度O(n*n)<br />
<span style="white-space:pre">	</span>ALG_LIS_vector<span style="white-space:pre">			</span>最长递增子序列，Longest Increase Subsequence，元素无需相邻，时间复杂度O(n*n)<br />
<span style="white-space:pre">	</span>ALG_LCSS_string<span style="white-space:pre">		</span>最长公共子串 LCS(Longest Common Substring)，元素必须相邻，时间复杂度O(n*n)<br />
<span style="white-space:pre">	</span>ALG_LCSS_cstr<span style="white-space:pre">			</span>最长公共子串 LCS(Longest Common Substring)，元素必须相邻，时间复杂度O(n*n)<br />
<span style="white-space:pre">	</span>ALG_MaxSub_vector<span style="white-space:pre">		</span>最大子数组 maximum subarray，要找出由数组成的一维数组中和最大的连续子数组，时间复杂度O(n)<br />
<span style="white-space:pre">	</span>ALG_MaxSub_array<span style="white-space:pre">		</span>最大子数组 maximum subarray，要找出由数组成的一维数组中和最大的连续子数组，时间复杂度O(n)<br />
<span style="white-space:pre">	</span>ALG_MaxSubMatrix_array<span style="white-space:pre">	</span>最大子矩阵，时间复杂度O(m*m*n)<br />

<p>
	<span style="white-space:pre">	</span>ALG_EditDistance<span style="white-space:pre">		</span>字符串编辑距离，字符串相似度
</p>
<p>
	<br />
	
</p>
alg_search.h<br />

<p>
	<span style="white-space:pre">	</span>ALG_BinarySearch<span style="white-space:pre">		</span>查找指定元素在数组中的位置，二分法查找算法，时间复杂度 O(logN)
</p>
<p>
	<br />
	
</p>
alg_math.h<br />
<span style="white-space:pre">	</span>ALG_PermutationCalc<span style="white-space:pre">	</span>求排列数 P(n,m) = n!/(n-m)!<br />
<span style="white-space:pre">	</span>ALG_CombinationCalc<span style="white-space:pre">	</span>求组合数 C(n,m) = n!/m!/(n-m)!<br />
<span style="white-space:pre">	</span>ALG_Permutation<span style="white-space:pre">		</span>输入n，输出[1..n] 的全排列，以及输出总数<br />
<span style="white-space:pre">	</span>ALG_Combination<span style="white-space:pre">		</span>从[1..n] 个数中选m 个的组合，以及输出总数<br />
<span style="white-space:pre">	</span>ALG_Gcd<span style="white-space:pre">				</span>最大公约数<br />
<span style="white-space:pre">	</span>ALG_Lcm<span style="white-space:pre">				</span>最小公倍数<br />
<span style="white-space:pre">	</span>ALG_ExtendedEuclid<span style="white-space:pre">		</span>扩展欧几里德算法<br />
<span style="white-space:pre">	</span>ALG_IsPrime<span style="white-space:pre">			</span>素数判断<br />
<span style="white-space:pre">	</span>ALG_SievePrime<span style="white-space:pre">			</span>素数筛法<br />
<span style="white-space:pre">	</span>ALG_Euler<span style="white-space:pre">				</span>欧拉函数<br />

<p>
	<span style="white-space:pre">	</span>ALG_ChangeRadix<span style="white-space:pre">		</span>整数进位制转换
</p>
<p>
	<br />
	
</p>
alg_knapsack.h<br />

<p>
	<span style="white-space:pre">	</span>ALG_Knapsack_01<span style="white-space:pre">		</span>0-1背包问题
</p>
<p>
	<br />
	
</p>
alg_graph_bipartite.h<br />

<p>
	<span style="white-space:pre">	</span>ALG_BipartiteMatch<span style="white-space:pre">		</span>二分图的最大匹配—匈牙利算法
</p>
<p>
	<br />
	
</p>
alg_other_dp.h<br />
<span style="white-space:pre">	</span>ALG_ExtendedBottomUpCutRob<span style="white-space:pre">	</span>《算法导论》15.1 钢条切割<br />
<span style="white-space:pre">	</span>ALG_MatrixChain<span style="white-space:pre">				</span>《算法导论》15.2 矩阵链乘法； 王晓东 3.1 矩阵连乘<br />
<span style="white-space:pre">	</span>ALG_WIS<span style="white-space:pre">				</span>Weighted Interval Scheduling，《Algorithm Design》Kleinberg 6.1<br />
<span style="white-space:pre">	</span>ALG_WIS_All<span style="white-space:pre">			</span>Weighted Interval Scheduling，《Algorithm Design》Kleinberg 6.1
