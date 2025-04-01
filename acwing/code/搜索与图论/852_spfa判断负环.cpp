#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

const int N = 100010;

int n, m;
int h[N], e[N], ne[N], w[N], idx;
int dist[N];
int cnt[N];
bool st[N];

void add(int a, int b, int c) {
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx;
    idx++;
}

bool spfa() {
    // memset(dist, 0x3f, sizeof(dist));
    // dist[1] = 0;
    
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        q.push(i);
        st[i] = true;
    }

    while(q.size()) {
        int t = q.front();
        q.pop();
        
        st[t] = false;
        
        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            if (dist[j] > dist[t] + w[i]) {
                dist[j] = dist[t] + w[i];
                cnt[j] = cnt[t] + 1;
                if (cnt[j] >= n) return false;
                if (!st[j]) {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }
    
    
    return true;
}

int main() {
    scanf("%d%d", &n, &m);
    memset(h, -1, sizeof(h));
    
    while(m--) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
    }
    
    int res = spfa();
    
    if (res) puts("No");
    else puts("Yes");
    return 0;
}