#include <bits/stdc++.h>
using namespace std;
int main() {
    string str;
    getline(cin, str);
    stack<char> st;
    for(int i = 0; i < str.length(); i++) {
        if(str[i] == '<') {
            if(!st.empty()) {
                while(!st.empty()) {
                    cout << st.top();
                    st.pop();
                }
            }
            while(str[i] != '>') {
                cout << str[i];
                i++;
            }
            cout << '>';
            i++;
            if(str[i] == '<') {
                i--;
                continue;
            }
        }
        if(i >= str.length()) break;
        st.push(str[i]);
        if(str[i] == ' ') {
            st.pop();
            while(!st.empty()) {
                cout << st.top();
                st.pop();
            }
            cout << ' ';
        }
    }
    while(!st.empty()) {
        cout << st.top();
        st.pop();
    }

}