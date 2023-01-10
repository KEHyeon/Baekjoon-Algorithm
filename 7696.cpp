#include <bits/stdc++.h>
using namespace std;
int arr[1000001], num = 1;

bool isRepeat(int x) {
    int status = 0;
    while(x > 0) {
        int first = x % 10;
        x /= 10;
        if(status & (1 << first)) return 0;
        else status |= (1 << first);
    }
    return 1;
}
int main() {
    for(int cnt = 1; cnt <= 1000000;) {
        if(isRepeat(num)) {
            arr[cnt++] = num;
        }
        num++;
    }
    int query;
    cin >> query;
    while(query) {
        cout << arr[query] << '\n';
        cin >> query;
    }
}