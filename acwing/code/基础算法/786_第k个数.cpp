#include <algorithm>
#include <stdio.h>
#define MAXN 100010
typedef long long ll;
using namespace std;

ll q[MAXN];

ll get_kth(ll l, ll r, ll k) {
    if (l >= r) {
        return q[l];
    }
    
    ll i = l - 1, j = r + 1, x = q[l + r >> 1];
    
    while(i < j) {
        do ++i; while(q[i] < x);
        do --j; while(q[j] > x);
        if (i < j) {
            swap(q[i], q[j]);
        }
    }
    
    if (j - l + 1 < k) return get_kth(j + 1, r, k - j + l -1);
    else return get_kth(l, j, k);
}

int main() {
    ll n, k;
    scanf("%lld%lld", &n, &k);
    for(ll i = 0; i < n; ++i) {
        scanf("%lld", &q[i]);
    }
    printf("%lld", get_kth(0, n - 1, k));
    return 0;
}