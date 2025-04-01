#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int N, V;
int v[110], w[110], s[110];
int dp[110][10010];

int main() {
    cin >> N >> V;
    for (int i = 1; i <= N; i++) {
        cin >> v[i] >> w[i] >> s[i];
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= V; j++) {
            int m = 0;
            for (int k = 0; k <= s[i] && j - v[i] * k >= 0; k++) {
                m = max(m, dp[i - 1][j - v[i] * k] + w[i] * k);
            }
            dp[i][j] = m;
        }
    }
    cout << dp[N][V];
}