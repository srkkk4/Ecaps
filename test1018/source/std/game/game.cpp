#include<bits/stdc++.h>
using namespace std;
int read(){
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	x=c^48;
	while((c=getchar())>='0'&&c<='9')x=(x<<3)+(x<<1)+(c^48);
	return x;
}
const int maxn=5000020;
int n,m,q;
int col[maxn],tag[maxn],tid,tx;
int fi[maxn],ne[maxn],eval[maxn],sg[maxn];
int main(){
freopen("game.in","r",stdin);
freopen("game.out","w",stdout);
	n=read();m=read();q=read();
	for(int i=1;i<=n;i++){
		col[i]=read();
		fi[i]=0;
	}
	for(int i=1;i<=q;i++){
		int x=read();eval[i]=read();
		ne[i]=fi[x];fi[x]=i;
	}
	tid=1;
	for(int i=1;i<=m;i++)
		tag[i]=0;
	for(int i=1;i<=n;i++)
		if(tag[col[i]]==tid){
			for(int j=fi[i];j;j=ne[j])
				if(eval[j]==col[i])
					sg[j]=tx;
				else if(tag[eval[j]]==tid)
					sg[j]=i;
				else
					sg[j]=i-1;
			tag[col[i]]=tid^1;
		}
		else{
			for(int j=fi[i];j;j=ne[j])
				if(eval[j]==col[i])
					sg[j]=i-1;
				else if(tag[eval[j]]==tid)
					sg[j]=tx;
				else
					sg[j]=i;
			tid^=1;
			tag[col[i]]=tid^1;
			tx=i-1;
		}
	for(int i=2;i<=q;i++)
		sg[i]^=sg[i-1];
	for(int i=1;i<=q;i++)
		if(sg[i]==0)
			putchar('0');
		else
			putchar('1');
	return 0;
}
