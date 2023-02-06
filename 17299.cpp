#include <bits/stdc++.h>
#define pii pair<int,int>
#define X first
#define Y second
using namespace std;
int n, f[1000001];
int ans[1000000];
stack<pair<int,int>> st;
queue<int> num;
int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        f[x]++;
        num.push(x);
    }
    for(int i = 0; i < n; i++) {
        int x = num.front(); num.pop();
        while(!st.empty() && f[st.top().X] < f[x]) {
            ans[st.top().Y] = x;
            st.pop();
        }
        st.push({x, i});
    }
    for(int i = 0; i < n; i++) {
        if(ans[i] == 0) cout << -1 << " ";
        else cout << ans[i] << " ";
    }
}