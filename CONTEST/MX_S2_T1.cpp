#include <bits/stdc++.h>
#define MAXN 1000003
using namespace std;
int k;
char a[MAXN];
int cnt[30];
int main(){
    cin>>k;
    cin>>a+1;
    int len=strlen(a+1);
    // cout<<len<<endl;
    for (int x=1;x<=len;x++){
        if (!(len%x)){
            // cout<<"x:"<<x<<endl;
            int res=0;
            for (int j=0;j<=x-1;j++){
                for (int i=1;i<=len;i+=x){
                    // cout<<i+j<<endl;
                    cnt[a[i+j]-'a'+1]++;
                }
                int mx=0;
                for (int i=1;i<=26;i++){
                    mx=max(mx,cnt[i]);
                    cnt[i]=0;
                }
                res+=len/x-mx;
            }
            if (res<=k){
                cout<<x<<endl;
                break;
            }
        }
    }
    return 0;
}