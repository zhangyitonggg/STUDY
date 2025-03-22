#include <iostream>
using namespace std;
int e[100010], ne[100010], idx, head;

void init(){
    head = -1;
    idx = 0;
}

void insert(int a) {
    e[idx] = a;
    ne[idx] = head;
    head = idx;
    idx++;
}

void insert(int k, int a) {
    e[idx] = a;
    ne[idx] = ne[k];
    ne[k] = idx;
    idx++;
}

void remove() {
    head = ne[head];
}

void remove(int k) {
    ne[k] = ne[ne[k]];
}

int main() {
    int m;
    cin >> m;
    init();
    while(m--){
        char op;
        cin >> op;
        if(op == 'H') {
            int x;
            cin >> x;
            insert(x);
        } else if(op == 'D') {
            int x;
            cin >> x;
            if(x == 0) {
                remove();
            } else {
                remove(x - 1);
            }
        } else {
            int x, y;
            cin >> x >> y;
            insert(x-1, y);
        }
    }
    int t = head;
    while(t!=-1){
        cout << e[t] << " ";
        t = ne[t];
    }
    return 0;
}