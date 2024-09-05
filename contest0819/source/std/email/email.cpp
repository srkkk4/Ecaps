#include<bits/stdc++.h>
using namespace std;

int const N = 1e5 + 5;
stack <int> st;
list <int> lst; 
int d[N], vis[N];
int main()
{
	freopen("email.in","r",stdin);
	freopen("email.out","w",stdout);
	int t;
	cin >> t;
	while(t--){
		int m, n, k;
		cin >> m >> n >> k;
		while(!st.empty()) st.pop();
		lst.clear();
		memset(vis, 0, sizeof(vis));//多组数据要清空 
		for(int i = 1; i <= n; ++i){
			cin >> d[i];
			vis[d[i]]++;//用桶记录每个文件夹下有多少个邮件 
		} 
      for(int i = 1; i <= k; i++){
			lst.push_back(d[i]);//先将邮件屏幕铺满
		}
		int j = k + 1;//j表示没归邮件的第一个 
		for(int i = 1; i <= m - k + 1; ++i){//枚举邮件夹屏幕开头的位置（原来这里写错了） 
			list<int>::iterator it, tmp;
			for(it = lst.begin(); it != lst.end();){//能归就归，清一遍list 
				tmp = it;
				++it; //不然清掉之后会导致循环不知道在哪 
				if(*tmp >= i && *tmp <= i + k - 1){//在邮件夹范围內 
					lst.erase(tmp);
					vis[*tmp]--;//邮件个数减1 
				}
			}
			while(j <= n && vis[i]){//下移 ，假如邮件夹已经没有邮件归这个了就等下一次for循环 
				if(lst.size() == k){//满了 
					st.push(lst.front());//压入栈中 
					lst.pop_front();
				}
				if(!(d[j] >= i && d[j] <= i + k - 1)) //不能再归，压入list 
					lst.push_back(d[j]);
				else
					vis[d[j]]--;//邮件个数减1 
				j++;
			}
			if(j > n){//栈下落 
				while(lst.size() < k && st.size() > 0){//有空下落 
					if(!(st.top() >= i && st.top() <= i + k - 1))//不能再归，压入list 
						lst.push_back(st.top());
					else
						vis[st.top()]--;//邮件个数减1
					st.pop();//栈中邮件弹出 
				}
			}
		}
		if(lst.size()) cout << "NO" << endl;//还有邮件没归 
		else cout << "YES" << endl;
	}
	return 0;
} 
