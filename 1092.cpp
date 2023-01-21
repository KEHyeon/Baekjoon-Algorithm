#include <bits/stdc++.h>
using namespace std;
int n, m, ans;
vector<int> lim;
vector<int> box;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        lim.push_back(x);
    }
    cin >> m;
    for(int i = 0; i < m; i++) {
        int x; cin >> x;
        box.push_back(x);
    }
    sort(lim.begin(), lim.end());
    sort(box.begin(), box.end());
    if(lim[lim.size() - 1] < box[box.size() - 1]) {
        cout << -1;
        return 0;
    }
    while(box.size() > 0) {
        int bs = box.size() - 1;
        for(int i = n - 1; i >= 0; i--) {
            if(bs == -1) break;
            if(lim[i] >= box[bs]) {
                box.erase(box.begin() + bs);
                bs--;
                continue;
            }
            while(bs >= 0 && lim[i] < box[bs]) {bs--;};
            if(bs < 0) continue;
            else {
                box.erase(box.begin() + bs);
                bs--;
                continue;
            }
        }
        ans++;
    }
    cout << ans;
}