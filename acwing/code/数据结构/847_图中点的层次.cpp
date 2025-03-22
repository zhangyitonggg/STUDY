#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int h[100010], e[200010], ne[200010], idx;
int d[100010];

void add(int a, int b){
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx;
    idx++;
}

void bfs(int x) {
    queue<int> q;
    d[x] = 0;
    q.push(x);
    
    while(q.size()) {
        int i = q.front();
        q.pop();
        for (int j = h[i]; j != -1; j = ne[j]) {
            int t = e[j];
            if (d[t] != -1) continue;
            d[t] = d[i] + 1;
            q.push(t);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    
    idx = 0;
    memset(h, -1, sizeof(h));
    memset(d, -1, sizeof(d));
    
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        add(a, b);
    }
    
    bfs(1);
    
    cout << d[n] << endl;
    
    return 0;
}