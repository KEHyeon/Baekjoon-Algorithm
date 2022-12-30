#include <bits/stdc++.h>
using namespace std;

int v, e, ans, cnt;
tuple<int,int,int> edge[100001];
vector<int> p(10001, -1);
int find(int cur) {
    if(p[cur] == -1) return cur;
    return p[cur] = find(p[cur]);;
}

bool isGroup(int a, int b) {
    a = find(a); b = find(b);
    if(a == b) return 1;
    if(a < b) p[a] = b;
    else p[a] = b;
    return 0;
}

int main() {
    cin >> v >> e;
    for(int i = 0; i < e; i++) {
        int a, b, c; cin >> a >> b >> c;
        edge[i] = {c, a, b};
    }
    sort(edge, edge + e);
    for(int i = 0; i < e; i++){
        int cost, a, b;
        tie(cost, a, b) = edge[i];
        if(!isGroup(a, b)) {
            ans += cost;
            cnt++;
        }
        if(cnt == v - 1) break;
    }
    cout << ans;
}