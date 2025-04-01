#include <iostream>
#include <algorithm>

using namespace std;

int N,V;
int v[1010], w[1010];
int dp[1000010];


int main() {
    cin >> N >> V;
    for (int i = 1; i <= N; i++) {
        cin >> v[i] >> w[i];
    }
    for (int i = 1;  i <= N; i++) {
        for (int j = v[i]; j <= V; j++) {
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);   
        }
    }
    cout << dp[V]; 
    return 0;
}