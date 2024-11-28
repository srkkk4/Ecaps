#include <bits/stdc++.h>
using namespace std;
int n,m,q;
map <long long,int> a;
int main(){
    cin>>n>>m>>q;
    long long ans=n*m;
    while (q--){
        int x,y;
        cin>>x>>y;
        if (!a[x*1000000ll+y]) {a[x*1000000ll+y]=1;ans--;}
        else {
            int tx=x,ty=y;
            x--;
            while (x>0&&a[(x)*1000000ll+y]) x--;
            if (x>0) {a[(x)*1000000ll+y]=1;ans--;}
            x=tx; y=ty;
            x++;
            while (x<n+1&&a[(x)*1000000ll+y]) x++;
            if (x<n+1) {a[(x)*1000000ll+y]=1;ans--;}
            x=tx; y=ty;
            y--;
            while (y>0&&a[x*1000000ll+(y)]) y--;
            if (y>0) {a[x*1000000ll+(y)]=1;ans--;}
            x=tx; y=ty;
            y++;
            while (y<m+1&&a[x*1000000ll+(y)]) y++;
            if (y<m+1) {a[x*1000000ll+(y)]=1;ans--;}
        }
    }
    std::cout<<ans<<endl;
    return 0;
}
/*
0 0 0 1 1
0 0 0 1 1
0 0 0 0 1
1 0 0 1 1
1 1 1 1 1
*/