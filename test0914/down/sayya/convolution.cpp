#include<bits/stdc++.h>
using namespace std;
const int mod=998244353; 
#define int long long
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

signed main(){
	
	vector<int> A,B;
	A={1,1},B={1,1};
	vector<int> C=A*B;
	for(int u:C) cout<<u<<' ';
	
	return 0;
}
