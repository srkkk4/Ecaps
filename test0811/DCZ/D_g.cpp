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
            fa[faa].s=1;
            fa[faa].f=fab;
            printf("LADICA\n");
        } else if (!fa[fab].s){
            fa[fab].s=1;
            fa[faa].f=fab;
            printf("LADICA\n");
        } else {
            printf("SMECE\n");
        }
    }
    return 0;
}