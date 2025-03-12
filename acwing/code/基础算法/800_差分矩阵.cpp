#include <iostream>
using namespace std;

int b[1010][1010];

void insert(int x1, int y1, int x2, int y2, int c) {
    b[x1][y1] += c;
    b[x2+1][y2+1] += c;
    b[x1][y2+1] -= c;
    b[x2+1][y1] -= c;
}

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            int t;
            cin >> t;
            insert(i,j,i,j,t);
        }
    }
    while(q--) {
        int x1,y1,x2,y2,c;
        cin >> x1 >> y1 >> x2 >> y2 >> c;
        insert(x1,y1,x2,y2,c);
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            b[i][j] += b[i-1][j] + b[i][j-1] - b[i-1][j-1];
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}