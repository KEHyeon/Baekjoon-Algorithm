#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <cstring>


using namespace std;
int tc, n, arr[100], ans[100];
int main () {
    cin >> tc;
    while(tc--) {
        cin >> n;
        memset(ans, 0, sizeof(ans));
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        bool inf = false;
        for(int i = 0; i < n; i++) {
            int ok = 0;
            int lastIndex = -1;
            for(int j = 0; j < n; j++) {
                if(ans[j] != 0) {
                    ok++;
                } else if(arr[j] == ok){
                    lastIndex = j;
                }
            }
            if(lastIndex == -1) {
                inf = true;
                break;
            }
            ans[lastIndex] = i + 1;
        }
        if(inf) {
            cout << "IMPOSSIBLE";
        } else {
            for(int i = 0; i < n; i++) {
                cout << ans[i] << " ";
            }
        }

        cout << "\n";
    }
}