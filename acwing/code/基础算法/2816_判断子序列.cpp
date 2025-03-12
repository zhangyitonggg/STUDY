#include<iostream>
using namespace std;

int a[100010], b[100010];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    int i = 0, j = 0;
    for(; j < m; j++) {
        if(i >= n) break;
        if(a[i] == b[j]) i++;
    }
    if(i >= n) cout << "Yes";
    else cout << "No";
}