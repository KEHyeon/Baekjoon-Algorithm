#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <cstring>

int n, a, b, ans, arr[10000];
using namespace std;

int main () {
    cin >> n >> a >> b;
    int tmax = -1;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        tmax = max(arr[i], tmax);
    }
    sort(arr, arr + n);

    for (int sleepTime = 0; sleepTime <= tmax; sleepTime++) {
        for(int x = 0; x < a; x++) {
            int bx = x * b;
            int cnt = 0, curtime = 0;
            int tt = a;
            for (int i = 0; i < n; i++) {
                if (sleepTime >= curtime && sleepTime < curtime + a) {
                    curtime = sleepTime + bx;
                    tt = a - x;
                }
                if(curtime + tt <= arr[i]) {
                    cnt++;
                    curtime += tt;
                }  
               
            }
            ans = max(cnt, ans);
        }
    }
    cout << ans;
}