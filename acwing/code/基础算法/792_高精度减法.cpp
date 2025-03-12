#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

vector<int> sub(vector<int> &A, vector<int> &B) {
    int t = 0;
    vector<int> C;
    
    for (int i = 0; i < A.size(); i++) {
        t = A[i] - t;
        if (i < B.size()) t = t - B[i];
        C.push_back((t + 10) % 10);
        if (t < 0) t = 1;
        else t = 0;
    }
    
    while(C.size() > 1 && C.back() == 0) {
        C.pop_back();
    }

    return C;
}

bool cmp(string a, string b) {
    if(a.size() != b.size()) return a.size() >= b.size();
    return a >= b;
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
    
    vector<int> C;
    if (!cmp(a, b)) {
        C = sub(A, B);        
    } else {
        C = sub(B, A);
    }

    for (int i = C.size() - 1; i >= 0; i--) {
        printf("%d", C[i]);
    }
    return 0;
}