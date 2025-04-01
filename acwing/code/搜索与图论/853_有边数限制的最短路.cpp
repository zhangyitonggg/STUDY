#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 510, M = 10010;

struct Edge {
    int a, b, w;
} edges[M];

int n, m, k;
int dist[N];
int last[N];

void bellman_ford() {
    memset(dist, 0x3f, sizeof(dist));
    
    dist[1] = 0;
    for (int i = 0; i < k; i++) {
        memcpy(last, dist, sizeof(dist));
        for (int j = 0; j < m; j++) {
            auto e = edges[j];
            // cout << e.a << " " << e.b << " " << e.w << endl;
            dist[e.b] = min(dist[e.b], last[e.a] + e.w);
        }
    }
}

int main() {
    scanf("%d%d%d", &n, &m, &k);
    
    for (int i = 0; i < m; i++) {
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        edges[i] = {a, b, w};
    }
    
    bellman_ford();
    
    if (dist[n] > 0x3f3f3f3f / 2) puts("impossible");
    else printf("%d\n", dist[n]);
    
    return 0;
}