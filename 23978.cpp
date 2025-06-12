#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <cstring>


using namespace std;
long long int n, k;
long long int arr[1000000];
bool a(__int128  x){
    __int128 sum = 0;
    for(long long int i = 0; i < n; i++) {
        __int128 diff;
        if(i == n - 1) {
            diff = 0;
        } else {
            diff = x - (arr[i + 1] - arr[i] - 1) - 1;
        }
        if(diff < 0) {
            diff = 0;
        }

        sum += (x + 1) * x / 2 - (diff + 1) * diff / 2;
    }
    return k <= sum;
}
int main () {
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    long long int l = 0, h = k;

    while(l + 1 < h) {
        __int128  mid = (l + h) / 2;
        if(a(mid)) {
            h = mid;
        } else {
            l = mid;
        }
    }
    cout << h;
}

