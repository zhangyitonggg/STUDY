#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
#define MAXN 100010

int h[MAXN], ph[MAXN], hp[MAXN], idx = 0;

void heap_swap(int a, int b) {
    swap(ph[hp[a]], ph[hp[b]]);
    swap(hp[a], hp[b]);
    swap(h[a], h[b]);
}

void down(int u) {
    int t = u;
    if (u * 2 <= idx && h[u * 2] < h[t]) t = u * 2;
    if (u * 2 + 1 <= idx && h[u * 2 + 1] < h[t]) t = u * 2 + 1;
    if (u != t) {
        heap_swap(u, t);
        down(t);
    }
}

void up(int u) {
    while(u / 2 && h[u] < h[u / 2]) {
        heap_swap(u, u / 2);
        u = u / 2;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int k, x;
    char s[5];
    int cnt = 0;
    while(n--) {
        scanf("%s", s);
        if (s[0] == 'I') {
            cnt++;
            scanf("%d", &x);
            h[++idx] = x;
            ph[cnt] = idx;
            hp[idx] = cnt;
            up(idx);
        } else if (s[0] == 'P') {
            cout << h[1] << endl;
        } else if (s[0] == 'D' && s[1] == 'M') {
            heap_swap(1, idx);
            idx--;
            down(1);
        } else if (s[0] == 'D') {
            scanf("%d", &k);
            k = ph[k];
            heap_swap(k, idx);
            idx--;
            down(k);
            up(k);
        } else {
            scanf("%d%d", &k, &x);
            k = ph[k];
            h[k] = x;
            down(k);
            up(k);
        }
    }
    return 0;
}