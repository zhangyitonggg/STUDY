#include<iostream>
#include<string>
using namespace std;
#define MAXM 100010
int e[MAXM], l[MAXM], r[MAXM], idx;

void init() {
    r[0] = 1;
    l[1] = 0;
    idx = 2;
}

void insert_right(int a, int x) {
    e[idx] = x;
    l[idx] = a, r[idx] = r[a];
    l[r[a]] = idx, r[a] = idx;
    idx++;
}

void insert_left(int a, int x) {
    e[idx] = x;
    l[idx] = l[a], r[idx] = a;
    r[l[a]] = idx, l[a] = idx;
    idx++;
}

void remove(int a) {
    l[r[a]] = l[a];
    r[l[a]] = r[a];
}

int main() {
    int m;
    cin >> m;
    init();
    while(m--) {
        string op;
        int k,x;
        cin >> op;
        if(op == "L") {
            cin >> x;
            insert_right(0, x);
        }
        else if (op == "R") {
            cin >> x;
            insert_left(1, x);
        }
        else if (op == "D") {
            cin >> k;
            remove(k+1);
        } 
        else if (op == "IL") {
            cin >> k >> x;
            insert_left(k+1, x);
        }
        else {
            cin >> k >> x;
            insert_right(k+1, x);
        }
    }
    for(int i = r[0]; i!=1;i=r[i]) {
        cout << e[i] << " ";
    }
    return 0;
}