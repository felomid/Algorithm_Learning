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

int N, D;
int ans[101];
int t, l;

int main(){
  cin >> N >> D;
  for (int i = 0; i < N; i++) {
    cin >> t >> l;
    for (int j = 1; j <= D; j++) {
      ans[j] = std::max(t * (l + j), ans[j]);
    }
  }
  for (int i = 1; i <= D; i++)
    cout << ans[i] << endl;
  return 0;
}