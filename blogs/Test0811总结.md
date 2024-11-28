# Contest 0811 总结

## [A.Zrinka](https://www.luogu.com.cn/problem/P9173)

给你两个长度分别为 $n$ 和 $m$ 的数组，它们只由 $0$ 和 $1$ 组成。

你的任务是用偶数替换每个 $0$，用奇数替换每个 $1$。

替换之后，两个数组都应该是单调递增的且所有元素均大于 $0$，并且你最多可以使用每个正整数一次，使用的最大数字要尽可能的小。

$n,m \le 5000$

**Solution**

数据范围5000想到DP，设计状态 $dp[i][j][0/1]$ 表示当替换了 $a$ 的前 $i$ 个及 $b$ 的前 $j$ 个且最后一个替换的数属于 $a,b$ 中的哪一个。

边界：$dp[i][0][0]$ 以及 $dp[0][j][1]$ 贪心求结果。$dp[0][0][0]$ 以及 $dp[0][0][1]$ 设为 $0$ ,其他取无穷大。

**Code**

```c++
#include <bits/stdc++.h>
#define MAXN 5003
using namespace std;
int n,m;
int a[MAXN],b[MAXN];
int dp[MAXN][MAXN][2];
int main(){
    cin>>n;
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    cin>>m;
    for (int i=1;i<=m;i++) scanf("%d",&b[i]);
    memset(dp,0x3f,sizeof dp); dp[0][0][0]=0; dp[0][0][1]=0;
    for (int i=1;i<=n;i++) dp[i][0][0]=dp[i-1][0][0]+(a[i]==a[i-1]?2:1);
    for (int i=1;i<=m;i++) dp[0][i][1]=dp[0][i-1][1]+(b[i]==b[i-1]?2:1);
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            dp[i][j][0]=min(dp[i-1][j][0]+(a[i-1]==a[i]?2:1),dp[i-1][j][1]+(b[j]==a[i]?2:1));
            dp[i][j][1]=min(dp[i][j-1][1]+(b[j]==b[j-1]?2:1),dp[i][j-1][0]+(b[j]==a[i]?2:1));
        }
    }
    cout<<min(dp[n][m][0],dp[n][m][1])<<endl;
    return 0;
}
```

## [B.LADICE](https://www.luogu.com.cn/problem/P7677)

有 $N$ 个物品，$L$ 个抽屉，没个抽屉只能放 $1$ 个物品，每个物品都能被放进抽屉 $A_i$ 或 $B_i$ 中。

放物品的规则如下（按照顺序执行，即满足条件 $1$ 时就立刻执行，不会执行条件 $2$；不满足条件 $1$ 时就判断条件 $2$）：

- $1.$ 如果抽屉 $A_i$ 是空的，就把这个物品放进抽屉 $A_i$ 中；

- $2$ 如果抽屉 $B_i$ 是空的，就把这个物品放进抽屉 $B_i$ 中；

- $3.$ 把抽屉 $A_i$ 中的物品移到它的另一个抽屉里；如果这个抽屉也满了，就把这个抽屉里的物品放到它的另一个抽屉里，知道你成功或回到之前遇到过的抽屉为止。如果成功了，就把这个物品放进这个抽屉中；

- $4.$ 把抽屉 $B_i$ 中的物品移到它的另一个抽屉里；如果这个抽屉也满了，就把这个抽屉里的物品放到它的另一个抽屉里，知道你成功或回到之前遇到过的抽屉为止。如果成功了，就把这个物品放进这个抽屉中；

- $5.$ 扔掉此物品。

对于给定的每件物品，请你求出哪些物品将被保存，哪些将被扔掉。

**Solution**

- 物品可能且仅能由A移动到B，不能由B移动到A；

由 $A_i$ 向 $B_i$ 连有向边，将相连的边视作一个并查集，一个并查集仅有根结点可能是空的，即并查集内（也可以是单独一个点）的任意一次存放（单独一个点时就相当于把物品放入这个抽屉且不影响其他抽屉）都会使根节点被占用（如果根节点free的话）。

当加入一个物品时，依照顺序依次检查 $A_i$ 所在并查集以及 $B_i$ 所在并查集是否可以接受一个新物品的加入（根节点是否free），有空闲就**加入**且合并并查集，没有就输出`SMECE`。

**Code**

```c++
#include <bits/stdc++.h>
#define MAXN 300003
using namespace std;
int n,L;
struct sub{
    int a,b;
};
sub a[MAXN];
struct situ{
    int f;
    bool s;
};
situ fa[MAXN];
void init(){
    for (int i=1;i<=300000;i++) fa[i].f=i;
    return;
}
int find(int x){
    while (fa[x].f!=x) x=fa[x].f=fa[fa[x].f].f;
    return x;
}
int main(){
    cin>>n>>L;
    for (int i=1;i<=n;i++){
        cin>>a[i].a>>a[i].b;
    }
    init();
    for (int i=1;i<=n;i++){
        int faa=find(a[i].a),fab=find(a[i].b);
        if (!fa[faa].s){
            fa[faa].s=1; //标记为占用
            fa[faa].f=fab; //合并
            printf("LADICA\n");
        } else if (!fa[fab].s){
            fa[fab].s=1;
            fa[faa].f=fab;
            printf("LADICA\n");
        } else {
            printf("SMECE\n"); //无法加入
        }
    }
    return 0;
}
```

## [C.DVONIZ](https://www.luogu.com.cn/problem/P7635)

当前 $K$ 个元素的和与最后 $K$ 个元素的和都不大于 $S$ 时，我们说这个 $2\times K$ 个元素的序列是有趣的。

给出一个长度为 $N$ 的序列 $A$。对于每个元素，输出从该元素开始的最长的有趣的子段。

**Solution**

处理前缀和 $q$ ,枚举 $q_i$ ,二分查找 $q_j$ ，使得前半部分 $q_j-q_{i-1}$ 最大。 $j$ 往前枚举，直到找到后半部分满足条件的 $j$ ，输出答案。

**Code**

```c++
#include <bits/stdc++.h>
#define MAXN 100003
using namespace std;
int n,s;
int a[MAXN];
int q[MAXN];
int main(){
    cin>>n>>s;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    for (int i=1;i<=n;i++){
        q[i]=q[i-1]+a[i];
    }
    for (int i=1;i<=n-1;i++){
        int l=i,r=i-1+(n-i+1)/2,mid;
        while (l<r){
            mid=(l+r)>>1;
            if (q[mid]-q[i-1]>s) r=mid-1;
            else l=mid+1;
        }
        int ans=0;
        for (int j=l;j>=i;j--){
            if (q[j]-q[i-1]<=s&&q[j+(j-i+1)]-q[j]<=s){
                ans=(j-i+1)*2;
                break;
            }
        }
        cout<<ans<<endl;
    }
    cout<<0<<endl;
    return 0;
}
```

## [D.PIRAMIDA](https://www.luogu.com.cn/problem/P6416)

Zoran 和 Tomislav 今天很无聊。

于是，他们把他们喜欢的字符串 `JANJETINA` 按照一定规律在一个塔上从左到右从上到下写了一遍又一遍。

这是塔只有六层的情况：

![](https://cdn.luogu.com.cn/upload/image_hosting/ja46bpf9.png?x-oss-process=image/resize,m_lfit,h_170,w_225)

现在他们想考你一个问题：给定字符串 $s$ 与塔的层数 $n$，将这个字符串在塔上写一遍又一遍，接下来会有 $k$ 个问题，第 $i$ 次问你字符 $c_i$ 在第 $a_i$ 层出现了几次。

**Solution**

计算出当前层的第一个字母在原字符串中的位置，利用前缀和求出 $c_i$ 在当前层中的个数。

> 32Mib内存限制，前缀和离线处理。

> 神金评测机爆 __int128

**Code**

```c++
#include <bits/stdc++.h>
#define MAXL 1000003
#define MAXK 50003
using namespace std;
long long n;
int k;
char s[MAXL];
// int q[27][MAXL];
int ton[MAXL];
int cnt[27];
map <int,int[27]> p;
long long a[MAXK]; char c[MAXK];
int main(){
    cin>>n;
    cin>>s;
    long long len=strlen(s); ton[len]=1;
    // for (int i=0;i<len;i++){
    //     for (int j=1;j<=26;j++){
    //         q[j][i+1]=q[j][i];
    //     }
    //     q[s[i]-'A'+1][i+1]++;
    // }
    cin>>k;
    for (int i=1;i<=k;i++){
        cin>>a[i]>>c[i];
        __int128 tmp=a[i];
        tmp=tmp*(a[i]-1);
        tmp=tmp/2+1;
        int l=(tmp-1)%len+1;
        long long ans=0;
        ton[(a[i]+l-1)%len]=1; ton[l-1]=1;
    }
    for (int i=0;i<len;i++){ //离线前缀和
        cnt[s[i]-'A'+1]++;
        if (ton[i+1]){
            for (int j=1;j<=26;j++){
                p[i+1][j]=cnt[j];
            }
        }
    }
    for (int i=1;i<=k;i++){
        __int128 tmp=a[i];
        tmp=tmp*(a[i]-1);
        tmp=tmp/2+1;
        int l=(tmp-1)%len+1;
        long long ans=0;
        a[i]+=l-1;
        ans+=p[len][c[i]-'A'+1]*(a[i]/len);
        ans+=p[a[i]%len][c[i]-'A'+1];
        ans-=p[l-1][c[i]-'A'+1];
        cout<<ans<<endl;
        // ans+=q[c-'A'+1][len]*(a/len); 在线前缀和,MLE预定
        // ans+=q[c-'A'+1][a%len];
        // ans-=q[c-'A'+1][l-1];
        // cout<<ans<<endl;
    }
    return 0;
}
```

## [E.Sjeckanje](https://www.luogu.com.cn/problem/P7402)

给定一个包含 $n$ 个整数的数组 $a$。接着进行 $q$ 次修改，每次给定整数 $l,r,x$。表示将 $[l,r]$ 内的所有元素加上 $x$。

规定一个区间的权值为**该区间的最大值减去最小值**。现要将 $a$ 数组分为若干个连续的区间。规定一个已被分为若干个区间的数组的权值为**该数组所有区间的权值之和**。求数组 $a$ 在**每次修改**后的所有分法中，数组权值的最大值。

**Solution**

不会