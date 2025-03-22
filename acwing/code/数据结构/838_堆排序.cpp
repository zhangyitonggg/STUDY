#include <iostream>
#include <algorithm>
using namespace std;

int h[100010], siz;

void down(int u) {
    int t = u;
    if (2 * u <= siz && h[2 * u] < h[t]) t = 2 * u;
    if (2 * u + 1 <= siz && h[2 * u + 1] < h[t]) t = 2 * u + 1;
    if (t != u) {
        swap(h[t], h[u]);
        down(t);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    siz = n;
    for (int i = n / 2; i >= 1; i--) {
        down(i);
    }
    for (int i = 1; i <= m; i++) {
        cout << h[1] << " ";
        h[1] = h[siz];
        down(1);
        siz--;
    }
    return 0;
}