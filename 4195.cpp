#include <bits/stdc++.h>
using namespace std;
int tc, n;
map<string, string> m;
void swap(string *a, string *b) {
	string temp = *a;
	*a = *b;
	*b = temp;
}
string Find(string node) {
	if(m[node][0] == ' ') return node;
	m[node] = Find(m[node]);
	return m[node];
}
int Merge(string a, string b) {
	string apar = Find(a);
	string bpar = Find(b);
	if(apar == bpar) {
		return m[apar].size();
	}
	if(m[apar].size() < m[bpar].size())  swap(&apar, &bpar);
	m[apar] += m[bpar];
	m[bpar] = apar;
	return m[apar].size();
}
int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	cin >> tc;
	while(tc--) {
		m.clear();
		cin >> n;
		for(int i = 0; i < n; i++) {
			string a, b; cin >> a >> b;
			if(m.find(a) == m.end()) m.insert({a, " "});
			if(m.find(b) == m.end()) m.insert({b, " "});
			cout << Merge(a, b) << "\n";
		}
		
	}
}
