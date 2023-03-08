#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
using namespace std;
int n, k, arr[100000];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    vector<int> lis;
    lis.push_back(arr[0]);
    for(int i = 1; i < n; i++) {
        if(lis.back() < arr[i]) lis.push_back(arr[i]);
        *lower_bound(lis.begin(), lis.end(), arr[i]) = arr[i];
    }
    cout << n - lis.size();
}