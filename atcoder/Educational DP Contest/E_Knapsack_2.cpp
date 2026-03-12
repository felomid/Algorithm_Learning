#include <iostream>
#include <vector>
#include <climits>

using ll = long long;

int main() {
  int n, w, v=100000;
  std::cin >> n >> w;
  std::vector<std::vector<ll>> weights(n + 1, std::vector<ll>(v + 500, w + 100));

  for (int i = 0; i <= n; i++) {
    weights[i][0] = 0;
  }

  int ww, vv;
  for (int i = 1; i <= n; i++) {
    std::cin >> ww >> vv;

    for (int prev_v = 0; prev_v <= v; prev_v++) {
      if (weights[i - 1][prev_v] > w)
        continue;
      weights[i][prev_v] = std::min(weights[i - 1][prev_v], weights[i][prev_v]);
      weights[i][prev_v + vv] = std::min(weights[i - 1][prev_v] + ww, weights[i][prev_v + vv]);
    }
  }

  for (auto i = 100000; i >=0; --i) {
    if (weights[n][i] <= w) {
      std::cout << i << std::endl;
      break;
    }
  }
  return 0;
}