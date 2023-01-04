#include <bits/stdc++.h>
using namespace std;
int n, ans = 0;
bool comp(int a, int b) {
    return a > b;
}
vector<int> alp(26, 0);
int main() {
	cin >> n;
    while(n--) {
        string str; cin >> str;
        int len = str.size();
        for(int i = 0; i < len; i++) {
            alp[str[i]-'A'] += pow(10, len-i-1);
        };
    }
    sort(alp.begin(), alp.end(), comp);
    int num = 9;
    for(int i : alp) {
        ans += (i * num--);
    }
    cout << ans;
}
