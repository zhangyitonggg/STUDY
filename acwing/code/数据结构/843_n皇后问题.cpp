#include <iostream> 
using namespace std;

int col[20], pd[20], nd[20];
int n;
char s[20][20];

void dfs(int t) {
    if (t == n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << s[i][j];
            }
            cout << endl;
        }
        cout << endl;
        return;
    }
    for (int i = 0; i < n; i++) {
        if (col[i] || pd[t + i] || nd[t - i + n - 1]) {
            continue;
        }
        col[i] = 1;
        pd[t + i] = 1;
        nd[t - i + n - 1] = 1;
        s[t][i] = 'Q';
        dfs(t + 1);
        s[t][i] = '.';
        col[i] = 0;
        pd[t + i] = 0;
        nd[t - i + n - 1]= 0;
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            s[i][j] = '.';
        }
    }
    dfs(0);
    return 0;
}