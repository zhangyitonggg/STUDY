#include <iostream>
using namespace std;

int p[100010];

int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        p[i] = i;
    }
    int m;
    cin >> m;
    while(m--) {
        char op;
        int x, y;
        cin >> op >> x >> y;
        if (op == 'M') {
            x = find(x);
            y = find(y);
            p[x] = y;
        } else {
            if (find(x) == find(y)) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
    return 0;
}