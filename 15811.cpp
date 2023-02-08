#include <bits/stdc++.h>
#define ll long long
using namespace std;
string a, b, c;
int num[26];
bool vis[10];
vector<int> arr;
bool bt(int depth) {
    if(depth == arr.size()) {
        ll send = 0, more = 0, money = 0;
        for(char i : a) {
            send = send * 10 + num[i - 'A'];
        }
        for(char i : b) {
            more = more * 10 + num[i - 'A'];
        }
        for(char i : c) {
            money = money * 10 + num[i - 'A'];
        }
        return send + more == money;
    }
    bool ret = 0;
    for(int i = 0; i < 10; i++) {
        if(!vis[i]) {
            vis[i] = 1;
            num[arr[depth]] = i;
            ret |= bt(depth + 1);
            vis[i] = 0;
        }
    }
    return ret;
}
int main() {
    cin >> a >> b >> c;
    bool check[26] = {0,};
    for(char i : a) {
        if(!check[i - 'A']) {
            arr.push_back(i - 'A');
            check[i - 'A'] = 1;
        }
    }
    for(char i : b) {
        if(!check[i - 'A']) {
            arr.push_back(i - 'A');
            check[i - 'A'] = 1;
        }
    }
    for(char i : c) {
        if(!check[i - 'A']) {
            arr.push_back(i - 'A');
            check[i - 'A'] = 1;
        }
    }
    if(arr.size() > 10) {cout<<"NO"; return 0;}
    if(bt(0)) cout << "YES";
    else cout << "NO";
}