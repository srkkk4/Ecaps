#include<bits/stdc++.h>
#define M 2005

using namespace std;
struct node{
	int x,id;
}s[M];
int A[M],B[M],L[M],R[M],pos[M];
bool cmp(node A,node B){
	return A.x>B.x;
} 
int main(){ 
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&A[i]);
		s[i].x=A[i];s[i].id=i;
	}
	int ans=A[1];
	sort(s+1,s+n+1,cmp); 
	for(int i=1;i<=n;i++)pos[s[i].id]=i; 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)L[j]=j-1,R[j]=j+1;
		R[0]=1,L[n+1]=n;
		int tot=0;
		int inside=0;
		for(int j=i,k;j<=n;j++){
			int x=pos[j];L[R[x]]=L[x];R[L[x]]=R[x];
			inside+=A[j];
			for(k=tot;k&&B[k]>A[j];k--)B[k+1]=B[k]; 
			B[k+1]=A[j];tot++;
			tot=min(tot,m); 
			
			int t=R[0];
			int tmp=inside;
			for(k=1;k<=tot&&t!=n+1;k++,t=R[t]){ 
				if(B[k]>=s[t].x)break;
				tmp+=s[t].x-B[k]; 
			} 
			if(ans<tmp)ans=tmp;
		}
	}
	printf("%d\n",ans);
	return 0; 
}
