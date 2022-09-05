#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
set<ll> vis;
ll s, t;
int main() {
	cin >> s >> t;
	if(s == t) {
		cout << 0;
		return 0;
	}
	queue<pair<ll,string>> q;
	if(s > t) {
		q.push({1,"/"});
	}
	else q.push({s, ""});
	while(!q.empty()) {
		auto cur = q.front(); q.pop();
		ll num = cur.first;
		string s = cur.second;
		if(num > t) continue;
		if(num == t) {
			cout << s;
			return 0;
		}
		if(vis.find(num * num) == vis.end()) {
			vis.insert(num * num);
			q.push({num*num, s + '*'});
		}
		if(vis.find(num + num) == vis.end()) {
			vis.insert(num + num);
			q.push({num+num, s + '+'});
		}
	}
	cout << -1;
}
