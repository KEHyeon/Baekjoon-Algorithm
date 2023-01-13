#include <bits/stdc++.h>
using namespace std;

int main(){
	long long int x, n; cin >> x >> n;
    for(int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        x -= a * b;
    }
    if(x != 0) cout << "No";
    else cout << "Yes";
}