#include <iostream>
#include <string>
using namespace std;
int q[100010];
int head = 0, tail = -1;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int m;
    cin >> m;
    while(m--) {
        string op;
        cin >> op;
        if (op == "push") {
            int x;
            cin >> x;
            q[++tail] = x;
        }
        else if (op == "pop") {
            head++;
        } 
        else if (op == "empty") {
            if (head == tail + 1) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
        else {
            cout << q[head] << endl;
        }
    }
    return 0;
}