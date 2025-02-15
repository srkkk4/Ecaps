#	 回文串题解

## 解法一

枚举中心点，直接向外扩展，暴力求出当前这一位的值，复杂度 $O(n^3)$，常数较小，可以获得 20 分

## 解法二

改良解法一，将暴力求值改为树状数组，复杂度 $O(n^2\log n)$，常数小，可以获得 40 分

## 解法三

保证单调不减，则答案的字符串左半部分一定全部相同，简单贪心即可，结合前面的解法可以获得 50 分

## 解法四

发现本题的回文串定义非常不优美，几乎没有特殊性质，但是依然有回文串的一个最基本的性质：一个回文串删去前后各一个字符后仍是回文串。

于是考虑哈希，并且贪心的去找最长回文子串。

假设当前中心点在 $i$ 和 $i+1$ 之间，对于左边部分，$j$ 位置的哈希值为 $\sum\limits_{k=j}^{i}[S_k\le S_j]B^{i-j}$，其中 $B$ 为一个常数，右半部分的 $j$ 位置的哈希值则为 $\sum\limits_{k=i+1}^{j}[S_k\le S_j]B^{j-i-1}$。 

可以分块维护。

可以获得 70 分，结合解法三可以获得 80 分。

## 解法五

发现答案具有单调性，所以可以先二分。

然后把需要计算的回文串哈希值左右分开计算，于是变成了一个滑动窗口在移动，然后每次求出滑动窗口内的哈希值。

此处可以使用树状数组维护，但是由于滑动窗口滑动时会导致哈希的幂次下降，所以需要实现除法，哈希模数需要使用质数。

