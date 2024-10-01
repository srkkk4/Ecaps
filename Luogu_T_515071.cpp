#include <bits/stdc++.h>
using namespace std;
int n;
string a,b;
int len;
int main(){
    cin>>n;
    cin>>a;
    len=a.length();
    int ans=0;
    for (int i=1;i<=n;i++){
        cin>>b;
        int res=0;
        for (int i=0;i<=len-1;i++){
            if (a[i]==b[i]) res++;
        }
        if (res>=(len+1)/2){
            ans++;
        }
    }
    cout<<ans<<endl;
    if (!ans) cout<<"Good job!\n";
    else cout<<"Make persistent efforts.\n";
    return 0;
}