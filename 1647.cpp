#include <bits/stdc++.h>
using namespace std;
int v, e;
tuple<int,int,int> edge[1000000];
vector<int> p(100001, -1);
int find(int cur) {
    if(p[cur] == -1) return cur;
    return p[cur] = find(p[cur]);
}
bool isGroup(int a, int b) {
    a = find(a); b = find(b);
    if(a == b) return 1;
    if(a > b) p[b] = a;
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
    int sum = 0, cnt = 0;
    for(int i = 0; i < e; i++) {
        int a, b, cost;
        tie(cost, a, b) = edge[i];
        if(isGroup(a, b)) continue;
        sum += cost;
        cnt ++;
        if(cnt == v - 2) break;
    }
    cout << sum;
}