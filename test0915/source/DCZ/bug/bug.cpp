#include <bits/stdc++.h>
#define MAXN 20003
using namespace std;
int n;
struct node{
    string str;
    int len;
}s[MAXN];
bool cmp(node a,node b) {return a.len<b.len;}
int cnt;
int main(){
    freopen("bug.in","r",stdin);
    freopen("bug.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>s[i].str;
        s[i].len=s[i].str.length();
    }
    sort(s+1,s+1+n,cmp);
    for (int i=1;i<=n;i++){
        for (int j=1;j<=i-1;j++){
            if (s[i].str==s[j].str){
                cnt+=2;
                continue;
            }
            int len1=s[i].len,len2=s[j].len;
            // cout<<len1<<" "<<len2<<endl;
            for (int k=0;k<len1-len2+1;k++){
                int ok=0;
                for (int l=0;l<=len2-1;l++){
                    if (s[i].str[k+l]!=s[j].str[l]){
                        ok=1;
                        break;
                    }
                }
                if (!ok){
                    cnt++;
                    break;
                }
            }
        }
    }
    std::cout<<cnt<<endl;
    return 0;
}