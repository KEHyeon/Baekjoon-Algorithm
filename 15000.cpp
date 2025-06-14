#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <cstring>
using namespace std;
string a;
int main() {
    cin >> a;
    for (char& c : a) {
        c = toupper(c);
    }

    cout << a;
}