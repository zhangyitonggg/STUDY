#include <iostream>
using namespace std;
int b[100010];
int main() {
    int n,m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) {
        int t;
        scanf("%d", &t);
        b[i] += t;
        b[i+1] -= t;
    }
    for(int i = 0; i < m;i++) {
        int l,r,c;
        scanf("%d%d%d", &l, &r, &c);
        b[l] += c;
        b[r+1] -= c;
    }
    for(int i = 1; i <= n; i++) {
        b[i] += b[i-1];
        printf("%d ", b[i]);
    }
    
}