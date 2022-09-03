#include <bits/stdc++.h>
using namespace std;
int s, t;
bool vis[100000001];
int main() {
	cin >> s >> t;
	if(s == t) {
		cout << 0;
		return 0;
	}
	queue<pair<int,string>> q;
	q.push({s, ""});
	q.push({1, "/"});
	while(!q.empty()) {
		auto cur = q.front(); q.pop();
		int num = cur.first;
		string s = cur.second;
		if(num == t) {
			cout << s;
			return 0;
		}
		if(!vis[num * num] && num * num <= t) {
			vis[num * num] = 1;
			q.push({num*num, s + '*'});
		}
		if(!vis[num + num] && num + num <= t) {
			vis[num + num] = 1;
			q.push({num+num, s + '+'});
		}
	}
	cout << -1;
}
