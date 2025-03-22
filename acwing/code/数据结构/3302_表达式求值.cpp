#include<iostream>
#include<cstring>
#include<algorithm>
#include<stack>
#include<unordered_map>

using namespace std;

stack<int> nums;
stack<char> ops;

void eval() {
    auto b = nums.top();
    nums.pop();
    auto a = nums.top();
    nums.pop();
    auto op = ops.top();
    ops.pop();
    int res;
    // cout << op << " " << a << " " << b << endl;
    if (op == '+') {
        res = a + b;
    } else if (op == '-') {
        res = a - b;
    } else if (op == '*') {
        res = a * b;
    } else {
        res = a / b;
    }
    nums.push(res);
}

int main() {
    unordered_map<char, int> pr{{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};
    string all;
    cin >> all;
    for (int i = 0; i < all.size(); i++) {
        auto c = all[i];
        if (isdigit(c)) {
            int num = 0, j = i;
            while(j < all.size() && isdigit(all[j])) {
                num = num * 10 + all[j] - '0';
                j++;
            }
            i = j - 1;
            nums.push(num);
        } 
        else if (c == '(') {
            ops.push(c);
        } 
        else if (c == ')') {
            while (ops.top() != '(') eval();
            ops.pop();
        } 
        else {
            while(!ops.empty() && ops.top() != '(' && pr[ops.top()] >= pr[c]) eval();
            ops.push(c);
        }
    }
    while(!ops.empty()) eval();
    cout << nums.top() << endl;
    return 0;
}