#include <bits/stdc++.h>
using namespace std;
int n, ans;
int main() {
    for(int i = 1; i < n; i++) {
        int temp = i;
        bool flag = 1;
        while(1) {
            int now = temp % 10; temp /= 10;
            if(temp == 0) break;
            if(temp % 10 < now) {
                flag = 0;
                break;
            }
            ans += flag;
        }
    }
}

//GTTTGACACACAT
//GTTTGAC CACAT