#include <iostream>
#include <map>

using namespace std;

// 自定义比较仿函数（按键降序排序）
struct MyCompare {
    bool operator()(int a, int b) const {
        return a > b;  // 降序
    }
};

int main() {
    map<int, string, MyCompare> m;
    m[3] = "Apple";
    m[1] = "Banana";
    m[5] = "Cherry";

    for (const auto& pair : m) {
        cout << pair.first << ": " << pair.second << endl;
    }

    return 0;
}
