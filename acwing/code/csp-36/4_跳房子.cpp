#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;
typedef long long int ll;
const ll N  = 1e5 + 100;

ll n;
ll a[N], k[N];
ll ans[N];

int main() {
    memset(ans, -1, sizeof(ans));
    // cout << ans[0] << endl;
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &k[i]);
    }
    
    queue<ll> q;
    q.push(1);
    ans[1] = 0;
    while(q.size()) {
        ll t = q.front();
        // cout << "begin " << t << endl;
        q.pop();
        
        if (t == n) break;
        
        ll l = t + 1;
        ll r = min(t + k[t], n);
        

        if (r == n) {
            ans[n] = ans[t] + 1;
            break;
        }
        
        for (ll j = r; j >= l; j--) {
            ll ne = j - a[j];
            if (ans[ne] == -1) {
                ans[ne] = ans[t] + 1;
                q.push(ne);
            }
        }
    }

    // for (int i = 1; i <= n; i++) {
    //     cout << ans[i] << " ";
    // }
    // cout << endl;
    printf("%lld\n", ans[n]);
    return 0;
}