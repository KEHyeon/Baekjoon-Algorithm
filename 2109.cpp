#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
using namespace std;
int n, ans;
bool day[10001];
pii task[10000];
bool compare(pii a, pii b) {return a > b;};
int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        task[i] = {a, b};
    }
    sort(task, task + n, compare);
    for(int i = 0; i < n; i++) {
        int cost = task[i].X;
        int deadLine = task[i].Y;
        while(deadLine >= 1 && day[deadLine]) {deadLine--;};
        if(deadLine == 0) continue;
        day[deadLine] = 1;
        ans += cost;
    }
    cout << ans;
}