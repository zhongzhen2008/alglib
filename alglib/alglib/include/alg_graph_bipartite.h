#ifndef ALG_GRAPH_BIPARTITE_H_
#define ALG_GRAPH_BIPARTITE_H_

#include <memory.h>

const int N = 201;

//n1,n2Ϊ����ͼ�Ķ��㼯,����x��n1,y��n2
int n1, n2;

//link��¼n2�еĵ�y��n1����ƥ���x��ı��
int map[N][N], vis[N], link[N];

int ALG_FindBipartite(int x)
{
    int i;
    for (i = 1; i <= n2; i++)
    {
        if (map[x][i] && !vis[i]) //x->i�б�,�ҽڵ�iδ������
        {
            vis[i] = 1; //��ǽڵ��ѱ�����
            //���i������ǰһ��ƥ��M��iƥ�䵽�Ľڵ����Ѱ�ҵ�����·
            if (link[i] == 0 || ALG_FindBipartite(link[i]))
            {
                link[i] = x; //����
                return 1;//ƥ��ɹ�
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

/** ����ͼ���ƥ��
*
*     @note ����ͼ�����ƥ�䡪�������㷨��http://www.cnblogs.com/pony1993/archive/2012/07/25/2607738.html
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