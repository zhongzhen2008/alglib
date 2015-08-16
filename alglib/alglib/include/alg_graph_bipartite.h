#ifndef ALG_GRAPH_BIPARTITE_H_
#define ALG_GRAPH_BIPARTITE_H_

#include <memory.h>

const int N = 201;

//n1,n2为二分图的顶点集,其中x∈n1,y∈n2
int n1, n2;

//link记录n2中的点y在n1中所匹配的x点的编号
int map[N][N], vis[N], link[N];

int ALG_FindBipartite(int x)
{
    int i;
    for (i = 1; i <= n2; i++)
    {
        if (map[x][i] && !vis[i]) //x->i有边,且节点i未被搜索
        {
            vis[i] = 1; //标记节点已被搜索
            //如果i不属于前一个匹配M或被i匹配到的节点可以寻找到增广路
            if (link[i] == 0 || ALG_FindBipartite(link[i]))
            {
                link[i] = x; //更新
                return 1;//匹配成功
            }
        }
    }
    return 0;
}

void ALG_InitBipartite()
{
    memset(map, 0, sizeof(map));
    memset(vis, 0, sizeof(vis));
    memset(link, 0, sizeof(link));
}

/** 二分图最大匹配
*
*     @note 二分图的最大匹配—匈牙利算法，http://www.cnblogs.com/pony1993/archive/2012/07/25/2607738.html
*/
int ALG_BipartiteMatch()
{
    int sum = 0;
    for (int i = 1; i <= n1; i++)
    {
        memset(vis, 0, sizeof(vis));
        if (ALG_FindBipartite(i))
        {
            sum++;
        }
    }
    return sum;
}

#endif