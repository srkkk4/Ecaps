#include<bits/stdc++.h>
using namespace std;
const int maxn=220000;
struct data
{
	long long id,x;
};
bool cmp(string a,string b)
{
	if (a.size()!=b.size()) return a.size()<b.size();
	return a<b;
}
vector<long long> Has[maxn];
vector<data> has[maxn];
char s[15];
long long hash1=19260817,hash2=19660813,M=218357;
string a[200005];
long long n,q,kk1,kk2,k1,k2,e1[maxn],e2[maxn],ans;
int main()
{
	freopen("bug.in","r",stdin);
	freopen("bug.out","w",stdout);
	cin>>n;
	//std::ios::sync_with_stdio(false);
	for (int i=1;i<=n;i++) 
	{
		scanf("%s",s);
		a[i]=s;
	}
	sort(a+1,a+1+n,cmp);
	for (int i=1;i<=n;i++)
	{
		string t=" "+a[i];
		for (int x=1;x<=a[i].size();x++)
	 	{
	 		e1[x]=(e1[x-1]*131%hash1+t[x])%hash1;
	 		e2[x]=(e2[x-1]*131%hash2+t[x])%hash2;
	 	}
	 	long long kk1=1,kk2=1;
	 	for (int x=1;x<=a[i].size();x++)
	 	{
	 		long long p=x;
			kk1=kk1*131%hash1;
			kk2=kk2*131%hash2; 
	 		while (p<=a[i].size())
	 		{
				long long c1=(e1[p]-(e1[p-x]*kk1)%hash1+hash1)%hash1;
	 			long long c2=(e2[p]-(e2[p-x]*kk2)%hash2+hash2)%hash2;
				int p1=0,k=c1%M,p2=0;//模运算很慢，对于一些重复模的地方要取出来，尤其写hash，容易超时， 
				data tmp;
			    tmp.x=c2%hash2,tmp.id=i;
	 			if (has[k].size()>0)
				{
					int len=has[k].size();
					for (int j=0;j<len;j++)
					{
						if (has[k][j].x==c2&&has[k][j].id==i)  {p1=1;break;
						}//这个子串出现过，且在这个串中重复出现，不做操作;
						else if (has[k][j].x==c2) {has[k][j].id=i;break;
						}//这个子串出现过，但不在这个串中重复出现，更新id即可 
					}	
			    } 
			    else 
			    {
			    	has[k].push_back(tmp);
                    //这个子串从未出现过，要把它的哈希值和id(第几个字符串)push_back进去
			    }
				if (p1==0)
				{
					if (Has[k].size()>0)
			 	   	{
						for (int j=0;j<Has[k].size();j++)
						{
					 		if (Has[k][j]==c2) 
							 {
							 	ans++;
							 	if (x==a[i].size()) ans++;
							 }
						}
			       	}    
				}
			    p++;
	    	}
	 	}
	 	Has[e1[a[i].size()]%M].push_back(e2[a[i].size()]%hash2);
	}
	cout<<ans;
	return 0;
}
