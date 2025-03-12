#include <algorithm>
#include <stdio.h>
using namespace std;

#define MAXN 100010
typedef long long ll;

ll q[MAXN];

void swap(ll i, ll j) {
    ll t = q[i];
    q[i] = q[j];
    q[j] = t;
}

void quick_sort(ll l, ll r) {
    if (l >= r) return;
    
    ll i = l - 1, j = r + 1, x = q[l + r >> 1];
    while(i < j) {
        do ++i; while(q[i] < x);
        do --j; while(q[j] > x);
        if(i < j) swap(i,j);
    }
    printf("%lld: ", x);
    printf("%lld %lld  ---- ", q[j], q[j+1]);
    for (ll i = l; i < r; i++) {
        printf("%lld ", q[i]);
    }
    printf("\n");
    quick_sort(l, j);
    quick_sort(j + 1, r);
}

int main() {
    ll n;
    scanf("%lld", &n);
    for (ll i = 0; i < n; ++i) {
        scanf("%lld", &q[i]);
    }
    quick_sort(0, n - 1);
    for (ll i = 0; i < n; i++) {
        printf("%lld ", q[i]);
    }
    return 0;
}