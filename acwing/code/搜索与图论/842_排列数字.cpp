#include <iostream>
#include <cstdio>

using namespace std;

int visit[10];
int all[10];

int n;

void dfs(int s) {
    if (s == n) {
        for(int i = 0; i < n; i++) {
            cout << all[i] << " ";
        }
        cout << endl;
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (visit[i]) {
            continue;
        }
        visit[i] = 1;
        all[s] = i;
        dfs(s + 1);
        visit[i] = 0;
    }
}

int main() {
   cin >> n;
   dfs(0);
   return 0;
}