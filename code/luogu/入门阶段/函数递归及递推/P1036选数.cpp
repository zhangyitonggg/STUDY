#include <iostream>
#include <vector>
#include <cmath>
#include <functional>

using namespace std;

int count = 0;

bool is_prime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

void slove(int n, int k, vector<int> nums) {
    int count = 0;
    vector<bool> used(n, false);

    function<void(int, int, int)> backtrack = [&](int start, int count, int sum) {
        if (count == k) {
            if (is_prime(sum)) (::count)++;
            return;
        }
        for (int i = start; i < n; i++) {
            if (!used[i]) {
                used[i] = true;
                // for (int i = 0; i < n; i++)
                // {
                //     cout << used[i] << " ";
                // }
                // cout << sum + nums[i] << endl;
                // cout << endl;
                backtrack(i + 1, count + 1, sum + nums[i]);
                used[i] = false;
            }
        }
    };

    backtrack(0, 0, 0);
    cout << ::count << endl;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    slove(n, k, nums);
    return 0;
}

