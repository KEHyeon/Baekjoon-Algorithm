#include <bits/stdc++.h>
using namespace std;
int n;
void bt(int num, string a) {
    if(n == num) {
        cout << a;
        cout << '\n';
        return;
    }

    bt(num + 1, a + '0');
    bt(num + 1, a + '1');
}
int main() {
    cin >> n;
    bt(0, " ");
}