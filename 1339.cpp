#include <bits/stdc++.h>
using namespace std;
int n; 
vector<string> str;
bool Comp(string a, string b) {
	if (a.length() != b.length()) {
		return a.length()
	} 
}
int main() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		string x; cin >> x;
		str.push_back(x);
	}
	sort(str.begin(), str.end());
	for(auto s : str) {
		cout << s << "\n";
	}
}
