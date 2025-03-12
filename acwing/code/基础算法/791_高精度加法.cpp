#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> add(vector<int> &A, vector<int> &B) {
    if (A.size() < B.size()) return add(B, A);
    
    int t = 0;
    vector<int> C;
    
    for (int i = 0; i < A.size(); i++) {
        t = t + A[i];
        if (i < B.size()) t = t + B[i];
        C.push_back(t % 10);
        t = t / 10;
    }
    
    if (t) C.push_back(t);
    return C;
}

int main() {
    string a, b;
    cin >> a >> b;    
    vector<int> A, B;
    for(int i = a.size() - 1; i >= 0;i--) {
        A.push_back(a[i] - '0');
    }
    for(int i = b.size() - 1; i >= 0; i--) {
        B.push_back(b[i] - '0');
    }
    auto C = add(A, B);
    for (int i = C.size() - 1; i >= 0; i--) {
        printf("%d", C[i]);
    }
    return 0;
}