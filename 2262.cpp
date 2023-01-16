#include <bits/stdc++.h>
using namespace std;
int n, ans;
vector<int> graph;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        graph.push_back(x);
    }
    while(graph.size() != 1) {
        int MAX = -1;
        int idx;
        for(int i = 0; i < graph.size(); i++) {
            if(graph[i] > MAX) {
                MAX = graph[i];
                idx = i;
            }
        }
        if(idx - 1 == -1) ans += (graph[idx] - graph[idx + 1]);
        else if(idx + 1 == graph.size()) ans += (graph[idx] - graph[idx - 1]);
        else ans += (graph[idx] - max(graph[idx - 1], graph[idx + 1]));
        graph.erase(graph.begin() + idx);
    }
    cout << ans;
}