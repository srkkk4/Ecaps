## tp

时间限制：2s

空间限制：512MB

### 题目背景

你说得对，但是电脑玩家欧文是一款由杭州哈哈游开发的恐龙模拟器，你需要在与论语十二章的对决中逐步发掘欧文的家庭组之力，并且需要时刻警惕身后阴暗千里眼的窥视。在如此的条件下，欧文需要仁济之力来进化，成为至高无上的叮当兄弟，所以你需要帮助他扭曲的跨过成神之路的阻碍，避免误伤，夺取可乐，击败奶龙，在咪咪世界中体会化身懂王，将高尔夫球打出天际的快乐。同时，逐步发掘 b12345678910t 的真相。

### 题目描述

给定长度为 $n$ 的序列 $a$，以及 $m$ 个数对 $(l_i,r_i)$。  
欧文需要你进行下列操作至多一次：

- 选择序列 $a$ 的一个子段，并将其中的每个元素的值都改成任意整数。    

你需要保证执行完操作之后，对于每个整数 $i(1\leq i\leq m)$，都有 $a[l_i,r_i]$ 中所有元素互不相同。  
你需要最小化操作时选择的子段的长度，并求出这个长度的最小值。  
如果没有必要进行操作，答案为 $0$。

**本题输入输出量较大，请使用合理的I/O优化。**

### 输入格式

第一行输入一个整数 $t$ 表示数据组数，接下来对于每组数据：  
第一行输入一个整数 $n$ 表示序列长度。  
接下来一行输入 $n$ 个整数表示 $a_1,a_2,\cdots,a_n$。
接下来一行输入一个整数 $m$ 表示给定的数对数。  
接下来输入 $m$ 行，其中第 $i$ 行输入两个整数表示 $l_i,r_i(1\leq l_i\leq r_i\leq n)$。

### 输出格式

对于每组数据：  
输出进行操作的子段的长度的最小值。

### 样例解释

对于第一组数据，我们可以选择子段 $[1,2]$ 并将序列改成 $[114,514,2,1,3,3,5]$，此时：

- 对于第一个数对 $(1,4)$，我们有 $a[1,4]=[114,514,2,1]$。
- 对于第二个数对 $(4,5)$，我们有 $a[4,5]=[1,3]$。  
- 对于第三个数对 $(2,4)$，我们有 $a[2,4]=[514,2,1]$。

显然每个数对都满足要求，且我们可以证明没有更优的答案，因此答案为 $2$。  
对于第二组数据，我们没有必要进行操作。  
对于第三组数据，我们可以选择子段 $[1,1]$ 并将序列改成 $[1,7,5,6]$。

### 输入 #1

```
5
7 3
1 1 2 1 3 3 5
1 4
4 5
2 4
5 2
10 1 6 14 1
4 5
2 4
4 5
5 7 5 6
2 2
1 3
2 4
3 3
3 4
7 3
2 2 2 7 8 2 2
4 4
4 4
5 5
1 1
123
1 1
```

### 输出 #1

```
2
0
1
0
0
```

对于 $10\%$ 的数据：$n, m \le 100$

对于 $30\%$ 的数据：$n, m \le 500$

对于另外 $10\%$ 的数据，$m = 1$

对于另外 $20\%$ 的数据，$t = 1$

对于所有数据，$1\leq t\leq 10, 1\leq n,m \le2\times10^5, 1\leq a_i\leq10^9$

# 游戏 (`game`)  6s 256MiB

### 题目描述

GoldenFishX 和 SilverFishY 玩游戏。

游戏中有一个 $1\times N$ 的棋盘，棋盘上有若干颗棋子，每轮两位玩家依次操作，每次操作可以把棋盘上某个棋子向左移动正整数格，不能操作者输。

然而当他们开始游戏前，调皮的 CopperFishZ 把棋盘和棋子涂上了各种各样的颜色。GoldenFishX 看到这五彩斑斓的棋盘和棋子，灵机一动，将游戏规则改为：

游戏中有一个 $1\times N$ 的棋盘，棋盘上有若干颗棋子，棋盘上每个格子均有颜色，每个棋子均有颜色，每轮两位玩家依次操作，不能操作者输，每次操作可以：

1. 选择棋盘上任意一个棋子，将其向左移动正整数格；
2. 选择棋盘上任意一个棋子颜色和其所在格子颜色**不同**的棋子，将其颜色改为其所在格子颜色。

SilverFishY 想知道，对于某个局面，先手是否有必胜策略。

为了防止你扔硬币蒙混过关，SilverFishY 会从一个没有棋子的局面开始，每次往棋盘中加入一个棋子，而你需要在他加入棋子后回答当前局面先手是否有必胜策略。

### 输入格式

第一行三个正整数 $N,M,Q$，分别表示棋盘大小、颜色数量、操作次数。

第二行 $N$ 个正整数 $col_i$，表示棋盘上每个格子的颜色。

接下来 $Q$ 行，每行两个正整数 $x,y$，表示 SilverFishY 往棋盘上第 $x$ 个格子上放入一个初始颜色为 $y$ 的棋子。

### 输出格式

一行一个长度为 $Q$ 的 01 串 $ans$，当第 $i$ 次操作后先手有必胜策略则 $ans_i=1$，否则 $ans_i=0$。

### 样例输入 1

```
3 3 3
1 3 3
1 3
3 2
2 3
```

### 样例输出 1

```
111
```

### 样例解释 1

下文中我们用 $(x,y)$ 表示一颗在第 $x$ 个格子，颜色为 $y$ 的棋子。

第一次询问，棋盘上只有 $(1,3)$ 一颗棋子，先手将其操作成 $(1,1)$ 后后手无法操作。

第二次询问，棋盘上存在 $(1,3),(3,2)$ 两颗棋子，先手将 $(1,3)$ 操作成 $(1,1)$ 后，后手必败。

第三次询问，棋盘上存在 $(1,3),(3,2),(2,3)$ 三颗棋子，由于 $(2,3)$ 会且仅会在两次操作后变为 $(1,1)$，所以此状态与第二次询问的状态完全相同，先手必胜。

### 样例 2

见选手目录下 `game2.in / game2.ans`。

该样例满足 $n,m,q\le 10$。

### 样例 3

见选手目录下 `game3.in / game3.ans`。

该样例满足 $m=1$。

### 样例 4

见选手目录下 `game4.in / game4.ans`。

该样例满足 $m=2$。

### 样例 5

见选手目录下 `game5.in / game5.ans`。

该样例随机生成，满足 $q\le 10^3$。

### 样例 6

见选手目录下 `game6.in / game6.ans`。

该样例满足 $n,m,q\le 5\times 10^3$。

### 样例 7

见选手目录下 `game7.in / game7.ans`。

该样例满足 $n,m,q\le 5\times 10^5$。

### 数据范围

对于测试点 $1$，$n,m,q\le 3$。

对于测试点 $2\sim 4$，$n,m,q\le 10$。

对于测试点 $5$，$n=1$。

对于测试点 $6$，$m=1$。

对于测试点 $7$，$m=2$。

对于测试点 $8\sim 9$，数据随机生成，$q\le 10^3$。

对于测试点 $10\sim 11$，$n,m,q\le 10^3$。

对于测试点 $12\sim 13$，$n,m,q\le 5\times 10^3$。

对于测试点 $14\sim 15$，$n,m,q\le 5\times 10^4$。

对于测试点 $16\sim 17$，$n,m,q\le 5\times 10^5$。

对于测试点 $18\sim 20$，$n,m,q\le 5\times 10^6$。

对于所有测试点，$1\le n,m,q\le 5\times 10^6,1\le x_i\le n,1\le col_i,y_i\le m$。

# 夜空中最亮的星(star)  1s 256MiB

## 题目描述

给出平面上的 $n$ 个点 $(x,y)$，保证 $1\le x,y\le 10^9$，坐标为正整数，我们称这些点为星空上的。

接下来会有 $q$ 次操作，操作会有两种类型：

`1 x y` 在星空上加入点 $(x,y)$。

`2 p` 你在坐标系中的点 $A(p,0)$ 上，现在你要找到一个星空上的点 $B(x,y)$，使得 $x$ 轴与 $AB$ 的夹角尽可能小（默认为锐角）。为了方便输出，我们要求你输出这个角的正切值。

对于一个包含了角 $\alpha$ 的直角三角形，我们定义角 $\alpha$ 的对边长度与除直角边以外的邻边长度的比值为 $\alpha$ 的正切值。

## 输入格式

第一行一个正整数 $n$，表示星空中初始点的数量。

接下来 $n$ 行，每行两个正整数 $x,y$ 表示一个点的坐标。

然后输入一个正整数 $q$ 表示操作组数。

接下来 $q$ 行，每行 $2$ 到 $3$ 个数表示一次操作，操作格式见题目描述。

## 输出格式

对于每次 $2$ 类操作，输出这个正切值。我们认为你的答案是正确的当且仅当你的答案与标准答案的绝对误差不超过 $10^{-6}$，换句话说，若你的答案是 $x$，标准答案是 $y$，只要 $|x-y|\le 10^{-6}$ 则认为你的答案正确。

## 样例

### 输入#1

```
2
2 5
3 8
4
2 1
2 4
1 5 2
2 4 
```

### 输出#1

```
4.000000000
2.500000000
2.000000000
```

### 输入#2和输出#2

见下发文件。

## 说明

对于所有输入的 $p$，保证此时不存在一个星空上的点的横坐标与之相等。

|  测试点编号   |       特殊性质        |
| :-----------: | :-------------------: |
|   $1,2,3,4$   |     $n,q\le 5000$     |
|     $5,6$     |           A           |
|    $7,8,9$    |           B           |
| $10,11,12,13$ |           C           |
|  $14,15,16$   | $n,q\le 5\times 10^4$ |
| $17,18,19,20$ |          无           |

特殊性质 A：对于所有星空上的点，保证要么它们的横坐标都相同，要么纵坐标都相同。

特殊性质 B：保证所有输入数据在数据范围内随机生成。

特殊性质 C：保证没有修改操作。

对于所有数据，保证 $1\le n,q\le 2\times10^5,1\le x,y\le 10^9$。