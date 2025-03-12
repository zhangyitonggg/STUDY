#include <algorithm>
#include <stdio.h>
using namespace std;

int q[100010];

int main() {
    int n, t;
    scanf("%d%d", &n, &t);
    for(int i = 0; i < n; i++) {
        scanf("%d", &q[i]);
    }
    while(t--) {
        int k;
        scanf("%d", &k);
        
        int l = 0, r = n - 1;
        while(l < r) {
            int mid = (l + r) >> 1;
            if (q[mid] >= k) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        
        if (q[l] != k) {
            printf("-1 -1\n");
            continue;
        }
        printf("%d ", l);
        
        l = 0, r = n - 1;
        while(l < r) {
            int mid = (l + r + 1) >> 1;
            if (q[mid] <= k) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        printf("%d\n", l);
    }
    return 0;
}