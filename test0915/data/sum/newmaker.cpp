#include<bits/stdc++.h>
using namespace std;
#define M 200005
struct node{
	int x,id;
}s[M];
int A[M],B[M],L[M],R[M],pos[M];
ofstream infile,outfile;
int times=10;
mt19937 rng(time(0)); 
bool cmp(node A,node B){
	return A.x>B.x;
} 
void file(int tp)
{
	char inname[10],outname[11];
	infile.close();
	outfile.close();
	sprintf(inname,"sum%d.in",tp);
	sprintf(outname,"sum%d.out",tp);
	infile.open(inname);
	outfile.open(outname);
}  
 
#define num(a,b) (rng()%(b-a+1)+a)
 
void make(int tp)
{
	int n,m;
	if(tp==1)n=100,m=0;
	else if(tp==2)n=100,m=1;
	else if(tp==3 || tp==4)n=500,m=1;
	else if(tp==5 || tp==6)n=50,m=2;
	else if(tp==7 || tp==8)n=300,m=10;
	else if(tp==9)n=600,m=20;
	else n=2000,m=100;
	infile<<n<<" "<<m<<endl;
	for(int i=1;i<=n;i++)
	{
		A[i]=num(0,15000)-10000;
		infile<<A[i]<<" ";
	}
	for(int i=1;i<=n;i++){
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
	outfile<<ans;
}
 
int main()
{
	for(int tp=1;tp<=times;tp++)	
	{
		file(tp);
		make(tp);
	}
	return 0;
} 
