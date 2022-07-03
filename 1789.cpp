#include <iostream>
using namespace std;
int main() {
    unsigned long long int n, i = 1; cin >> n;
    for( ; i * (i + 1) / 2 <= n; i++){}
    cout << i - 1;
}