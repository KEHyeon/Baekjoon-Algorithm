#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <cstring>
using namespace std;
int n;
int main() {
    cin >> n;
    for(int i = 0; i < 9; i++) {
        int x; cin >> x;
        n -= x;
    }
    cout << n;
}