#include <bits/stdc++.h>
#define MAXN 200003
#define inf 0x3f3f3f3f
#define pb push_back
using namespace std;
template<class T>void err(const T &x,const char c='\n') {cerr<<x<<c;}
template<class T,class ...Args>void err(const T &x,const Args &...args) {err(x,' '),err(args...);}
bool ST;
int n,m,l;
int q1[25],q2[15],q3[15],cnt1,cnt2,cnt3;
bool ED;
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m>>l;
    cnt1=n; cnt2=m; cnt3=l;
    for (int i=1;i<=n;i++){
        cin>>q1[i];
    }
    for (int i=1;i<=m;i++){
        cin>>q2[i];
    }
    for (int i=1;i<=l;i++){
        cin>>q3[i];
    }
    sort(q1+1,q1+1+cnt1);
    sort(q2+1,q2+1+cnt2);
    sort(q3+1,q3+1+cnt3);
    while (cnt1&&cnt2){
        int i=0;
        int j=cnt1;
        while (q3[i+1]<q1[cnt1]&&i+1<=cnt3) i++;
        while (q1[j-1]>q3[i]) j--;
        int tmp=q1[j]; q1[j]=inf; sort(q1+1,q1+1+cnt1); cnt1--;
        q3[++cnt3]=tmp; sort(q3+1,q3+1+cnt3);
        if (i>0){
            q1[++cnt1]=q3[i]; q3[i]=inf; sort(q3+1,q3+1+cnt3); cnt3--;
            sort(q1+1,q1+1+cnt1);
        }
        if (!cnt1) {cout<<"Aoki\n"; break;}

        for (int i=1;i<=cnt1;i++) cout<<q1[i]<<" "; cout<<'\n';
        for (int i=1;i<=cnt2;i++) cout<<q2[i]<<" "; cout<<'\n';
        for (int i=1;i<=cnt3;i++) cout<<q3[i]<<" "; cout<<'\n';
        cout<<'\n';

        i=0;
        j=cnt2;
        while (q3[i+1]<q2[cnt2]&&i+1<=cnt3) i++;
        while (q2[j-1]>q3[i]) j--;
        tmp=q2[j]; q2[j]=inf; sort(q2+1,q2+1+cnt2); cnt2--;
        q3[++cnt3]=tmp; sort(q3+1,q3+1+cnt3);
        if (i>0){
            q2[++cnt2]=q3[i]; q3[i]=inf; sort(q3+1,q3+1+cnt3); cnt3--;
            sort(q2+1,q2+1+cnt2);
        }
        if (!cnt2) {cout<<"Takahashi\n"; break;}

        for (int i=1;i<=cnt1;i++) cout<<q1[i]<<" "; cout<<'\n';
        for (int i=1;i<=cnt2;i++) cout<<q2[i]<<" "; cout<<'\n';
        for (int i=1;i<=cnt3;i++) cout<<q3[i]<<" "; cout<<'\n';
        cout<<'\n';
    }
    return 0;
}