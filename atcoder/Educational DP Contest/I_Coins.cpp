#include <iostream>
#include <vector>
#include <iomanip>

const int shift = 3000;

int main() {
  int n;
  std::cin >> n;
  std::vector<double> prob(n + 1, 0.0);
  std::vector<std::vector<double>> dp(n + 1, std::vector<double>(2 * shift, 0.0));

  for (int i = 1; i <= n; i++)
    std::cin >> prob[i];
  
  dp[1][-1 + shift] = 1 - prob[1];
  dp[1][1 + shift] = prob[1];

  for (int i = 2; i <= n; i++)
    for(int j = -(i - 1); j <= (i - 1); j += 2) {
      dp[i][j + 1 + shift] += dp[i - 1][j + shift] * prob[i];
      dp[i][j - 1 + shift] += dp[i - 1][j + shift] * (1 - prob[i]);
    }

  double ans = 0;
  for (int i = 0; i <= n; i++)
    ans += dp[n][i + shift];

  std::cout << std::setprecision(10) << ans << std::endl;
  return 0;
}