#include <bits/stdc++.h>
#define MAXN 100003
using namespace std;
int c;
int T;
struct A{
    int val;
    int real;
    int id;
}a[MAXN];
bool cmp(A x,A y){
    if (x.val==y.val){
        if (x.id<y.id) return x.real<y.real;
        else return x.real>y.real;
    } else return x.val<y.val;
}
int v[10];
bool cmp2(A x,A y){
    return x.id<y.id;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>c;
    cin>>T;
    while (T--){
        string num; cin>>num;
        int len=num.length();
        for (int i=0;i<=len-1;i++) {a[i+1].real=int(num[i]-'0'); a[i+1].id=i+1;}
        for (int i=1;i<=9;i++) cin>>v[i];
        for (int i=1;i<=len;i++) a[i].val=v[a[i].real];
        sort(a+1,a+1+len,cmp);
        long long ans=0;
        int i;
        for (i=1;i<=len-7;i++){
            ans+=a[i].val;
        }
        for (;i<=len;i++){
        // cerr<<"ok\n";
            int tmp=a[i].val;
            if (i!=len) sort(a+i+1,a+1+len,cmp2);
            int tmp2=0;
            // for (int j=i+1;j<=len;j++) cout<<a[j].real;
            // cout<<endl;
            for (int j=i+1;j<=len;j++){
                tmp2*=10; tmp2+=a[j].real;
            }
            sort(a+i,a+1+len,cmp2);
            int tmp3=0;
            for (int j=i;j<=len;j++){
                tmp3*=10; tmp3+=a[j].real;
            }
            sort(a+i,a+1+len,cmp);
            cout<<">:"<<tmp<<" "<<tmp2<<" "<<tmp3<<endl;
            if (tmp+tmp2<tmp3){
                ans+=tmp;
            }
            else {
                ans+=tmp3;
                break;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}