#include <iostream>
#include <vector>
#include <algorithm>

// Topology Sort
// https://cp-algorithms.com/graph/topological-sort.html

void dfs(std::vector<std::vector<int>> &g, std::vector<int> &visited, std::vector<int> &topo, int start) {
  visited[start] = 1;

  for (auto child : g[start])
    if (!visited[child])
      dfs(g, visited, topo, child);
  
  topo.emplace_back(start);
}

int main() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int>> g(n + 1, std::vector<int>());
  std::vector<int> visited(n + 1, 0);
  std::vector<int> topo;

  int x, y;
  for (int i = 0; i < m; i++) {
    std::cin >> x >> y;
    g[x].emplace_back(y);
  }

  for (int i = 1; i <= n; i++)
    if (!visited[i])
      dfs(g, visited, topo, i);

  visited.assign(n + 1, 0);
  std::reverse(topo.begin(), topo.end());

  int cur, ans = -1, temp;
  for (int i = 0; i < n; i++) {
    cur = topo[i];
    temp = visited[cur];
    ans = std::max(ans, temp);
    for (auto child : g[cur])
      visited[child] = std::max(visited[child], temp + 1);
  }
  std::cout << ans << std::endl;
  return 0;
}