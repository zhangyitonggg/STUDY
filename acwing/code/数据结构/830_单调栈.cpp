#include <stack>
#include <iostream>
using namespace std;

stack<int> s;

int main() {
    int n;
    cin >> n;
    while(n--) {
        int x;
        cin >> x;
        while(s.size() && s.top() >= x) s.pop();
        if (s.size()) cout << s.top() << " ";
        else cout << -1 << " ";
        s.push(x);
    }
    return 0;
}