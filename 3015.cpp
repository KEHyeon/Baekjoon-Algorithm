#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
#define pii pair<ll,ll>
using namespace std;
stack<pii> st;
ll ans;
int main() {
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        ll cnt = 1;
        while(!st.empty() && st.top().X <= x) {
            if(st.top().X == x) {
                ans += st.top().Y;
                cnt = st.top().Y + 1;
                st.pop();
            }
            else {
                ans += st.top().Y;
                st.pop(); cnt = 1;
            }
        }
        if(!st.empty()) ans++;
        st.push({x, cnt});
    }
    cout << ans;
}