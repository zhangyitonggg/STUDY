#include<iostream>

using namespace std;

int n;

int calc(int m, int p) {
    return (n + m - 1) / m * p;
}


int main() {
    cin >> n;
    int min = 0x7fffffff;
    for (size_t i = 0; i < 3; i++) {
        int m, p;
        cin >> m >> p;
        int res = calc(m, p);
        if (res < min) {
            min = res;
        }
    }
    cout << min;
    return 0;
}