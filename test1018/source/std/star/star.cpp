#include<bits/stdc++.h>
using namespace std;
#define N 800001
int n,num;
struct line{
  double k,b;
}a[N<<1];
double get(int x,int y){
  return a[x].k*y+a[x].b;
}
int tag[N<<2],lc[N<<2],rc[N<<2],tot,rt;
#define mid (l+r>>1)
void modify(int &p,int l,int r,int x){
  if(!p)p=++tot;
  int &y=tag[p];
  if(get(x,mid)>get(y,mid))swap(x,y);
  if(l==r)return;
  bool a1=get(x,l)>get(y,l),a2=get(x,r)>get(y,r);
  if(a1)modify(lc[p],l,mid,x);
  if(a2)modify(rc[p],mid+1,r,x);
}
double query(int p,int l,int r,int pos){
  if(l==r)return get(tag[p],pos);
  double ans=get(tag[p],pos);
  if(pos<=mid)ans=max(ans,query(lc[p],l,mid,pos));
  else ans=max(ans,query(rc[p],mid+1,r,pos));
  return ans;
}
int main(){
  freopen("star.in","r",stdin);
  freopen("star.out","w",stdout);
  scanf("%d",&n);
  while(n--){
    int x,y;scanf("%d%d",&x,&y);
    a[++num]=(line){1.0/y,-1.0*x/y};
    modify(rt,1,1e9,num);
    a[++num]=(line){-1.0/y,1.0*x/y};
    modify(rt,1,1e9,num);
  }
  scanf("%d",&n);
  while(n--){
    int pos,x,y;
    scanf("%d",&pos);
    if(pos==1){
      scanf("%d%d",&x,&y);
      a[++num]=(line){1.0/y,-1.0*x/y};
      modify(rt,1,1e9,num);
      a[++num]=(line){-1.0/y,1.0*x/y};
      modify(rt,1,1e9,num);
    }
    else{
      scanf("%d",&x);
      printf("%.10lf\n",1/query(rt,1,1e9,x));
    }
  }
}
