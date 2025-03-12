#include <iostream>
using namespace std;
int A[100010];
int B[100010];
int main() {
    int n, m, x;
    cin >> n >> m >> x;
    for(int i = 0; i < n; i++) {
        cin >> A[i];
    }
    for(int i = 0; i < m; i++) {
        cin >> B[i];
    }
    for(int i = 0, j = m - 1; i < n; i++) {
        while (A[i] + B[j] > x) {
            j--;
        } 
        if (A[i] + B[j] == x) {
            cout << i << " " << j;
            break;
        }
    }
}