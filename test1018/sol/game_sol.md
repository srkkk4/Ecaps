由于每个棋子是独立的，我们考虑每个棋子的 sg。我们定义格子 $i$ 上一颗颜色 $j$ 的棋子的 sg 值为 $s_{i,j}$

对于棋盘上的任意一个格子 $i$，我们可以证明，一定能找到一个颜色集合 $S$ 和一个整数 $x$，使得 $x<i-1,\forall p\in S,\{s_{j,p}|j<i\}=\{a|0\le a<i,a\neq x\}\forall p\notin S,\{s_{j,p}|j<i\}=\{0,1,\dots,i-2\}$。我们会在计算过程中证明这个这个结论。

现在我们考虑第 $i$ 个格子，它的颜色是 $c_i$，满足上面结论的 $S,x$ 分别为 $S_i,x_i$，分类讨论：
+ 若 $c_i\in S_i$：
+ + $s_{i,c_i}=\operatorname{mex}\{0,\dots,x-1,x+1,\dots,i-1\}=x$；
+ + $\forall j\in S_i\And j\neq c_i,s_{i,j}=\operatorname{mex}\{0,\dots,x-1,s_{i,c_i},x+1,\dots,i-1\}=i$；
+ + $\forall j\notin S_i,s_{i,j}=\operatorname{mex}\{0,\dots,i-2,s_{i,c_i}\}=i-1$；
+ $S_{i+1}=\{a|a\in S_i,a\neq c_i\},x_{i+1}=x_i$;
+ 若 $c_i\notin S_i$：
+ + $s_{i,c_i}=\operatorname{mex}\{0,\dots,i-2\}=i-1$；
+ + $\forall j\in S_i,s_{i,j}=\operatorname{mex}\{0,\dots,x-1,x+1,\dots,i-1,s_{i,c_i}\}=x$；
+ + $\forall j\notin S_i\And j\neq c_i,s_{i,j}=\operatorname{mex}\{0,\dots,i-2,s_{i,c_i}\}=i$；
+ $S_{i+1}=\{a|a\notin S_i,a\neq c_i\},x_{i+1}=i-1$。

初始状态 $S=\emptyset$，此结论得证，时空复杂度 $\Theta(n)$。