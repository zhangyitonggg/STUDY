#include<bits/stdc++.h>
using namespace std;

stack<char> s;
int main() {
    char c;
    while(cin >> c) {
        if (c == '-') {
            cout << '-';
        } else {
            s.push(c);
        }
    }

    while(s.top() == '0' && s.size() > 1) {
        s.pop();
    }

    while(!s.empty()) {
        cout << s.top();
        s.pop();
    }

    return 0;
}
