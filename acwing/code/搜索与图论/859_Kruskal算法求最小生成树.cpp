#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

struct Edge {
    int a, b, w;
    
    bool operator<(const Edge &W) {
        return w < W.w;
    }
} edges[200010];

int n, m;

int p[100010];

int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int kruskal() {
    sort(edges, edges + m);
    for (int i = 1; i <= n; i++) p[i] = i;
    
    int res = 0, cnt = 0;
    for (int i = 0; i < m; i++) {
        int a = edges[i].a, b = edges[i].b, w = edges[i].w;
        int pa = find(a), pb = find(b);
        if (pa != pb) {
            p[pa] = pb;
            res += w;
            cnt++;
        }
    }
    
    if (cnt < n - 1) return 0x3f3f3f3f;
    return res;
}

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++) {
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        edges[i] = {a, b, w};
    }
    
    int t = kruskal();
    if (t == 0x3f3f3f3f) puts("impossible");
    else printf("%d", t);
    return 0;
}