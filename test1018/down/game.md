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