#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
using namespace std;
string a, b;
int main() {
    freopen("./input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> a >> b;
    int ans = b.size();
    int p = b.size() - 1;
    for(int i = a.size() - 1; i >= 0; i--) {
        if(a[i] == b[p]) {
            ans--;
            p--;
        }
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    if(a != b) cout << -1;
    else cout << ans;
}