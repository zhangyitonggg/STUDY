#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n, k;
char s[120];
int m[120][120];

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < k; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        scanf("%s", s);
        for (int j = 0; j < strlen(s); j++) {
            char op = s[j];
            int x = 0, y = 0;
            if (op == 'f') {
                y = 1;
            } else if (op == 'b') {
                y = -1;
            } else if (op == 'l') {
                x = -1;
            } else if (op == 'r') {
                x = 1;
            }
            x = a + x, y = b + y;
            if (!(x < 1 || x > n || y < 1 || y > n)) {
                a = x, b = y;
            }
        }
        printf("%d %d\n", a, b);
    }
    return 0;
}