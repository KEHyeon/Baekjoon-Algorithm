#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
using namespace std;
int n, k;
int dist[200001];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    queue<int> Q; Q.push(n);
    memset(dist, -1, sizeof(dist));
    dist[n] = 0;
    while(!Q.empty()) {
        int cur = Q.front(); Q.pop();
        if(cur + 1 <= 200000 && dist[cur + 1] == -1) {
            dist[cur + 1] = dist[cur] + 1; Q.push(cur + 1);
        }
        if(cur - 1 >= 0 && dist[cur - 1] == -1) {
            dist[cur - 1] = dist[cur] + 1; Q.push(cur - 1);
        }
        if(cur * 2 <= 200000 && dist[cur * 2] == - 1) {
            dist[cur * 2] = dist[cur] + 1; Q.push((cur * 2));
        }
    }
    int c = k;
    stack<int> ans; ans.push(c);
    while(dist[c] != 0) {
        if(c - 1 >= 0 && dist[c - 1] + 1 == dist[c]) {
            c--;
            ans.push(c);
        }
        else if(dist[c + 1] + 1 == dist[c]) {
            c++;
            ans.push(c);
        }
        else if(c % 2 == 0 && dist[c / 2] + 1 == dist[c]) {
            c /= 2;
            ans.push(c);
        }
    }
    cout << ans.size() - 1 << '\n';
    while(!ans.empty()) {
        cout << ans.top() << " ";
        ans.pop();
    }
}