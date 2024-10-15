#include<bits/stdc++.h>
#define MAXN 100003
using namespace std;
int n;
std::mt19937 Rand(9023645);
struct D{
    int ch[2],val,key,size;
    void new_(int x){
        ch[0]=ch[1]=0; val=x; key=Rand(); size=1;
        return;
    }
}t[MAXN];
int root,cnt;
void pushup(int now){
    t[now].size=t[t[now].ch[0]].size+t[t[now].ch[1]].size+1;
    return;
}
int merge(int u,int v){
    if (!u || !v) return u|v;
    if (t[u].key<t[v].key){
        t[u].ch[1]=merge(t[u].ch[1],v);
        pushup(u); return u;
    } else {
        t[v].ch[0]=merge(u,t[v].ch[0]);
        pushup(v); return v;
    }
}
void split_val(int now,int x,int &u,int &v){
    if (!now) return (void)(u=v=0);
    if (t[now].val<=x){
        u=now; split_val(t[now].ch[1],x,t[now].ch[1],v);
    } else {
        v=now; split_val(t[now].ch[0],x,u,t[now].ch[0]);
    }
    pushup(now);
    return;
}
void split_rk(int now,int rk,int &u,int &v){
    if (!now) return (void)(u=v=0);
    if (t[t[now].ch[0]].size<rk){
        u=now; split_rk(t[now].ch[1],rk-t[t[now].ch[0]].size-1,t[now].ch[1],v);
    } else {
        v=now; split_rk(t[now].ch[0],rk,u,t[now].ch[0]);
    }
    pushup(now);
    return;
}
void insert(int x){
    int a,b;
    split_val(root,x,a,b);
    t[++cnt].new_(x);
    root=merge(merge(a,cnt),b);
    return;
}
void del(int x){
    int a,b,c,d;
    split_val(root,x-1,a,b);
    split_rk(b,1,c,d);
    root=merge(a,d);
    return;
}
int get_rk(int x){
    int a,b; int res;
    split_val(root,x-1,a,b);
    res=t[a].size+1;
    root=merge(a,b);
    return res;
}
int to_be_rk(int rk){
    int a,b,c,d; int res;
    split_rk(root,rk-1,a,b);
    split_rk(b,1,c,d);
    res=t[c].val;
    root=merge(a,merge(c,d));
    return res;
}
int pre(int x){
    int a,b,c,d; int res;
    split_val(root,x-1,a,b);
    split_rk(a,t[a].size-1,c,d);
    res=t[d].val;
    root=merge(merge(c,d),b);
    return res;
}
int suf(int x){
    int a,b,c,d; int res;
    split_val(root,x,a,b);
    split_rk(b,1,c,d);
    res=t[c].val;
    root=merge(a,merge(c,d));
    return res;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++){
        int type,x; cin>>type>>x;
        if (type==1){
            insert(x);
        } else if (type==2){
            del(x);
        } else if (type==3){
            cout<<get_rk(x)<<endl;
        } else if (type==4){
            cout<<to_be_rk(x)<<endl;
        } else if (type==5){
            cout<<pre(x)<<endl;
        } else {
            cout<<suf(x)<<endl;
        }
    }
    return 0;
}