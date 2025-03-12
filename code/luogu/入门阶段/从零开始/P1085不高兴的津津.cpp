#include<bits/stdc++.h>

using namespace std;

int main() {
    int ans = 0;
    int max = 0;
    for (int i = 0; i < 8; i++) {
        int a, b;
        cin >> a >> b;
        if (a + b > max) {
            ans = i;
            max = a + b;
        }
    }
    if (max > 8) {
        cout << ans + 1 << endl;
    } else {
        cout << 0 << endl;
    }
    return 0;
}