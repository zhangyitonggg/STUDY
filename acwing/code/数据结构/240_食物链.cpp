#include <iostream>
using namespace std;
int p[50010];
int d[50010];
int idx;

int find(int x) {
    if (x != p[x]) {
        int t = find(p[x]);
        d[x] += d[p[x]];
        p[x] = t;
    }
    return p[x];
}

int main() {
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        p[i] = i;
    }
    int op, x, y;
    int res = 0;
    while(k--) {
        cin >> op >> x >> y;
        if (x > n || y > n) {
            res++;
            continue;
        } 
        if (op == 1) {
            int px = find(x), py = find(y);
            if (px == py) {
                if ((d[x] - d[y]) % 3 != 0) {
                    res++;
                }
            } else {
                p[px] = py;
                d[px] = d[y] - d[x];
            }
        } else {
            int px = find(x), py = find(y);
            if (px == py) {
                if ((d[x] - d[y] - 1) % 3 != 0) {
                    res++;
                }
            } else {
                p[px] = py;
                d[px] = d[y] - d[x] + 1;
            }
        }
    }
    cout << res << endl;
    return 0;
}