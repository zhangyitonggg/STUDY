#include<iostream>
#include<cstring>
using namespace std;

char P[100010];
char S[1000010];

int ne[100010];

int main() {
    int n, m;
    cin >> n >> P + 1 >> m >> S + 1;
    
    for (int i = 2, j = 0; i <= n; i++) {
        while (j && P[i] != P[j + 1]) j = ne[j];
        if (P[i] == P[j + 1]) j++;
        ne[i] = j;
    }
    
    for (int i = 1, j = 0; i <= m; i++) {
        while (j && S[i] != P[j + 1]) j = ne[j];
        if (S[i] == P[j + 1]) j++;
        if (j == n) {
            j = ne[j];
            cout << i - n << " ";
        }
    }
    return 0;
}