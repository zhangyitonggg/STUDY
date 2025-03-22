#include<iostream>
#include<string>
using namespace std;

int stk[100010];
int top = -1;
int main() {
    int m;
    cin >> m;
    while(m--) {
        string op;
        cin >> op;
        if (op == "push") {
            int x;
            cin >> x;
            stk[++top] = x;
        } else if (op == "pop") {
            top--;
        } else if (op == "empty") {
            if (top == -1) cout << "YES" << endl;
            else cout << "NO" <<endl;
        } else {
            cout << stk[top] << endl;
        }
    }
    return 0;
}