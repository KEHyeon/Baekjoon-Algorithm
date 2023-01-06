//
// Created by kimtaehyun on 2023/01/06.
//
#include <bits/stdc++.h>
using namespace std;

int arr[1000001], n;
vector<int> ans;
vector<int> cnt;
int maxLen = 1;
int main() {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    ans.push_back(arr[0]);
    cnt.push_back(1);
    for(int i = 1; i < n; i++) {
        if(ans[ans.size() - 1] < arr[i]) {
            ans.push_back(arr[i]);
            cnt.push_back(maxLen);
        }
        else {
            int idx = lower_bound(ans.begin(), ans.end(), arr[i]) - ans.begin();
            ans[idx] = arr[i];
            cnt[idx] += 1;
            maxLen = max(maxLen, cnt[idx]);
        }
    }
    cout << ans.size() << " " << maxLen;
}
