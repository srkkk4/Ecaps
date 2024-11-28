#include <bits/stdc++.h>
using namespace std;
string a,b;
int main(){
    freopen("orz.in","r",stdin);
    freopen("orz.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>a>>b;
    cout<<"0 \n";
    for (int i=1;i<=32;i++){
        cout<<"& "<<i<<" 0 1\n";
        cout<<">> 0 0 1\n";
    }
    for (int i=1;i<=32;i++){
        cout<<"+ "<<i<<" "<<i<<" "<<i<<endl;
        cout<<"- "<<i<<" "<<i<<" 1\n";
    }
    cout<<"= 0 0\n";
    for (int i=1;i<=32;i++){
        cout<<"+ "<<i<<" "<<i<<" "<<i-1<<endl;
        for (int j=33;j<=64;j++){
            cout<<"& "<<j<<" 0 1\n";
            cout<<">> 0 0 1\n";
        }
        for (int j=65;j<=96;j++){
            cout<<"& "<<j<<" "<<i<<" 1\n";
            cout<<">> "<<i<<" 0 1\n";
        }
    }
    return 0;
}