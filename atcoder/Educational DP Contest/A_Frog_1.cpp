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
  int n;
  cin >> n;
  std::vector<int> h(n);
  for(int i=0;i<n;i++) cin >> h[i];
  std::vector<int> dp(n, INT_MAX);
  dp[0] = 0;
  dp[1] = std::abs(h[1]-h[0]);
  for (auto i = 2; i < n; i++) {
    dp[i] = std::min(dp[i - 1] + std::abs(h[i] - h[i - 1]), dp[i - 2] + std::abs(h[i] - h[i - 2]));
  }
  cout << dp[n - 1] << endl;
  return 0;
}