#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int d[210][210];
int n, m, k;


void floyd() {
    for (int t = 1; t <= n; t++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                d[i][j] = min(d[i][j], d[i][t] + d[t][j]);
            }
        }
    }
}

int main() {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) d[i][j] = 0;
            else d[i][j] = 0x3f3f3f3f;
        }
    }
    while(m--) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        d[a][b] = min(d[a][b], c);
    }
    floyd();
    while(k--) {
        int a, b;
        scanf("%d%d", &a, &b);
        int res = d[a][b];
        if (res > 0x3f3f3f3f >> 1) puts("impossible");
        else printf("%d\n", res);
    }
    
    return 0;
}
