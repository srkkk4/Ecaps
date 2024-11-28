#include <bits/stdc++.h>
#define MAXN 200003
#define pb push_back
using namespace std;
template<class T>void err(const T &x,const char c='\n') {cerr<<x<<c;}
template<class T,class ...Args>void err(const T &x,const Args &...args) {err(x,' '),err(args...);}
bool ST;
bool ED;
int main(){
    int cnt=0;
    system("g++ -std=c++14 -o public.exe public.cpp -O2");
    system("g++ -std=c++14 -o pubmaker.exe pubmaker.cpp -O2");
    // system("g++ -std=c++14 -o myprogram.exe Luogu_AT_arc_152_c.cpp -O2");
    // while (1){
    //     cnt++; cout<<"#testcase"<<cnt<<":";
    //     system("./pubmaker.exe > data.in");
    //     system("./public.exe < data.in > public.out");
    //     system("./myprogram.exe < data.in > myprogram.out");
    //     bool flag=1;
    //     while (system("diff -Z -b public.out myprogram.out > ERR.log")){
    //         cout<<"WA\n"; flag=0;
    //         cout<<"Run again?(y/n)";
    //         string s; cin>>s;
    //         if (s[0]!='y') return 0;
    //         system("g++ -std=c++14 -o myprogram.exe Luogu_AT_arc_152_c.cpp -O2");
    //         system("./myprogram.exe < data.in > myprogram.out");
    //         flag=1;
    //     }
    //     if (flag) cout<<"AC\n";
    // }
    while (cnt<=10){
        cnt++; cout<<"#testcase"<<cnt<<":";
        system("./pubmaker.exe > data.in");
        system("./public.exe < data.in > public.out");
    }
    return 0;
}