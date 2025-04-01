#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n;
int a[100010], b[100010];
int r[100010];
int ans[100010];

int main() {
    scanf("%d", &n);
    for (int i = 0; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &b[i]);
    }
    r[0] = 0 - a[0];
    int m = r[0];
    for (int i = 1; i <= n; i++) {
        r[i] = r[i - 1] + b[i] - a[i];
        m = min(m, r[i]);
    }
    
    int t = n;
    int j = n;
    for (int i = n; i >= 1; i--) {
        for (; j >= i; j--) {
            if (r[j] < r[t]) {
                t = j;
            }
        }
        ans[i] = -1 * min(m, r[t] - b[i]);
    }
    for (int i = 1; i <= n; i++) {
        printf("%d ", ans[i]);
    }
    return 0;
}