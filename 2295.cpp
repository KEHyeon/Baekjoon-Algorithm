#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
using namespace std;
int n, ans;
unordered_map<int,int> ck;
int arr[1000];
int main() {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            ck[arr[i] + arr[j]] = 1;
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(ck[arr[j] - arr[i]] == 1) {
                ans = max(ans, arr[j]);
            }
        }
    }
    cout << ans;
}