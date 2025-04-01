#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 200010;

int n, m;
int h[N], e[N], ne[N], idx;
int color[N];

void add(int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx;
    idx++;
}

bool dfs(int u, int c) {
    color[u] = c;
    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        if (color[j] == -1) {
            if (!dfs(j, !c)) return false;
        }
        else if (color[j] == c) {
            return false;
        }
    }
    return true;
}

int main() {
    scanf("%d%d", &n, &m);
    
    memset(h, -1, sizeof(h));
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
        add(b, a);
    }
    
    memset(color, -1, sizeof(color));
    bool flag = true;
    for (int i = 1; i <= n; i++) {
        if (color[i] == -1) {
            if (!dfs(i, 0)) {
                flag = false;
                break;
            }
        }
    }
    if (flag) puts("Yes");
    else puts("No");
    return 0;
}