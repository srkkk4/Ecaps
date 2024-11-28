#include <bits/stdc++.h>
#define MAXN 100003
using namespace std;
int c;
int T;
int a[MAXN];
int v[10];
int q[MAXN],cnt,sum,sum2;
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>c;
    cin>>T;
    while (T--){
        string num; cin>>num;
        int len=num.length();
        for (int i=0;i<=len-1;i++) a[i+1]=int(num[i]-'0');
        for (int i=1;i<=9;i++) cin>>v[i];
        cnt=sum=sum2=0;
        for (int i=1;i<=len;i++){
            if (sum*9+a[i]<v[a[i]]){
                sum*=10; sum+=a[i]; sum2+=v[a[i]];
                q[++cnt]=i;
            } else {
                // cout<<"in\n";
                bool ok=0;
                int tmp=sum,tmp2=sum2,tmp3,tmp4;
                tmp/=10; tmp2-=v[a[q[cnt]]];
                while (cnt&&tmp2+v[a[i]]-(tmp*10+a[i])>sum2-sum){
                    ok=1;
                    cnt--;
                    tmp3=tmp; tmp4=tmp2;
                    tmp/=10; tmp2-=v[a[q[cnt]]];
                }
                if (ok){
                    sum=tmp3*10+a[i]; sum2=tmp4+v[a[i]];
                    q[++cnt]=i;
                }
            }
            // cout<<sum<<" "<<sum2<<endl;
        }
        long long ans=sum;
        for (int i=1;i<=cnt;i++) a[q[i]]=0;
        for (int i=1;i<=len;i++){
            if (a[i]) ans+=v[a[i]];
        }
        cout<<ans<<endl;
    }
    return 0;
}