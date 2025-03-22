#include <iostream>
#include <cstring>
#define null 0x3f3f3f3f
#define N 300007
using namespace std;

int h[N];

int find(int x) {
    int k = (x % N + N) % N;
    int i;
    for(i = k; h[i] != null && h[i] != x; i = (i + 1) % N);
    return i;
}

int main() {
    memset(h, 0x3f, sizeof(h));
    
    int n;
    cin >> n;
    while(n--) {
        char op;
        int x;
        cin >> op >> x;
        if (op == 'I') {
            int t = find(x);
            h[t] = x;
        } else {
            int t = find(x);
            if (h[t] == null) cout << "No" << endl;
            else cout << "Yes" << endl;
        }
    }
    
    return 0;
}