#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

int n, m;
int g[510][510];
int dist[510];
bool st[510];

int prim() {
    memset(dist, 0x3f, sizeof(dist));
    
    int res = 0;
    for (int i = 0; i < n; i++) {
        int t = -1;
        for (int j = 1; j <= n; j++) {
            if (!st[j] && (t == -1 || dist[t] > dist[j])) t = j;
        }
        
        if (i && dist[t] > 0x3f3f3f3f >> 1) return 0x3f3f3f3f;
        
        if (i) res += dist[t];
        st[t] = true;
        
        for (int j = 1; j <= n; j++) {
            dist[j] = min(dist[j], g[t][j]);
        }
    }
    
    return res;
}

int main() {
    scanf("%d%d", &n, &m);
    memset(g, 0x3f, sizeof(g));
    
    while(m--) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        g[a][b] = min(g[a][b], c);
        g[b][a] = min(g[b][a], c);
    }
    
    int t = prim();
    if (t == 0x3f3f3f3f) puts("impossible");
    else printf("%d", t);
    
    return 0;
}