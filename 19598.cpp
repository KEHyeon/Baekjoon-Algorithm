#include <bits/stdc++.h>

using namespace std;
int n, ans;
vector<pair<int,int>> conf;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        int s, e; cin >> s >> e;
        conf.push_back({s, e});
    }
    sort(conf.begin(), conf.end());
    priority_queue<int, vector<int>, greater<int>> endTime;
    endTime.push(0);
    for(auto i : conf) {
        int s = i.first, e = i.second;;
        if(endTime.top() <= s) {
            endTime.pop();
            endTime.push(e);
            continue;
        }
        endTime.push(e);
        ans++;
    }
    cout << ans + 1;
}