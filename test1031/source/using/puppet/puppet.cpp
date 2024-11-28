#include<bits/stdc++.h>
using namespace std;
int read(){
	int x,c;
	while((c=getchar())<'0'||c>'9');
	x=c^48;
	while((c=getchar())>='0'&&c<='9')x=(x<<3)+(x<<1)+(c^48);
	return x;
}

typedef long long ll;
const int maxn=1000020;
int n,q;
unsigned z1,z2,z3,z4,b;
unsigned rand_(){
	b=((z1<<6)^z1)>>13;
	z1=((z1&4294967294U)<<18)^b;
	b=((z2<<2)^z2)>>27;
	z2=((z2&4294967288U)<<2)^b;
	b=((z3<<13)^z3)>>21;
	z3=((z3&4294967280U)<<7)^b;
	b=((z4<<3)^z4)>>12;
	z4=((z4&4294967168U)<<13)^b;
	return (z1^z2^z3^z4);
}
void srand(unsigned s1,unsigned s2){
	z1=s1;
	z2=(~s1)^0x233333333U;
	z3=s2^0x1234598766U;
	z4=(~s2)+51;
}
int Gen(){
	int a=rand_()&32767;
	int b=rand_()&32767;
	return ((a<<15)+b)%(n*3);
}
int t[maxn],l[3][maxn],r[3][maxn],val[maxn],dis[maxn];
void init(){
	for(int i=1;i<n;i++)
		t[i]=read();
	for(int i=0;i<n;i++)
		l[0][i]=l[1][i]=l[2][i]=r[0][i]=r[1][i]=r[2][i]=i;
	for(int i=1;i<n;i++){
		if(t[i]&4)
			r[2][i]=r[2][i-1];
		if(t[i]&2)
			r[1][i]=r[1][i-1];
		if(t[i]&1)
			r[0][i]=r[0][i-1];
	}
	for(int i=n-1;i>0;i--){
		if(t[i]&4)
			l[2][i-1]=l[2][i];
		if(t[i]&2)
			l[1][i-1]=l[1][i];
		if(t[i]&1)
			l[0][i-1]=l[0][i];
	}
	for(int i=0;i<n;i++)
		val[i]=max(max(l[0][i],l[1][i]),l[2][i]);
	dis[0]=1;
	for(int i=2,g=0;g<n-1;i++){
		for(int j=g+1;j<=val[g];j++)
			dis[j]=i;
		g=val[g];
	}
}
int query(){
	int x=Gen(),y=Gen();
	if(x==y)
		return 0;
	if(x>y)swap(x,y);
	int xi=x%3,yi=y%3;
	x/=3;y/=3;
	if(x==y)
		return 1;
	int ans=y-x;
	if(xi==yi&&y<=l[xi][x])
		return ans;
	if(r[yi][y]<=l[xi][x])
		return ans+1;
	x=l[xi][x];y=r[yi][y];ans+=2;
	while(true){
		if(y<=val[x])
			return ans;
		x=val[x];
		if(dis[x]!=dis[x+1])
			return ans+dis[y]-dis[x];
		ans++;
	}
}
int main(){
	freopen("puppet.in","r",stdin);
	freopen("puppet.out","w",stdout);
	read();
	n=read();q=read();
	init();
	unsigned s1=read(),s2=read();
	srand(s1,s2);
	ll ans=0;
	for(int i=1;i<=q;i++)
		ans^=(ll)i*query();
	printf("%lld\n",ans);
	return 0;
}
