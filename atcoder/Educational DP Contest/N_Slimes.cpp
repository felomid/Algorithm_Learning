#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

int main() {
  int n;
  std::cin >> n;
  std::vector<long long> a(n);
  std::vector<long long> prev(n, 0);
  std::vector<std::vector<long long>> dp(n, std::vector<long long> (n, std::numeric_limits<long long>::max()));

  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
    dp[i][i] = 0;
    if (i == 0)
      prev[i] = a[i];
    else
      prev[i] = a[i] + prev[i - 1];
  }

  int tar;
  long long size1, size2;
  for (int len = 1; len < n; len++)
    for (int i = 0; i + len < n; i++) {
      tar = i + len;
      for (int j = i ; j < tar; j++) {
        size1 = (i == 0 ? prev[j] : prev[j] - prev[i - 1]);
        size2 = prev[tar] - prev[j];
        dp[i][tar] = std::min(dp[i][tar], dp[i][j] + dp[j + 1][tar] + size1 + size2);
      }
    }

  std::cout << dp[0][n - 1] << std::endl;
  return 0;
}