// 注意边的数量

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n;
int h[100010], e[200010], ne[200010], idx;
bool vis[100010];
int ans = 100010;

void add(int x, int y) {
    e[idx] = y;
    ne[idx] = h[x];
    h[x] = idx;
    idx++;
}

int dfs(int x) {
    vis[x] = true;
    
    int ans_tmp = 0, sum = 0;
    for (int i = h[x]; i != -1; i = ne[i]) {
        int j = e[i];
        if (!vis[j]) {
            int res = dfs(j);
            sum += res;
            ans_tmp = max(ans_tmp, res);
        } 
    }
    ans_tmp = max(ans_tmp, n - 1 - sum);
    ans = min(ans, ans_tmp);
    return sum + 1;
}

int main() {
    cin >> n;
    memset(h, -1, sizeof(h));
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        add(x, y);
        add(y, x);
    }
    dfs(1);
    cout << ans << endl;
    return 0;
}