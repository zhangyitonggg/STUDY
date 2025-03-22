#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int son[100010][26], cnt[100010], idx;
char str[100010];

void insert(char *str) {
    int p = 0;
    for (int i = 0; str[i]; i++) {
        int u = str[i] - 'a';
        if (!son[p][u]) son[p][u] = ++idx;
        p = son[p][u];
    }
    cnt[p]++;
}

int query(char *str) {
    int p = 0;
    for (int i = 0; str[i]; i++) {
        int u = str[i] - 'a';
        if (!son[p][u]) return 0;
        p = son[p][u];
    }
    return cnt[p];
}

int main() {
    int n;
    cin >> n;
    while(n--) {
        char op;
        scanf(" %c %s", &op, str);
        if (op == 'I') insert(str);
        else cout << query(str) << endl;
    }
    return 0;
}