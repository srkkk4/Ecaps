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
		memset(vis, 0, sizeof(vis));//��������Ҫ��� 
		for(int i = 1; i <= n; ++i){
			cin >> d[i];
			vis[d[i]]++;//��Ͱ��¼ÿ���ļ������ж��ٸ��ʼ� 
		} 
      for(int i = 1; i <= k; i++){
			lst.push_back(d[i]);//�Ƚ��ʼ���Ļ����
		}
		int j = k + 1;//j��ʾû���ʼ��ĵ�һ�� 
		for(int i = 1; i <= m - k + 1; ++i){//ö���ʼ�����Ļ��ͷ��λ�ã�ԭ������д���ˣ� 
			list<int>::iterator it, tmp;
			for(it = lst.begin(); it != lst.end();){//�ܹ�͹飬��һ��list 
				tmp = it;
				++it; //��Ȼ���֮��ᵼ��ѭ����֪������ 
				if(*tmp >= i && *tmp <= i + k - 1){//���ʼ��з�Χ�� 
					lst.erase(tmp);
					vis[*tmp]--;//�ʼ�������1 
				}
			}
			while(j <= n && vis[i]){//���� �������ʼ����Ѿ�û���ʼ�������˾͵���һ��forѭ�� 
				if(lst.size() == k){//���� 
					st.push(lst.front());//ѹ��ջ�� 
					lst.pop_front();
				}
				if(!(d[j] >= i && d[j] <= i + k - 1)) //�����ٹ飬ѹ��list 
					lst.push_back(d[j]);
				else
					vis[d[j]]--;//�ʼ�������1 
				j++;
			}
			if(j > n){//ջ���� 
				while(lst.size() < k && st.size() > 0){//�п����� 
					if(!(st.top() >= i && st.top() <= i + k - 1))//�����ٹ飬ѹ��list 
						lst.push_back(st.top());
					else
						vis[st.top()]--;//�ʼ�������1
					st.pop();//ջ���ʼ����� 
				}
			}
		}
		if(lst.size()) cout << "NO" << endl;//�����ʼ�û�� 
		else cout << "YES" << endl;
	}
	return 0;
} 
