#include <bits/stdc++.h>
using namespace std;
pair<int,int> cafe[100000];
int n;
bool cmp(pair<int,int> a, pair<int,int> b) {
    return a > b;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tc; cin >> tc;
    while(tc--) {
        cin >> n;
        for(int i = 0; i < n; i++) {
            int a, b; cin >> a >> b;
            cafe[i] = {a, b};
        }
        sort(cafe, cafe + n);
        for(int i = 0; i < n - 1; i++) {
            if(cafe[i].first == cafe[i + 1].first && (cafe[i - 1].second > cafe[i].second)) {
                int e = i + 1;
                while(e < n && cafe[i].first == cafe[e].first) {
                    e++;
                }
                sort(cafe + i, cafe + e, cmp);
                i = e - 1;
            }
        }
        int m; cin >> m;
        while(m--) {
            int x; cin >> x;
            cout << cafe[x - 1].first << " " << cafe[x - 1].second << "\n";
        }
    }
}