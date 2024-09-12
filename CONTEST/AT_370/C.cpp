#include <bits/stdc++.h>
using namespace std;
char a[103],b[103];
int main(){
    cin>>a;
    cin>>b;
    int len=strlen(a);
    int cnt=0;
    for (int i=0;i<len;i++){
        if (a[i]!=b[i]) cnt++;
    }
    cout<<cnt<<endl;
    for (int i=0;i<len;i++){
        if (a[i]>b[i]){
            a[i]=b[i];
            for (int i=0;i<len;i++) cout<<a[i];
            cout<<endl;
        }
    }
    for (int i=len-1;i>=0;i--){
        if (a[i]<b[i]){
            a[i]=b[i];
            for (int i=0;i<len;i++) cout<<a[i];
            cout<<endl;
        }
    }
    return 0;
}