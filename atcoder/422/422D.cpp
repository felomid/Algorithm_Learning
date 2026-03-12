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
#define mp make_pair

typedef long long ll;
typedef std::pair<int,int> pii;
using std::cin;
using std::cout;
using std::endl;

int main(){
    int N, K;
    cin >> N >> K;
    std::vector<int> ans(1, K);

    for (int i = 0; i < N; i++) {
        std::vector<int> temp;
        for (int prv : ans) {
            temp.eb(prv / 2);
            temp.eb(prv - prv / 2);
        }
        ans = temp;
    }
    auto min_it = std::min_element(ans.begin(), ans.end());
    auto max_it = std::max_element(ans.begin(), ans.end());
    cout << *max_it - *min_it << endl;
    for (auto x : ans)
        cout << x << " ";
    cout << endl;
    return 0;
}