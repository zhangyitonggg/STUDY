#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int, int> PII;

vector<PII> segs;

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        segs.push_back({l, r});
    }
    sort(segs.begin(), segs.end());
    int st = -10e9, ed = -10e9;
    vector<PII> res;
    for(auto seg : segs) {
        if(ed < seg.first) {
            if(st != -10e9) {
                res.push_back({st, ed});
            }
            st = seg.first;
            ed = seg.second;
        }
        else {
            ed = max(ed, seg.second);
        }
    }
    cout << res.size() << endl;
    return 0;
}