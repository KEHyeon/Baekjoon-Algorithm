#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
using namespace std;
int n;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    priority_queue<int> maxq;
    priority_queue<int, vector<int>, greater<int>> minq;
    int x; cin >> x;
    maxq.push(x);
    cout << x << "\n";
    for(int i = 1; i < n; i++) {
        cin >> x;
        if(maxq.size() == minq.size()) {
            maxq.push(x);
        }
        else minq.push(x);
        if(maxq.top() > minq.top()) {
            int minTemp = minq.top(); minq.pop();
            int maxTemp = maxq.top(); maxq.pop();
            minq.push(maxTemp);
            maxq.push(minTemp);
        }
        cout << maxq.top() << '\n';
    }
}