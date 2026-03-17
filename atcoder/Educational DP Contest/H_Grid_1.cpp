#include <iostream>
#include <string>
#include <vector>

const int MOD = 1e9 + 7;

inline bool valid(int x, int y, int n, int m) {
  return (x < n) && (y < m);
}

int main() {
  int n, m;
  std::cin >> n >> m;

  std::vector<std::string> g(n);
  std::vector<std::vector<int>> dp(n, std::vector<int>(m, 0));

  for (int i = 0; i < n; i++)
    std::cin >> g[i];
  
  dp[0][0] = 1; 
  
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (g[i][j] == '.') {
        if (valid(i + 1, j, n, m) && g[i + 1][j] == '.')
          dp[i + 1][j] += dp[i][j] % MOD, dp[i + 1][j] %= MOD;
          if (valid(i, j + 1, n, m) && g[i][j + 1] == '.')
          dp[i][j + 1] += dp[i][j] % MOD, dp[i][j + 1] %= MOD;
      }
  std::cout << dp[n - 1][m - 1] << std::endl;
  // std::cout << INT_MAX << std::endl;
  return 0;
}