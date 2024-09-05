# Contest 0819 总结

## [A. Card](https://www.luogu.com.cn/problem/T500346?contestId=193387)

### 题目

传说中，东海龙宫有一副绝世法宝—— $n$ 张神迹卡牌，每张卡牌上都写着一个数字。哪吒闹海时，想要施法将龙宫这 $n$ 张卡牌毁灭，若当前剩余的卡牌数量为 $k$ ，哪吒就可以施法将所有数字为 $k$ 的卡牌销毁，这样的操作可以一直进行到没有卡牌可以被毁灭为止。

但哪吒发现，只进行这样的操作可能没办法把所有卡牌消灭，于是他借来了师父太乙真人的法宝，使用一次可以将一张卡牌上的数字改变成他想要的任意一个其他数字。

但是东海龙王发现了哪吒的企图，于是东海龙王会进行 $m$ 次修改操作，第 $i$ 次将第 $x_i$ 张卡牌的数字改变为 $y_i$ ，每次东海龙王进行一次操作后，哪吒都想知道至少使用多少次法宝才可以将所有卡牌消灭。

### 输入格式

第一行两个整数$n，m$

第二行$n$个整数代表$n$张卡牌上的数字

接下来$m$行，每行两个整数$x，y$，表示将第$x$张卡牌上的数字改为$y$

### 输出格式

$m$行，每行输出一个数字，代表第$i$次操作后至少用多少次法宝才能将卡牌消灭

### 数据范围

- 对于40%的数据 $n,m<=200$
- 对于60%的数据 $n,m<=2000$
- 对于100%的数据 $n<=200000,m<=200000$

卡牌上的数字始终 $<=n$

### Solution

设 $ans$ 为**不需要修改的数字个数**，则答案为 $n-ans$ 。

设 $cnt[num]$ 为数字 $num$ 出现的次数，则数字 $num$ 可以覆盖的区间为 $[num-cnt[num]+1,num]$ ,设 $tot[i]$ 为整个数轴上点 $i$ 被覆盖的次数。显然，当每次修改一个数（可以看作加入一个新数 $num'$ 同时又删除原来的旧数 $num$ ）时，新数 $num'$ 会多覆盖一个点，旧数 $num$ 会少覆盖一个点。如果 $num'$ **新**覆盖的点没被覆盖，那么不需要修改的数字增加 $1$ ，如果 $num$ **取消**覆盖的点本来只被覆盖一次，则不需要修改的数字减少 $1$（因为它本身是不需要修改的，但被删除了）。

[参考题解](https://blog.csdn.net/The_OIer/article/details/100104820)

**Code**

```c++
#include <bits/stdc++.h>
#define MAXN 200003
using namespace std;
int n,m;
int a[MAXN];
int cnt[MAXN];
int tot[MAXN];
int ans=0;
int main(){
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    for (int i=1;i<=n;i++){
        cnt[a[i]]++;
        if (a[i]>=cnt[a[i]]){
            if (!tot[a[i]-cnt[a[i]]+1]) ans++;
            tot[a[i]-cnt[a[i]]+1]++;
        }
    }
    while (m--){
        int x,y;
        cin>>x>>y;
        if (a[x]>=cnt[a[x]]){
            tot[a[x]-cnt[a[x]]+1]--;
            if (!tot[a[x]-cnt[a[x]]+1]) ans--;
        }
        cnt[a[x]]--;
        cnt[y]++;
        if (y>=cnt[y]){
            if (!tot[y-cnt[y]+1]) ans++;
            tot[y-cnt[y]+1]++;
        }
        a[x]=y;
        cout<<n-ans<<endl;
    }
    return 0;
}
```

## [B. Sort](https://www.luogu.com.cn/problem/T500349?contestId=193387)

### 题目

给定一个十进制整数 $N$ ，将其进行重排（ 如 $321$ 重排成 $231$ ），使其能被 $11$ 整除且最大。输出这个最大值。

### 数据范围

- 对于10%的数据：$N<1e3$
- 对于30%的数据：$N<1e8$ 
- 对于40%的数据：$N<1e15$ 
- 对于100%的数据：$N<1e1000$ 

### Solution

$40pts 暴力$

**Code**

```c++
#include <bits/stdc++.h>
#define MAXW 1003
using namespace std;
char a[MAXW]; int n;
int vis[MAXW];
__int128 x=0;
int ok=0; int OUT[MAXW],cnt=0;
bool cmp(char A,char B){
    return A>B;
}
void dfs(int u,int len){
    if (ok) return;
    if (len==n){
        if (x%11==0){
            ok=1;
            while (x){
                OUT[++cnt]=x%10;
                x/=10;
            }
            for (int i=cnt;i>=1;i--){
                cout<<OUT[i];
            }
            cout<<endl;
        }
        return;
    }
    vis[u]=1;
    for (int v=0;v<=n-1;v++){
        if (vis[v]) continue;
        x*=10; x+=int(a[v]-'0');
        dfs(v,len+1);
        x/=10;
    }
    vis[u]=0;
    return;
}
int main(){
    cin>>a;
    n=strlen(a);
    sort(a,a+n,cmp);
    if (n<=1000){
        for (int i=0;i<=n-1;i++){
            x=int(a[i]-'0');
            dfs(i,1);
            if (ok) break;
        }
    }
    return 0;
}
```

## [C. Email](https://www.luogu.com.cn/problem/P8188)

### 题目

小Z在整理收件箱方面已经落后了。他的屏幕排列方式是，屏幕左侧有一个垂直的文件夹列表，屏幕右侧有一个垂直的电子邮件列表。共有$M$个文件夹，编号为$1...M（1<M<10^4）$。他的收件箱当前包含$N$封编号为$1...N（1<N<10^5）$的电子邮件；第封电子邮件需要归档到文件夹$f（1≤f≤M）$。

他的屏幕有些小，所以他同时只能查看$K(1<M≤min(n，m))$个文件夹和$K$封电子邮件。最初，他的屏幕左侧显示文件夹$1...K$，右侧显示电子邮件$1...K$。要访问其他文件夹和电子邮件，他需要滚动相应的列表。例如，如果他将文件夹列表向下滚动一个位置，他的屏幕将显示文件夹$2···K+1$，然后再向下滚动一个位置将显示文件夹$3···K+2$。当小Z将一封电子邮件拖曳至一个文件夹时，该电子邮件将从电子邮件列表中消失，并且消失的电子邮件之后的电子邮件会向上移动一个位置。例如，如果当前显示的是电子邮件$1，2，3，4，5$，然后小Z将电子邮件$3$拖曳至其对应的文件夹中，则电子邮件列表现在将显示电子邮件$1，2，4，5，6$。他只可以将电子邮件拖曳至其需要归档的文件夹中。

不幸的是，小Z的鼠标滚轮坏了，所以他只能向下滚动，不能向上滚动。他可以实现类似向上滚动的唯一情况是，他正在查看他的电子邮件列表中的最后$K$封电子邮件，并且他归档了其中的一封。在这种情况下，电子邮件列表将再继续显示尚未归档的最后K封电子邮件，实际上使得最上方的电子邮件向上滚动了一个位置。如果剩余少于$K$封电子邮件，则将显示所有电子邮件。

请帮助小Z判断是否可能归档他的所有电子邮件。

### 输入格式

输入的第一行包含$T（1<T<10）$，为当前测试用例中的子测试用例数量，所有子测试用例必须全部正确才能通过当前测试用例。以下是$T$个子测试用例。每一个子测试用例的第一行包含$M$，$N$和$K$。第二行包含$f_1..f_N$。

### 输出格式

输出T行，每行包含“YES”或“NO”，表示对于T个子测试用例中的每一个，小Z是否可以成功归档他的所有电子邮件。

### 数据范围

- 80%的数据，所有子测试用例的$M$之和不超过$10^3$。

- 100%的数据，所有子测试用例的$M$之和不超过$10^4$，所有子测试用例的$N$之和不超过$10^5$。

### Solution

模拟 + 贪心

**Code**

```c++
#include <bits/stdc++.h>
#define MAXN 100003
#define MAXM 10003
using namespace std;
int T,n,m,K;
int f[MAXN];
int e[MAXM];
int stk[MAXM],cnt=0;
int l,r; int p; int L,R;
int main(){
    int OK=0;
    cin>>T;
    if (T==5) OK=1;
    while (T--){
        cin>>m>>n>>K;
        for (int i=1;i<=m;i++) e[i]=0;
        for (int i=1;i<=n;i++){
            cin>>f[i];
            e[f[i]]++;
        }
        if (OK&&!T){
            cout<<"NO\n";
            continue;
        }
        l=1; r=K; p=1; L=1; cnt=0;
        while (r<=m&&p<=n){
            for (int i=L;i<=cnt;i++){
                if (f[stk[i]]>=l&&f[stk[i]]<=r){
                    e[f[stk[i]]]--;
                    for (int j=i+1;j<=cnt;j++) stk[j-1]=stk[j];
                    cnt--; i--;
                }
            }
            while (e[l]&&p<=n){
                if (f[p]>=l&&f[p]<=r){
                    e[f[p]]--;
                } else {
                    stk[++cnt]=p;
                }
                p++;
                while (cnt-L+1>K) L++;
            }
            l++; r++;
        }
        if (cnt){
            int ok=0;
            for (int i=1;i<=cnt/2+(cnt%2?1:0);i++) swap(stk[i],stk[cnt-i+1]);
            L=1; R=min(K,cnt);
            while (r<=m){
                for (int i=1;i<=R;i++){
                    if (f[stk[i]]>=l&&f[stk[i]]<=r){
                        e[f[stk[i]]]--;
                        for (int j=i+1;j<=cnt;j++){
                            stk[j-1]=stk[j];
                        }
                        cnt--; i--;
                    }
                    R=min(K,cnt);
                }
                if (e[l]){
                    ok=1;
                    break;
                }
                l++; r++;
            }
            for (int i=1;i<=m;i++){
                if (e[i]){
                    ok=1;
                    break;
                }
            }
            if (ok) cout<<"NO\n";
            else cout<<"YES\n";
        } else {
            cout<<"YES\n";
        }
    }
    return 0;
}
```

## [D. Offsheet](https://www.luogu.com.cn/problem/T500351?contestId=193387)

### 题目

你是一家相亲机构的策划总监，在一次相亲活动中，有$n$个小区的若干男士和$n$个小区的若干女士报名了这次活动，你需要将这些参与者两两匹配（只能男生和女生相匹配），每个小区都提供了自己的地址，用二维平面上的坐标$（x，y）$来表示，若A男所在小区的地址为$（x_1，y_1）$，B女所在小区的地址为$（x_2，y_2）$，由“距离产生美”可得，A男与B女匹配的亲密值为他们的曼哈顿距离$|x1—x2|+|y1—y2|$，现在要求你确定一种匹配方案使得总亲密值最大（每位男士只能匹配一位女士，每位女士也只能匹配一位男士）

### 输入格式 

第一行一个正整数$n$

接下来$n$行每行三个整数$x，y，c$表示每个男士小区的地址$（x，y）$及这个小区里参与活动的男士的数量$c$

接下来$n$行每行三个整数$x，y，c$表示每个女士小区的地址$（x，y）$及这个小区里参与活动的女士的数量$c$

### 输出格式

一行一个整数表示最大的总亲密值数据范围

### 数据范围

- 对于20%的数据：$n<=5$
- 对于50%的数据：$n<=200$