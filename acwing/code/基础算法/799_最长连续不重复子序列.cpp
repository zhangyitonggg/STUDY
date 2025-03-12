#include <map>
#include <iostream>
using namespace std;

int a[100010];

int main() {
    map<int, int> m;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int res = 0;
    for(int i = 0, j = 0; i < n; i++) {
        int t = a[i];
        if(m.find(t) == m.end()) {
            m[t] = 1;
        } else {
            m[t] = m[t] + 1;
        }
        while(m[t] > 1) {
            int p = a[j];
            m[p] = m[p] - 1;
            j++;
        }
        res = max(res, i - j + 1);
    }
    cout << res << endl;
    return 0;
}