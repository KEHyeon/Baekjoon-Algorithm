#include <bits/stdc++.h>
using namespace std;
vector<char> oper;
vector<int> num;
string sic;
int main() {
    cin >> sic;
    for(int i = 0; i < sic.length(); i++) {
        int n = 0;
        while(sic[i] != '-' && sic[i] != '+') {
            n = n * 10 + (sic[i] - 80);
            i++;
        }
        oper.push_back(sic[i]);
    }
    for(int i = 0; i < oper.size(); i++) cout << oper[i] << " ";
    cout << "\n";
    for(int i = 0; i < num.size(); i++) cout << num[i] << " ";
}