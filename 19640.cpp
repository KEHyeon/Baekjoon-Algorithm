#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <string>

using namespace std;


// N (1 ≤ N ≤ 10^5)
// M (2 ≤ M ≤ 10^5)
// K (0 ≤ K ≤ N − 1)
// Di (0 ≤ Di ≤ 36,500)
// Hi (0 ≤ Hi ≤ 10^8)

int n, m, k;
int leader[100000];
pair<int, int> worker[100000];
priority_queue<pair<pair<int,int>, int>> pq;



int main() {
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++) {
        int d, h; cin >> d >> h;
        worker[i] = {d, h};
    }
    

    for(int i = 0; i < m && i < n; i++) {
        leader[i] = i;
        pq.push(make_pair(worker[i], -i));
    }
    
    int cnt = 0;
    while(1) {
        cnt++;
        pair<pair<int,int>, int> a = pq.top();
        pq.pop();
        int line = -a.second;
        if (leader[line] == k) {
            cout << cnt - 1 << "\n";
            return 0;
        }
        int newLeader = leader[line] + m;
        if (newLeader >= n) continue;
        leader[line] = newLeader;
        pq.push(make_pair(worker[newLeader], -line));
    }
}