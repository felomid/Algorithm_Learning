#include <iostream>
#include <vector>
#include <climits>

#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define eb emplace_back
#define mp make_pair

typedef long long ll;
typedef std::pair<int,int> pii;
using std::cin;
using std::cout;
using std::endl;

int main(){
  int n, k;
  cin >> n >> k;
  std::vector<int> h(n);
  for(int i=0;i<n;i++) cin >> h[i];
  std::vector<int> dp(n, INT_MAX);
  dp[0] = 0;
  for (auto i = 1; i < n; i++) {
    auto start = std::max(0, i - k);
    for (auto j = start; j < i; j++)
      dp[i] = std::min(dp[i], dp[j] + std::abs(h[i] - h[j]));
  }
  cout << dp[n - 1] << endl;
  return 0;
}