#include <iostream>
#include <cstdio>
using namespace std;

int a[1000010];
int q[1000010];

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    int head = 0, tail = -1;
    for(int i = 0; i < n; i++) {
        while(head <= tail && q[head] < i - k + 1) head++;
        while(head <= tail && a[q[tail]] >= a[i]) tail--;
        q[++tail] = i;
        if (i >= k - 1) printf("%d ", a[q[head]]);
    }
    
    puts("");
    
        
    head = 0, tail = -1;
    for(int i = 0; i < n; i++) {
        while(head <= tail && q[head] < i - k + 1) head++;
        while(head <= tail && a[q[tail]] <= a[i]) tail--;
        q[++tail] = i;
        if (i >= k - 1) printf("%d ", a[q[head]]);
    }
    
    return 0;
}