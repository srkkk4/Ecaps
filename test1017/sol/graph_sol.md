注意到 $a_u + b_v < 2m$，那么实际上边的情况只有这两种：

1. $a_u + b_v < m$ 时，边权为 $a_u + b_v$。
2. $a_u + b_v \ge m$ 时，边权为 $a_u + b_v - m$。

可以发现我们将 $b$ 排序后对于固定的 $u$，两种连边对应前缀和后缀。

一种想法时第一种情况 $b$ 连出去的边是 $a_u$，第二种时 $a_u - m$，但是有负权边，用 SPFA 会 TLE。

考虑能不能把图中的边全部改为正权。

这时我们不把 $b$ 连出去的边赋权了，而是前后缀优化时建的虚点之间连边赋权，这样连的边权就是相邻 $b$ 的差了，可以发现这样图里只有正权边了，直接跑 Dijkstra 即可。

时间复杂度 $O(n \log n)$。 
