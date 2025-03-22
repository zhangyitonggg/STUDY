#include <iostream>
#include <cstring>
using namespace std;

const int N = 100010;

int n, m;
int h[N], e[N], ne[N], idx;
int d[N];
int q[N];

void add(int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx;
    idx++;
    d[b]++;
}

bool toposort() {
    int hh = 0, tt = -1;
    for (int i = 1; i <= n; i++) {
        if (d[i] == 0) q[++tt] = i;
    }
    // cout << tt << endl;
    while(hh <= tt) {
        int t = q[hh++];
        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            // cout << t << " " << j << endl;
            d[j]--;
            if (d[j] == 0) {
                q[++tt] = j;
            }
        }
    }
    // cout << tt << endl;
    return tt == n - 1;
}

int main() {
    memset(h, -1, sizeof(h));
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        add(a, b);
    }
    bool flag = toposort();
    if (flag) {
        for (int i = 0; i < n; i++) {
            cout << q[i] << " ";
        }
    } else {
        cout << -1;
    }
    return 0;
}