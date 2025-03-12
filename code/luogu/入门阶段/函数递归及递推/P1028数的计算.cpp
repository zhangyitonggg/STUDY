#include<bits/stdc++.h>

using namespace std;

const int maxn = 1000;
int f[maxn], g[maxn];

int main() {
    int n;
    cin >> n;
    f[1] = 1;
    g[1] = 1;
    for (int i = 2; i <= n; i++) {
        f[i] = g[i/2] + 1;
        g[i] = f[i] + g[i-1];
    }
    cout << f[n] << endl;
    return 0;
}
