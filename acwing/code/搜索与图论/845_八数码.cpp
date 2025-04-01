#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

int main() {
    string start = "";
    for (int i = 0; i < 9; i++) {
        char ch;
        cin >> ch;
        start += ch;
    }
    
    string end = "12345678x";
    
    queue<string> q;
    unordered_map<string, int> dist;
    
    q.push(start);
    dist[start] = 0;
    
    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};
    
    while(q.size()) {
        string s = q.front();
        q.pop();
        
        if (s == end) {
            cout << dist[s];
            return 0;
        }   
        
        int d = dist[s];
        int k = s.find('x');
        int x = k / 3, y = k % 3;
        for (int i = 0; i < 4; i++) {
            int a = x + dx[i], b = y + dy[i];
            if (a >= 0 && a < 3 && b >= 0 && b < 3) {
                swap(s[3 * a + b], s[k]);
                if (!dist.count(s)) {
                    dist[s] = d + 1;
                    q.push(s);
                }
                swap(s[3 * a + b], s[k]);
            }
        }
    }
    
    cout << -1;
    return 0;
}