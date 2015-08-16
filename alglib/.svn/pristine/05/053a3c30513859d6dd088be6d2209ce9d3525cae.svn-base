#include "../include/alg_graph_bipartite.h"

#include <gtest/gtest.h>

TEST(GraphTest, GraphBipartite_01)
{
    n1 = n2 = 5;

    ALG_InitBipartite();
    map[1][2] = map[1][5] = 1;
    map[2][2] = map[2][3] = map[2][4] = 1;
    map[3][1] = map[3][5] = 1;
    map[4][1] = map[4][2] = map[4][5] = 1;
    map[5][2] = 1;

    int ret = ALG_BipartiteMatch();
    EXPECT_EQ(4, ret);
}