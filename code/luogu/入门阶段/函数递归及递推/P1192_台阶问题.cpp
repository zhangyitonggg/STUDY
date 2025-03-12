#include<iostream>
#include<cstdio>
using namespace std;
const int mod = 100003;
int n, k, dp[1000005];

int main() {
    cin >> n >> k;
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            if (i >= j) {
                dp[i] = (dp[i] + dp[i-j]) % mod;
            }
        }
    }
    cout << dp[n] % mod;
    return 0;
}