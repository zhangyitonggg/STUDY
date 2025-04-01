#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int, int> PII;

const int N = 2e5;

int n, m;
int h[N], w[N], e[N], ne[N], idx;
int dist[N];
bool st[N];

void add(int a, int b, int c) {
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx;
    idx++;
}

int dijkstra() {
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;
    
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, 1});
    
    while(heap.size()) {
        auto t = heap.top();
        heap.pop();
        
        int v = t.second, d = t.first;
        
        if (st[v]) continue;
        st[v] = true;
        if (v == n) break;
        
        for (int i = h[v]; i != -1; i = ne[i]) {
            int j = e[i];
            if (dist[j] > dist[v] + w[i]) {
                dist[j] = dist[v] + w[i];
                heap.push({dist[j], j});
            }
        }
    }
    
    if (dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
}

int main() {
    scanf ("%d%d", &n, &m);
    
    memset(h, -1, sizeof(h));
    while(m--) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
    }
    
    int res = dijkstra();
    
    printf("%d\n", res);
    
    return 0;
}
