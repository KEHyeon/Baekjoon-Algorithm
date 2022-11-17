#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> ans;
int arr[1000000];
int search(int x) {
    int lo = 0, hi = ans.size() - 1;
    while(lo + 1 < hi) {
        int mid = (lo + hi) / 2;
        if(ans[mid] >= x) hi = mid;
        else lo = mid;
    }
    return hi;
}
int main() {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    ans.push_back(24);
    ans.push_back(arr[0]);
    for(int i = 1; i < n ; i++) {
        if(ans[ans.size() - 1] < arr[i]) ans.push_back(arr[i]);
        else {
            ans[search(arr[i])] = arr[i];
        }
    }
    cout << ans.size() - 1;
}
