#include <bits/stdc++.h>

using namespace std;

int main() {
    int n = 0, mother = 0;
    for (int i = 1; i < 13; i++) {
        int budget;
        cin >> budget;
        n += 300 - budget;
        if (n < 0) {
            cout << "-" << i;
            return 0;
        }
        mother += n / 100 * 100;
        n %= 100;
    }
    cout << n + mother * 1.2;
    return 0;
}