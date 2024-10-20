#include <bits/stdc++.h>
#define MAXN 200003
using namespace std;
int n,q;
std::mt19937 Rand(98734753);
struct D{
    int ch[2],val_x,val_y,key,size;
    void _new(int x,int y){
        val_x=x; val_y=y; key=Rand(); size=1;
    }
}t[MAXN*2]; int root;
double getk(int ax,int ay,int bx,int by){
    return double(by-ay)/double(bx-ax);
}
void pushup(int u) {t[u].size=t[t[u].ch[0]].size+t[t[u].ch[1]].size+1;}
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
void split_val(int now,int x,int &u,int &v){
    if (!now) return (void)(u=v=0);
    if (t[now].val_x<=x){
        u=now; split_val(t[u].ch[1],x,t[u].ch[1],v);
    } else {
        v=now; split_val(t[v].ch[0],x,u,t[v].ch[0]);
    }
    return;
}
void split_rk(int now,int rk,int &u,int &v){
    if (!now) return (void)(u=v=0);
    if (t[t[now].ch[0]].size<rk){
        u=now; split_rk(t[now].ch[1],rk-t[now].ch[0]-1,t[now].ch[1],v);
    } else {
        v=now; split_rk(t[now].ch[0],rk,v,t[now].ch[0]);
    }
    return;
}
// void INS(int x,int y){
//     int a,b;
//     split_val(root,x-1,a,b);
//     D lf=to_be_rk(a,t[a].size),ri=to_be_rk(b,1);
//     if (!ri.val_x) insert(x,y);
//     else if (!lf.val_x) insert(x,y);
//     else if (getk(lf.val_x,lf.val_y,ri.val_x,ri.val_y)>getk(lf.val_x,lf.val_y,x,y)){
        
//         insert(x,y);
//     }
// }
struct DOT{
    int x;
    int y;
}a[MAXN*2]; int cnt;
int main(){
    freopen("star.in","r",stdin);
    freopen("star.out","w",stdout);
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    // printf("%0.9lf\n",pow<double>(68,0.5));
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[++cnt].x>>a[cnt].y;
        // INS(x,y);
    }
    cin>>q;
    while (q--){
        int type; cin>>type;
        if (type==1){
            cin>>a[++cnt].x>>a[cnt].y;
        } else {
            int x; cin>>x;
            int w=1; double K=abs(getk(x,0,a[1].x,a[1].y));
            for (int i=2;i<=cnt;i++){
                double now=abs(getk(x,0,a[i].x,a[i].y));
                if (now<K){
                    K=now; w=i;
                }
            }
            printf("%0.9lf\n",K);
            // printf("%0.9lf\n",double(a[w].y)/pow<double>(((a[w].x-x)*(a[w].x-x)+(a[w].y*a[w].y)),0.5));
        }
    }
    return 0;
}