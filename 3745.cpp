#include <bits/stdc++.h>
using namespace std;
int n;

int main() {
    while(cin >> n) {
        vector<int> lis;
        int x; cin >> x;
        lis.push_back(x);
        for(int i = 1; i < n; i++) {
            cin >> x;
            if(x > lis[lis.size() - 1]) lis.push_back(x);
            else {
                lis[lower_bound(lis.begin(), lis.end(), x) - lis.begin()] = x;
            }
        }
        cout << lis.size() << endl;
    }
}