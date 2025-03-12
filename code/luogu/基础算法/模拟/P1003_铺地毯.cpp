#include<stdio.h>

const int MAXN = 10000 + 5;//程序里出现幻数可不是好习惯哦~

int a[MAXN], b[MAXN], g[MAXN], k[MAXN];

int main() {
    int n, x, y;
    
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d%d%d%d", &a[i], &b[i], &g[i], &k[i]);//输入
    }
    scanf("%d%d", &x, &y);
    
    int ans = -1;
    for(int i = 0; i < n; i++) {
        if(x >= a[i] && y >= b[i] && x <= a[i] + g[i] && y <= b[i] + k[i]) {
            ans = i + 1;//ans的最终值恰好是最上面的那张地毯编号
        }
    }
    
    printf("%d\n", ans);//输出结果
    
    return 0;
}