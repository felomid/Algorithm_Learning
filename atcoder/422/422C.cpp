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

int N;

int main(){
    cin >> N;
    while (N--) {
        ll a, b, c;
        cin >> a >> b >> c;
        ll pair_num = std::min(a, c);
        ll remain = std::max(a, c) - pair_num;
        if (remain > pair_num)
            cout << pair_num << endl;
        else {
            cout << std::min((a + b + c) / 3, pair_num) << endl;
        }
    }
    return 0;
}