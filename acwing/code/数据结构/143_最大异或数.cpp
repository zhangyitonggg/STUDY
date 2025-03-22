// 注意不要把 & 写成 &&

#include <iostream>
#include <algorithm>
using namespace std;

int all[100010];
int son[3200010][2];
int idx;

void insert(int x) {
    int p = 0;
    for(int i = 30; i >= 0; i--) {
        int b = x >> i & 1;
        // cout << "in " << b << endl;
        if (son[p][b] == 0) son[p][b] = ++idx;
        p = son[p][b];
    }
}

int search(int x) {
    int p = 0;
    int res = 0;
    for (int i = 30; i >= 0; i--) {
        int b = x >> i & 1;
        if (son[p][!b] == 0) {
            if (son[p][b] == 0) {
                break;
            }
            p = son[p][b];
        }
        else {
            // cout << i << endl;
            p = son[p][!b];
            res += 1 << i;
        }
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> all[i];
        // cout << all[i] << endl;
        insert(all[i]);
    }   
    int res = 0;
    for(int i = 0; i < n; i++) {
        res = max(res, search(all[i]));
    }
    cout << res;
    return 0;
}