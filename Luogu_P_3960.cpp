#include <bits/stdc++.h>
#define MAXN 300003
#define int long long
using namespace std;
int n,m,q;
struct eve{
    int x;
    int y;
    int id;
}e[MAXN];
std::mt19937 Rand(9879873);
struct D{
    int ch[2],key;
    long long l,r,size,len; //Treap内存的是区间
}t[MAXN*20];
int root[MAXN+1],cnt;
void pushup(int x) {t[x].size=t[x].len+t[t[x].ch[0]].size+t[t[x].ch[1]].size;}
int merge(int u,int v){
    if (!u || !v) return u|v;
    if (t[u].key<=t[v].key){
        t[u].ch[1]=merge(t[u].ch[1],v);
        pushup(u); return u;
    } else {
        t[v].ch[0]=merge(u,t[v].ch[0]);
        pushup(v); return v;
    }
}
void split_rk(int now,int rk,int &u,int &v){
    if (!now) return (void)(u=v=0);
    if (t[now].size-t[t[now].ch[1]].size<=rk){
        u=now; split_rk(t[now].ch[1],rk-(t[now].size-t[t[now].ch[1]].size),t[now].ch[1],v);
    } else {
        v=now; split_rk(t[now].ch[0],rk,u,t[now].ch[0]);
    }
    pushup(now);
    return;
}
void split_rk2(int now,int rk,int &u,int &v){ //倒着弄，使得包含第rk个数的区间在右子树内
    if (!now) return (void)(u=v=0);
    if (t[now].size-t[t[now].ch[0]].size<=rk){
        u=now; split_rk2(t[now].ch[0],rk-(t[now].size-t[t[now].ch[0]].size),t[now].ch[0],v);
    } else {
        v=now; split_rk2(t[now].ch[1],rk,u,t[now].ch[1]);
    }
    pushup(now);
    return;
}
void insert(int rtw,long long x){
    t[++cnt].l=x; t[cnt].r=x; t[cnt].len=t[cnt].size=1;
    t[cnt].key=Rand();
    root[rtw]=merge(root[rtw],cnt);
    return;
}
long long del(int rtw,int rk){
    int a,b,c,d; long long res;
    split_rk(root[rtw],rk-1,a,b);
    // c=b;
    // if (!t[b].ch[0]){ //b没有左儿子
    //     if (!t[b].ch[1]){ //b也没有右儿子
    //         d=0;
    //     } else {
    //         d=t[b].ch[1];
    //     }
    //     t[c].ch[1]=0;
    // } else {
    //     while (t[t[c].ch[0]].ch[0]) c=t[c].ch[0];
    //     int fa=c; c=t[c].ch[0]; t[fa].ch[0]=0;
    //     d=b;
    // }
    split_rk2(b,t[b].size-1,d,c); //找出包含第rk个数的区间c
    if (t[c].size==1) {res=t[c].l; t[c].len=t[c].size=0; root[rtw]=merge(a,d);}
    else {
        if (t[a].size+1==rk) {res=t[c].l; t[c].l++; t[c].len--; t[c].size--; root[rtw]=merge(merge(a,c),d);}
        else if (t[a].size+t[c].size==rk) {res=t[c].r; t[c].r--; t[c].len--; t[c].size--; root[rtw]=merge(merge(a,c),d);}
        else {
            res=t[c].l+(rk-t[a].size)-1;
            t[++cnt].l=t[c].l+(rk-t[a].size); t[cnt].r=t[c].r; t[cnt].size=t[cnt].len=t[cnt].r-t[cnt].l+1;
            t[c].r=t[c].l+(rk-t[a].size)-2; t[c].size=t[c].len=t[c].r-t[c].l+1;
            root[rtw]=merge(merge(merge(a,c),cnt),d);
        }
    }
    return res;
}
void init(){
    for (int i=1;i<=n+1;i++) root[i]=++cnt;
    for (int i=1;i<=n;i++){
        t[i].l=(i-1)*m+1; t[i].r=i*m-1;
        t[i].size=t[i].len=t[i].r-t[i].l+1;
        t[i].key=Rand();
    }
    for (int i=1;i<=n;i++) insert(n+1,1ll*i*m);
    return;
}
signed main(){
    // freopen("P3960.in","r",stdin);
    // freopen("P3960.ans","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m>>q;
    for (int i=1;i<=q;i++) {cin>>e[i].x>>e[i].y;}
    init();
    for (int i=1;i<=q;i++){
        if (e[i].y!=m){
            long long val=del(e[i].x,e[i].y);
            insert(n+1,val);
            long long tmp=del(n+1,e[i].x);
            insert(e[i].x,tmp);
            cout<<val<<endl;
        } else {
            long long val=del(n+1,e[i].x);
            insert(n+1,val);
            cout<<val<<endl;
        }
    }
    return 0;
}