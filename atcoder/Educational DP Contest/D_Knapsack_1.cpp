#include <iostream>
#include <vector>
#include <climits>

using ll = long long;

int main() {
  int n, w;
  std::cin >> n >> w;
  std::vector<std::vector<ll>> values(n + 1, std::vector<ll>(w+1, 0));
  
  ll ans = -100;
  int ww, v;
  for (int i = 1; i <= n; i++) {
    std::cin >> ww >> v;
    // Add this item to the knapsack
    for (int cur = 0; cur <= w; cur++) {
      if (cur - ww >= 0) 
        values[i][cur] = std::max(values[i - 1][cur], values[i - 1][cur - ww] + v);
      else 
        values[i][cur] = values[i - 1][cur];

      ans = std::max(ans, values[i][cur]);
    }
  }
  std::cout << ans << std::endl;
  return 0;
}