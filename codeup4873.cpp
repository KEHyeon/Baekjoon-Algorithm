#include <bits/stdc++.h>
using namespace std;
int n;
string str[1001];
vector<vector<int>> adj;

void getEulerCircuit(int node, vector<int> &circuit)
{
    for (int i = 0; i < adj[node].size(); ++i) {
        while (adj[node][i] > 0) {
            adj[node][i]--;
            adj[i][node]--; //  단방향 그래프의 경우 이 코드를 지워준다.
            getEulerCircuit(i, circuit);
        }
    }
    circuit.push_back(node);
}
int main() {
}