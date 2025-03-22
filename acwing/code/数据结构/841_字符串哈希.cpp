#include <iostream>
#include <cstring>
using namespace std;
typedef unsigned long long ULL;

const int P = 131;
ULL h[100010], p[100010];
char str[100010];

ULL get(int l, int r) {
    return h[r] - h[l - 1] * p[r - l + 1];
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    scanf("%s", str + 1);
    
    p[0] = 1;
    for (int i = 1; i <= n; i++) {
        p[i] = p[i - 1] * P;
        h[i] = h[i - 1] * P + str[i];
    }
    
    while (m--) {
        int l1, r1, l2, r2;
        scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
        if (get(l1, r1) == get(l2, r2)) printf("Yes\n");
        else printf("No\n");
    }
    
    return 0;
}