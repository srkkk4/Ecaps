#include <bits/stdc++.h>
using namespace std;
int a,b;
int main(){
    cin>>a>>b;
    if ((a==1&&b==1)||(a==0&&b==0)) cout<<"Invalid\n";
    else {
        if (a==1) cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}