#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
using namespace std;
int n, ans;
vector<int> arr;
int arrow[1000001];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x; cin >> x; arr.push_back(x);
    }
    for(int i : arr) {
        if(arrow[i + 1]) {
            arrow[i + 1]--;
            arrow[i]++;
        } else {
            arrow[i]++;
            ans++;
        }
    }
    cout << ans;
}