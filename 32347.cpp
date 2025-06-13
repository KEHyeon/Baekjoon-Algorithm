#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <cstring>
using namespace std;
int n, k;
bool arr[200000];
vector<int> onday;

bool check(int x) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int idx = n - 1;
    int cnt = k;
    while(idx != 0 && cnt != 0) {
        if(arr[idx] == 1) {
            idx = max(0, idx - x);
            cnt--;
        } else {
            int l = 0, r =  onday.size()  - 1;
            if(onday[0] >= idx) {
               idx = onday[0];
            } else {
                while(l + 1 < r) {
                    int mid = (l + r) / 2;
                    if(onday[mid] >= idx) {
                       r = mid;
                    }  else {
                       l = mid;
                    }
                }
                idx = onday[r];
            }
    
        }
    }
    return idx == 0;
}
int main() {
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        if(arr[i]) onday.push_back(i);
    }
    int l = 0, h = n;

    while(l + 1 < h) {
        int mid = (l + h) / 2;
        if(check(mid)) {
            h = mid;
        } else {
            l = mid;
        }
    }
    cout << h;
}