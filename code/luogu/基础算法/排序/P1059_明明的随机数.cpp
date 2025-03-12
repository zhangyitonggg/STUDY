#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<int> v;

int main() {
    int n, k;
    cin>>n;
    for(int i = 0; i < n; i++) {
        cin>>k;
        v.push_back(k);
    }
    sort(v.begin(), v.end());
    vector<int>::iterator it;
    it = unique(v.begin(), v.end());
    v.resize(distance(v.begin(), it));
    cout << v.size() << endl;
    for(int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    return 0;
}