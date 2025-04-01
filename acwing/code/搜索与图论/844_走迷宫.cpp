#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

typedef pair<int, int> PII;

int s[120][120];
int d[120][120];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= m; j++) 
            cin >> s[i][j];
    for (int j = 0; j <= m + 1; j++) {
        s[0][j] = 1;
        s[n + 1][j] = 1;
    }
    for (int i = 0; i <= n + 1; i++) {
        s[i][0] = 1;
        s[i][m + 1] = 1;
    }
    memset(d, -1, sizeof(d));
    
    queue<PII> q;
    q.push({1, 1});
    d[1][1] = 0;
    
    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};
    
    while(q.size()) {
        PII tmp = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int x = tmp.first + dx[i];
            int y = tmp.second + dy[i];
            if (s[x][y] == 0 && d[x][y] == -1) {
                d[x][y] = d[tmp.first][tmp.second] + 1;
                q.push({x, y});
            }
            
        }
    }
    
    cout << d[n][m];
    return 0;
}