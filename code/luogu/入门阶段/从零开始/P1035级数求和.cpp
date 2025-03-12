#include<bits/stdc++.h>

using namespace std;

bool excess(double sn, double k) {
    return sn > k;
}

int main() {
    int i = 1;
    double sn = 0;
    double k;
    cin >> k;
    while (!excess(sn, k)) {
        sn += 1.0 / i;
        i++;
    }
    cout << i - 1;
    return 0;
}