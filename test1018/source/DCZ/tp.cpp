#include <bits/stdc++.h>
#define MAXN 200003
using namespace std;
int T;
int n,m;
int a[MAXN];
struct P{
    int l;
    int r;
}p[MAXN];
int ton[MAXN];
bool check(int x){
    for (int i=1;i<=n-x+1;i++){
        bool flag=1;
        for (int j=1;j<=m;j++){
            for (int i=1;i<=n;i++) ton[i]=0;
            for (int k=p[j].l;k<=p[j].r;k++){
                if (k>=i&&k<=i+x-1) {k=i+x-1; continue;}
                ton[a[k]]++;
                if (ton[a[k]]==2) {flag=0; break;}
            }
            // if (!flag) break;
            // if (p[j].r<i||p[j].l>i+x-1){
            //     int k;
            //     for (k=p[j].l;k<=p[j].r;k++){
            //         ton[a[k]]++;
            //         if (ton[a[k]]==2) {flag=0; break;}
            //     }
            //     for (;k>=p[j].l;k--) ton[a[k]]--;
            // } else if (p[j].l<i&&p[j].r>=i&&p[j].r<i+x-1){
            //     int k;
            //     for (k=p[j].l;k<=i-1;k++){
            //         ton[a[k]]++;
            //         if (ton[a[k]]==2) {flag=0; break;}
            //     }
            //     for (;k>=p[j].l;k--) ton[a[k]]--;
            // } else if (p[j].r>i+x-1&&p[j].l<=i+x-1&&p[j].l>i){
            //     int k;
            //     for (k=p[j].r;k>=i+x;k--){
            //         ton[a[k]]++;
            //         if (ton[a[k]]==2) {flag=0; break;}
            //     }
            //     for (;k<=p[j].r;k++) ton[a[k]]--;
            // } else if (p[j].l<=i&&p[j].r>=i+x-1){
            //     int k;
            //     for (k=p[j].l;k<=i-1;k++){
            //         ton[a[k]]++;
            //         if (ton[a[k]]==2) {flag=0; break;}
            //     }
            //     if (!flag){
            //         for (;k>=p[j].l;k--) ton[a[k]]--;
            //     } else {
            //         for (k=i+x;k<=p[j].r;k++){
            //             ton[a[k]]++;
            //             if (ton[a[k]]==2) {flag=0; break;}
            //         }
            //         for (;k>=i+x;k--) ton[a[k]]--;
            //         for (k=i-1;k>=p[j].l;k--) ton[a[k]]--;
            //     }
            // }
        }
        if (flag) return true;
    }
    return false;
}
struct TMP{
    int val;
    int id;
    bool operator<(const TMP &B)const{
        return val<B.val;
    }
}tmp[MAXN];
int main(){
    freopen("tp.in","r",stdin);
    freopen("tp.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>T;
    while (T--){
        cin>>n;
        for (int i=1;i<=n;i++) {cin>>tmp[i].val; tmp[i].id=i;}
        sort(tmp+1,tmp+1+n);
        int last=0,cnt=0;
        for (int i=1;i<=n;i++){
            if (tmp[i].val!=last) {last=tmp[i].val; cnt++;}
            a[tmp[i].id]=cnt;
        }
        cin>>m;
        for (int i=1;i<=m;i++) cin>>p[i].l>>p[i].r;
        int l=0,r=n;
        while (l<r){
            int mid=(l+r)>>1;
            if (check(mid)) r=mid;
            else l=mid+1;
        }
        cout<<l<<endl;
    }
    return 0;
}
/*
1
7
1 1 2 1 3 3 5
3
1 4
4 5
2 4
*/
/*
5
7
1 1 2 1 3 3 5
3
1 4
4 5
2 4
5
10 1 6 14 1
2
4 5
2 4
4
5 7 5 6
5
2 2
1 3
2 4
3 3
3 4
7
2 2 2 7 8 2 2
3
4 4
4 4
5 5
1
123
1
1 1
*/