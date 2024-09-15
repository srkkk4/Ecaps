//Trie: https://www.luogu.com.cn/article/99w157ny
#include <bits/stdc++.h>
#define MAXN 20003
using namespace std;
int n;
struct node{
    string str;
    int len;
}s[MAXN];
bool cmp(node a,node b) {return a.len<b.len;}
map <string,int> m;
int main(){
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>s[i].str;
        s[i].len=s[i].str.length();
    }
    for (int i=1;i<=n;i++){
        map <string,bool> m2;
        for (int len=1;len<=s[i].len;len++){
            for (int j=0;j<=s[i].len-len;j++){
                string tmp;
                for (int k=j;k<=j+len-1;k++){
                    tmp+=s[i].str[k];
                }
                if (!m2[tmp]) {m[tmp]++; m2[tmp]=1;}
            }
        }
    }
    int ans=0;
    for (int i=1;i<=n;i++){
        ans+=m[s[i].str]-1;
    }
    cout<<ans<<endl;
    return 0;
}