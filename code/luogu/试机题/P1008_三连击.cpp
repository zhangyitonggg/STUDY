#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

ll num[9];

ll get_num(ll l, ll r) {
    ll ans = 0;
    for (ll i = l; i <= r; i++) {
        ans = ans * 10 + num[i];
    }
    return ans;
}

int main() {
    for (int i = 0; i < 9; i++) {
        num[i] = i + 1;
    }
    do {
        ll a = get_num(0, 2);
        ll b = get_num(3, 5);
        ll c = get_num(6, 8);
        if (b == 2 * a && c == 3 * a) {
            printf("%lld %lld %lld\n", a, b, c);
        }
    } while (next_permutation(num, num + 9));
    return 0;
}