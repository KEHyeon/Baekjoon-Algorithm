#include <bits/stdc++.h>
using namespace std;
vector<char> oper;
vector<int> num;
string sic;
int main() {
    cin >> sic;
    for(int i = 0; i < sic.size(); i++) {
        int n = 0;
        while(sic[i] != '-' && sic[i] != '+' && i < sic.size()) {
            n = n * 10 + (sic[i] - '0');
            i++;
        }
        if(i == sic.size()) {
            num.push_back(n);
        }
        else {
            num.push_back(n);
            oper.push_back(sic[i]);
        }
    }
    int sum = 0;
    sum += num[0];
    for(int i = 0; i < oper.size(); i++) {
        if(oper[i] == '-') {
            oper[i] = '1';
            while(oper[i] != '-' && i < oper.size()) {
                sum -= num[i + 1];
                i++;
            }
            if(i == oper.size()) break;
            else {
                i--;
            }
        }
        else sum += num[i + 1];
    }
    cout << sum;
}