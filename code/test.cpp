#include <iostream>
#include <map>

using namespace std;

// �Զ���ȽϷº�����������������
struct MyCompare {
    bool operator()(int a, int b) const {
        return a > b;  // ����
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
