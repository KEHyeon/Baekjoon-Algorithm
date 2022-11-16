#include <bits/stdc++.h>
using namespace std;
int n, arr[1000000], f[1000000];

stack<int> st;
int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        f[arr[i]]++;
    }
    for(int i = n - 1; i >= 0; i--) {
        if(st.empty())
        st.push(arr[i]);

    }
}