This repository records the prepare for the interview

The first algorithm is dijkstra algorithm
Below are the detailed steps used in Dijkstra's algorithm to find the shortest path from a
single source vertex to all other vertices in the given graph.
1) Create a set say named sptSet(shortest path tree set) that keeps track of vertices included in shortest path tree.
i.e., whose minimum distance from source is calculated and finalized. Initially, this set is empty.
2). Assgin a distance value to all vertices in the input graph. Initialize all distance values as INFINITE.
Assign the distance value as 0 for the source vertex so that it is picked first.
3). While sptSet doesn't include all vertices.
    a). Pick a vertex u which is not there in sptSet and has minimum distance value.
    b). include u to sptSet.
    c). Update distance value of all adjacent vertices of u. To update the distance values, iterate through all adjacent
    vertices. For every adjacent vertex v, if sum of distance value of u(from source) and weight of edge u-v, is less than
    the distance value of v, then update the distance value of v.

详细步骤：
1）. 创建一个集合，起名sptSet（最短路径集合），顾名思义，这个集合记录包含在最短路径树种的点。例如挡着点被记录在这个集合中，
就说明，这个点的最短路径已经计算好，确定下来了。刚开始的时候，这个集合是空的。
2）. 创建一个图的所有点离原始点的距离值数组，这个数组内每个值初始化为最大值。然后设置原始点的距离值 为 0.
3) . sptSet 逐步累加
    a）. 选取一个点u,这个点u不在SPTSet集合中，这个点U距离原始点距离不为0
    b) . 把U加入到SPTSet集合中
    C) . 更新所有与U相邻的点的距离值。首先要先遍历所有相邻点，对于每一个相邻点V，如果权重值V的距离值大于权重值U+U-V边的权重，那么更新V的距离值。

