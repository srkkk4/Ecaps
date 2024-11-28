#include <bits/stdc++.h>
using namespace std;
int main(){
    int cnt=0;
    // system("cd test1109");
    // system("cd polaris");
    while (1){
        cnt++;
        cout<<"#testcase"<<cnt<<":";
        system("./maker.exe");
        system("./pai.exe");
        system("./1.exe");
        if (!system("diff -Z -b pai.out polaris.out > error.log")){
            cout<<"AC\n";
        } else {
            cout<<"WA\n";
            break;
        }
    }
    return 0;
}