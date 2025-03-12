#include <algorithm>
#include <stdio.h>
using namespace std;

int main() {
    double n;
    scanf("%lf", &n);
    double l = -100, r = 100;
    while(r - l > 1e-7) {
        double mid = (l + r) / 2;
        if (mid * mid * mid < n) {
            l = mid;
        } else {
            r = mid;
        }
    }
    printf("%lf", l);
    return 0;
}