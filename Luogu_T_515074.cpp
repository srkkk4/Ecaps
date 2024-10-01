#include <bits/stdc++.h>
using namespace std;
int q;
struct NUM{
    int upd;
    long long num;
};
map <int,NUM> m;
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>q;
    int dt=0;
    while (q--){
        long long tpye,x,y;
        cin>>tpye;
        if (tpye==1){
            cin>>x>>y;
            if (m[x].upd==dt) m[x].num+=y;
            else {
                if (m[x].num==0) m[x].num=y;
                else m[x].num=1+y;
                m[x].upd=dt;
            }
        } else if (tpye==2){
            cin>>x>>y;
            if (m[x].upd==dt) m[x].num=max(0ll,m[x].num-y);
            else {
                if (m[x].num==0) m[x].num=0;
                else m[x].num=max(0ll,1-y);
                m[x].upd=dt;
            }
        } else if (tpye==3){
            dt++;
        } else {
            cin>>x;
            if (m[x].upd<dt&&m[x].num!=0) cout<<1<<endl;
            else cout<<m[x].num<<endl;
        }
    }
    return 0;
}