#include <bits/stdc++.h>
using namespace std;

int lis[1000001], arr[1000001], n;
vector<int> ans;
void print(int cur, int maxNum, int len) {
    if(len == 0) return;
    if(lis[cur] == len && arr[cur] < maxNum) {
        print(cur - 1, arr[cur], len - 1);
        cout << arr[cur] << " ";
    } else {
        print(cur - 1, maxNum, len);
    }
}
int main() {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    ans.push_back(arr[0]);
    lis[0] = 1;
    for(int i = 1; i < n; i++) {
        if(ans[ans.size() - 1] < arr[i]) {
            ans.push_back(arr[i]);
            lis[i] = ans.size();
        }
        else {
            int idx = lower_bound(ans.begin(), ans.end(), arr[i]) - ans.begin();
            ans[idx] = arr[i];
            lis[i] = idx + 1;
        }
    }
    cout << ans.size() << "\n";
    print(n - 1, 1000000001, ans.size());
}