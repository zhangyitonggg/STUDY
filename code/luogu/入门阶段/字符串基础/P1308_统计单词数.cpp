#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
    string c,s;
    cin>>c;
    getchar();
    getline(cin, s);
    c = ' ' + c + ' ';
    s = ' ' + s + ' ';
    for(int i = 0; i < c.size(); i++) {
        c[i] = tolower(c[i]);
    }
    for(int i = 0; i < s.size(); i++) {
        s[i] = tolower(s[i]);
    }
    int ans = s.find(c);
    int t = ans;
    if (ans == -1) {
        cout << -1 << endl;
        return 0;
    }
    int cnt = 0;
    while (t != -1) {
        cnt++;
        t = s.find(c, t + 1);
    }
    cout << cnt << endl;
    return 0;
}