#include <bits/stdc++.h>

using namespace std;
bool arr[31];
int main() {
    for(int i = 0; i < 28; i++) {
        int x; cin >> x; arr[x] = 1;
    }
    for(int i = 1; i < 31; i++) {
        if(!arr[i]) cout << i << "\n";
    }
}