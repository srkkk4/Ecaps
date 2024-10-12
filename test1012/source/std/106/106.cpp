#include<bits/stdc++.h>
#define rep(i,a,b) for (int i = (a); i <= (b); ++i)
#define drep(i,a,b) for (int i = (a); i >= (b); --i)
#define grep(i,u) for (int i = head[u],v = e[i].v; i; v = e[i = e[i].nxt].v)
#define il inline
#define LL long long
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define fi first
#define se second
#define mp make_pair
using namespace std;
il LL read() {
LL x = 0,y = 1; char ch = getchar(); while (!isdigit(ch)) {if (ch == '-') y = -y ; ch = getchar();}
while (isdigit(ch)) {x = x*10+ch-'0'; ch = getchar();} return x*y; }
namespace qiqi {
const int N = 2005,P = 998244353; int n,m,c[N][N],dp[N][N][20],f[N],g[N]; char s
[10];
il int mod(int x) {return x+((x>>31)&P);} il void add(int &x,int y) {x = mod(x+y -P);}
void main() {
n = read(); rep(i,0,n) {c[i][0] = 1; rep(j,1,i) c[i][j] = (c[i-1][j-1]+c[i-1
][j])%P;}
scanf("%s",s+1); m = strlen(s+1); rep(i,1,m) dp[1][1][s[i]-'0'+6] = 1;
rep(i,1,n-1) {
scanf("%s",s+1); int m = strlen(s+1); rep(k,1,m) {
int a = s[k]-'0',b = (a+2)%3,c = (a+1)%3; rep(j,1,i) {
add(dp[i+1][j+1][a],mod(mod(dp[i][j][b]+dp[i][j][b+3]-P)+dp[i][j
][b+6]-P));
add(dp[i+1][j][a+3],dp[i][j][c+6]); add(dp[i+1][j+1][a+6],dp[i][
j][c+3]);
add(dp[i+1][j][c],dp[i][j][c]); rep(p,0,2) add(dp[i+1][j][a+p*3
],dp[i][j][a+p*3]);
} } }
rep(i,1,n) {int x = 0; rep(j,0,8) add(x,dp[n][i][j]); printf("%d\n",x);} } }
int main() {
	freopen("106.in","r",stdin);
	freopen("106.out","w",stdout); 
qiqi::main(); return 0; }
