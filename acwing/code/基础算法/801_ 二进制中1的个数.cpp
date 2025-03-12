#include <iostream>
using namespace std;
int a[100010];
int main() {
    int n;
    cin >> n;
    while(n--) {
        int res = 0, x;
        cin >> x;
        while(x != 0) {
            x -= x & -x;
            res++;
        }
        cout << res << " ";
    }
    return 0;
}