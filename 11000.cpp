#include <bits/stdc++.h>
using namespace std;
long long n, ans;
vector<pair<long long,long long>> arr;
priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        long long s, t; cin >> s >> t;
        arr.push_back(make_pair(t, s));
    }
    sort(arr.begin(), arr.end());
    ans = 1;
    pq.push(arr[0]);
    for(int i = 1; i < n; i++) {
        if(!pq.empty() && arr[i].second < pq.top().first) {
            pq.push(arr[i]);
            if(pq.size() > ans) ans = pq.size();
        }
        else {
            if(pq.empty()) pq.push(arr[i]);
            else {
                pq.pop();
                pq.push(arr[i]);
            }

        }
    }
    cout << ans;
}