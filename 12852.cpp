#include <bits/stdc++.h>
using namespace std;
int x, cnt;
vector<int> ans;
void f(int n) {
    ans.push_back(n);
    if(n == 1) return;
    cnt++;
    if(n % 3 == 0) f(n / 3);
    else if(n % 2 == 0) f(n / 2);
    else f(n - 1);
}
int main () {
    cin >> x;
    f(x);
    cout << cnt << "\n";
    for(int i : ans) {
        cout << i << " ";
    }
}