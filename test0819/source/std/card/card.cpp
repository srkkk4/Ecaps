
#include<cstdio>
#define fo(i,a,b) for(int i=a;i<=b;i++)
using namespace std;

const int maxn=2e5+5;

int n,a[maxn],num[maxn];

int ans,cov[maxn];
void ADD(int x)
{
	if (x<=0) return;
	if (++cov[x]==1) ans++;
}
void DEC(int x)
{
	if (x<=0) return;
	if (--cov[x]==0) ans--;
}

int m;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d %d",&n,&m);
	fo(i,1,n)
	{
		scanf("%d",&a[i]);
		num[a[i]]++;
		ADD(a[i]-num[a[i]]+1);
	}
	
	while (m--)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		
		DEC(a[x]-num[a[x]]+1);
		num[a[x]]--;
		num[y]++;
		ADD(y-num[y]+1);
		a[x]=y;
		
		printf("%d\n",n-ans);
	}
}
