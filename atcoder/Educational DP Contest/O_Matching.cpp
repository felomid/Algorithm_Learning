#include <iostream>
#include <vector>

const int MOD = 1e9 + 7;

inline int count_set(int state) {
  int ans = 0;
  while (state) {
    ans += state & 1;
    state >>= 1;
  }
  return ans;
}

int main() {
  int n;
  std::cin >> n;
  std::vector<std::vector<int>> a(n, std::vector<int>(n, 0));

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      std::cin >> a[i][j];
  
  std::vector<long long> dp(1 << n, 0);

  const int all_set = (1 << n) - 1;

  // Init
  dp[0] = 1;

  for (int state = 0; state < all_set; state++) {
    int id = count_set(state);
    for (int target = 0; target < n; target++) {
      if (a[id][target] && (!((state >> target) & 1)))
        dp[state ^ (1 << target)] = (dp[state ^ (1 << target)] + dp[state]) % MOD;
    }
  }

  std::cout << dp[all_set] << std::endl;
  return 0;
}