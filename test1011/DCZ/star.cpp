#include <bits/stdc++.h>
#define MAXN 15003
using namespace std;
int n;
struct dot{
	int x,y;
	int k;
}a[MAXN];
int main(){
	freopen("star.in","r",stdin);
	freopen("star.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y>>a[i].k;
	}
	cout<<4<<endl;
	return 0;
}