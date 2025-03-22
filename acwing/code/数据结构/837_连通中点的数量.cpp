#include <iostream>
#include <cstdio>

using namespace std;
int p[100010];
int siz[100010];
int idx;

int find(int x) {
    if (x != p[x]) p[x] = find(p[x]);
    return p[x];
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        p[i] = i;
        siz[i] = 1;
    }
    char str[10];
    while (m--) {
        scanf("%s", str);
        if (str[0] == 'C') {
            int x, y;
            cin >> x >> y;
            x = find(x);
            y = find(y);
            if (x != y) {
                p[x] = y;
                siz[y] += siz[x];
            }
        } else if (str[1] == '1') {
            int x, y;
            cin >> x >> y;
            x = find(x);
            y = find(y);
            if (x == y) cout << "Yes" << endl;
            else cout << "No" << endl;
        } else {
            int x;
            cin >> x;
            cout << siz[find(x)] << endl;
        }
    }
    return 0;
}