#include <iostream>
#include <vector>

const int MOD = 1e9 + 7;

int main() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n, 0), prev(n, 0);
  std::vector<std::vector<long long>> dp(n, std::vector<long long>(k + 1, 0));

  std::cin >> a[0];
  prev[0] = a[0];
  for (int i = 1; i < n; i++) {
    std::cin >> a[i];
    prev[i] = prev[i - 1] + a[i];
  }
  
  for (int i = 0; i <= a[0]; i++)
    dp[0][i] = 1;
  
  for (int i = 1; i < n; i++) {
    int window = 0;
    
    // Increasing
    int point1 = a[i];
    for (int j = 0; j <= point1; j++) {
      window = (window + dp[i - 1][j]) % MOD;
      dp[i][j] = window;
    }

    // Flat and decrease
    int point2 = std::min(k, prev[i]);
    for (int j = point1 + 1; j <= point2; j++) {
      window = (window - dp[i - 1][j - point1 - 1] + dp[i - 1][j] + MOD) % MOD;
      dp[i][j] = window;
    }
  }
  std::cout << dp[n - 1][k] << std::endl;
  return 0;
}