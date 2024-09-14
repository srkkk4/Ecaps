#include<bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
#define poly vector<int>
int quickpow(int a,int b){
	int ret=1;
	while(b){
		if(b&1) ret=ret*a%mod;
		a=a*a%mod;
		b>>=1;
	}return ret;
}
int G=3;
int ri[1000005];
void NTT(poly &f,int N,int op){
	for(int i=0;i<N;i++){
		if(i<ri[i]) swap(f[i],f[ri[i]]);
	}
	for(int len=2,k=1;len<=N;len<<=1,k<<=1){
		int Wn=quickpow((op==1?G:quickpow(G,mod-2)),(mod-1)/len);
		for(int i=0;i<N;i+=len){
			for(int j=0,w=1;j<k;j++,w=w*Wn%mod){
				int x=f[i+j],y=f[i+j+k]*w%mod;
				f[i+j]=x+y;if(f[i+j]>=mod) f[i+j]-=mod;
				f[i+j+k]=x-y;if(f[i+j+k]<0) f[i+j+k]+=mod;
			}
		}
	}
	if(op==-1){
		int Inv=quickpow(N,mod-2);
		for(int i=0;i<N;i++) f[i]=f[i]*Inv%mod;
	}
}
poly operator *(poly A,poly B){
	int N=1,lim=0;int len=A.size()+B.size()-1;
	while(N<=(int)A.size()+(int)B.size()) N<<=1,lim++;
	A.resize(N),B.resize(N);
	for(int i=0;i<N;i++){
		ri[i]=(ri[i>>1]>>1)|((i&1)<<(lim-1));
	}
	NTT(A,N,1),NTT(B,N,1);
	for(int i=0;i<N;i++) A[i]=A[i]*B[i]%mod;
	NTT(A,N,-1);A.resize(len);
	return A;
}
int fac[1000005],inv[1000005];
void init(int n=1000000){
	fac[0]=1;for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
	inv[n]=quickpow(fac[n],mod-2);
	for(int i=n-1;~i;i--) inv[i]=inv[i+1]*(i+1)%mod;
}
int C(int n,int m){
	return fac[n]*inv[m]%mod*inv[n-m]%mod;
}
int n,w[26];
int t[26];
poly f[26];
signed main(){
	freopen("sayya.in","r",stdin);
	freopen("sayya.out","w",stdout);
	init();
	int S=0;
	for(int i=0;i<26;i++){
		cin>>w[i];
		S+=w[i];
	}
	S%=mod;
	string T;cin>>T;int len=T.size();
	cin>>n;
	int ti=1;
	for(int i=0;i<len;i++){
		t[T[i]-'a']++;
		ti=ti*w[T[i]-'a']%mod;
	}
	for(int c=0;c<26;c++){
		if(!t[c]) continue;
		f[c].resize(n+1-len);
		for(int i=0;i<=n-len;i++){
			f[c][i]=quickpow((S-w[c]),i)*C(i+t[c]-1,t[c]-1)%mod;
		}
	}
	poly ans;ans.resize(n+1-len);
	ans[0]=1;
	for(int c=0;c<26;c++){
		if(t[c]) ans=ans*f[c];
		ans.resize(n+1-len);
	}
	for(int i=1;i<len;i++){
		cout<<0<<'\n';
	}
	int sum=0;
	for(int i=0;i<=n-len;i++){
		sum=sum*S+ans[i];
		sum%=mod; 
		cout<<sum*ti%mod*quickpow(quickpow(S,i+len),mod-2)%mod<<'\n';
	}
}
