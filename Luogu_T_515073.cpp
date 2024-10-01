#include <bits/stdc++.h>
#define MAXN 3000003
using namespace std;
int n;
struct solu{
    int x; int y;
};
struct ans{
    int x; int y; int z;
};
bool del[MAXN];
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++){
        string a;
        cin>>a;
        int len=a.length();
        queue <int> q;
        queue <solu> q2;
        queue <ans> q3;
        memset(del,0,sizeof del);
        for (int j=0;j<=len-1;j++){
            if (a[j]=='A') q.push(j);
            if (a[j]=='P'){
                if (!q.empty()){
                    q2.push({q.front(),j});
                    q.pop();
                }
            }
            if (a[j]=='C'){
                if (!q2.empty()){
                    q3.push({q2.front().x,q2.front().y,j});
                    del[q3.back().x]=del[q3.back().y]=del[q3.back().z]=1;
                    q2.pop();
                }
            }
        }
        int is_p=1;
        for (int j=0;j<=len-1;j++){
            if (!del[j]){
                is_p=0;
                cout<<a[j];
            }
        }
        if (is_p) cout<<"Perfect";
        cout<<endl;
        cout<<q3.size()<<endl;
        while (!q3.empty()){
            cout<<q3.front().x+1<<" "<<q3.front().y+1<<" "<<q3.front().z+1<<endl;
            q3.pop();
        }
    }
    return 0;
}