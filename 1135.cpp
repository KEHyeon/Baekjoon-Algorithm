#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
using namespace std;
int n;
vector<int> child[50];
int dfs(int cur) {
    if(child[cur].size() == 0) return 0;
    vector<int> v;
    for(int nxt : child[cur]) {
        v.push_back(dfs(nxt));
    }
    int ret = 0;
    int len = child[cur].size();
    sort(v.begin(), v.end());
    for(int i : v) {
        ret = max(ret, i + len--);
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        int pe; cin >> pe;
        if(pe == -1) continue;
        child[pe].push_back(i);
    }
    cout << dfs(0);
}