#include <iostream>
#include <vector>
#include <queue>

const int MOD = 1e9 + 7;

inline void bfs(int start, std::vector<std::vector<int>> &g, std::vector<int> &visit, std::vector<std::vector<long long>> &dp) {
  visit[start] = 1;
  
  dp[start][1] = 0;
  dp[start][0] = 0;

  std::vector<std::pair<int, int>> childs;

  for (auto nxt : g[start]) {
    if (visit[nxt])
      continue;
    bfs(nxt, g, visit, dp);
    childs.emplace_back(std::make_pair(dp[nxt][0], dp[nxt][1]));
  }

  dp[start][1] = 1;
  dp[start][0] = 1;  
  
  for (const auto& [w, b] : childs) {
    dp[start][0] *= (w + b);
    dp[start][1] *= w;
    dp[start][0] %= MOD;
    dp[start][1] %= MOD;
  }

  return;
}

int main() {
  int n;
  std::cin >> n;
  
  if (n == 1) {
    std::cout << 2 << std::endl;
    return 0;
  }

  std::vector<std::vector<int>> g(n);
  std::vector<int> ord;

  int a, b;
  for (int i = 0; i < n - 1; i++) {
    std::cin >> a >> b;
    --a, --b;
    g[a].emplace_back(b);
    g[b].emplace_back(a);
  }

  int start = 0;
  while (start < n) {
    if (g[start].size() == 1)
      break;
    start++;
  }

  std::vector<std::vector<long long>> dp(n, std::vector<long long>(2, 0ll));
  std::vector<int> visit(n, 0);
  // 1 -> black, 0 -> white

  bfs(start, g, visit, dp);
  std::cout << (dp[start][0] + dp[start][1]) % MOD << std::endl;
  return 0;
}