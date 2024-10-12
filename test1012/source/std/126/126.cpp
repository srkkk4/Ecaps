#include <cstdio>
using namespace std;
typedef long long LL;
const int N=300005,p=1000000007;
int H[N],hq[N],hh[N],i,j,k,n,m,x,an;
char c;
inline char getc(){
 #define VV 10000000
 static char s[VV],*l=s,*r=s;
 if (l==r) l=s,r=s+fread(s,1,VV,stdin);
 return *l++;
}
int read(){
	int z=0; do c=getc(); while (c<'0'||c>'9');
	while (c>='0'&&c<='9') z*=10,z+=c-'0',c=getc();
	return z;
}
int main(){
	freopen("126.in","r",stdin);
	freopen("126.out","w",stdout);
	 n=read();
	 for (i=1;i<=n;i++) H[i]=(H[i-1]+read())%p,hq[i]=(hq[i-1]+H[i])%p;
	 for (i=n;i;i--) hh[i]=(hh[i+1]+H[i])%p;
	 for (i=1;i<=n;i++)
	 x=read(),an=((LL)x*(hh[i]-hq[n-i])+an)%p;
	 printf("%d\n",(an+p)%p);
	 return 0; 
}
