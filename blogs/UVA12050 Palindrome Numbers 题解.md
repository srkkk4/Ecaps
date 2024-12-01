AT abc363d 过来的，发现是个双倍经验。

## 题意
求第 $i$ 小的回文数（不包括数字 $0$）。

## 思路

注意到两回文数在位数相等的情况下，只需比较前半部分的大小。具体地，有 $514 > 114$ ，则有 $51415 > 11411$ 和 $514415 > 114411$ 。

依照次结论，可以得出如下的回文数：

一位：$1,2,3,...,9$ 共 9 个

两位：$11,22,33,...,99$ 共 9 个

三位：$101,111,121,...,999$ 共 90 个

四位：$1001,1111,1221,...,9999$ 共 90 个

以此类推。

显然，我们只要算出前半部分，再整体翻转即可。具体细节不多赘述。

## 代码


```cpp
#include <bits/stdc++.h>
using namespace std;
long long n;
long long pow1(long long x,int y){
    long long res=1;
    while (y){
        res*=x;
        y--;
    }
    return res;
}
int main(){
    cin>>n;
    while (n!=0){
        long long k=18,w=1;
        while (n>k){
            n-=k;
            k*=10;
            w+=2;
        }
        if (n<=k/2){
            long long p=pow1(10,(w-1)/2)-1+n;
            cout<<p;
            p/=10;
            while (p){
                cout<<p%10;
                p/=10;
            }
            cout<<endl;
        } else {
            w++;
            long long p=pow1(10,(w-1)/2)-1+(n-k/2);
            cout<<p;
            while (p){
                cout<<p%10;
                p/=10;
            }
            cout<<endl;
        }
        cin>>n;
    }
    return 0;
}
```

另外，在答案涉及长整数时，请谨慎使用默认 pow() 函数。（赛时因此吃了发罚时）