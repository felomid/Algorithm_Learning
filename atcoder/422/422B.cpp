#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <cstring>

#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define eb emplace_back
#define mp std::make_pair

typedef long long ll;
typedef std::pair<int,int> pii;
using std::cin;
using std::cout;
using std::endl;

std::vector<pii> blacks;
std::vector<std::vector<int>> g;

int n, m;
std::string s;

const int dir = 4;
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, 1, -1, 0};

bool safe(int x, int y) {
    return (x < n && x >= 0) && (y < m && y >= 0);
}

bool valid_black(pii point) {
    int x = point.first, y = point.second;
    int num = 0;
    for (int i = 0; i < dir; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (!safe(nx, ny))
            continue;
        num += g[nx][ny];        
    }
    // cout << "Point (" << x << "," << y << "): " << num <<endl;
    return (num == 2) || (num == 4);
}

int main(){
    cin >> n >> m;
    blacks.clear();
    g.clear();

    for (int i = 0; i < n; i++) {
        cin >> s;
        std::vector<int> temp;
        for (int j = 0; j < m; j++) {
            if (s[j] == '.')
                temp.eb(0);
            else {
                temp.eb(1);
                blacks.eb(mp(i, j));
            }
        }
        g.eb(temp);
    }

    if (!blacks.empty()) {
        for (auto point: blacks) {
            if (!valid_black(point)) {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}