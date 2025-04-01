// NVS -> NVlogS
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m;
int v[25000], w[25000];
int dp[2100];

int main() {
    cin >> n >> m;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        int a, b, s;
        cin >> a >> b >> s;
        int k = 1;
        while (k <= s) {
            cnt++;
            v[cnt] = a * k;
            w[cnt] = b * k;
            s = s - k;
            k = k * 2;
        }
        if (s > 0) {
            cnt++;
            v[cnt] = a * s;
            w[cnt] = b * s;
        }
    }
    n = cnt;
    
    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= v[i]; j--) {
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
        }
    }
    
    cout << dp[m] << endl;
    
    return 0;
}