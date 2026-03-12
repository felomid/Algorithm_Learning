#include <iostream>
#include <vector>
#include <climits>

int main() {
  int n;
  std::cin >> n;
  std::vector<std::vector<int>> points(n + 1, std::vector<int>(3, 0));
  std::vector<std::vector<int>> val(n + 1, std::vector<int>(3));

  for (auto i = 1; i <= n; i++)
    for (auto j = 0; j < 3; j++)
      std::cin >> val[i][j];
  
  for (auto i = 1; i <= n; i++) {
    points[i][0] = std::max(points[i - 1][1], points[i - 1][2]) + val[i][0];
    points[i][1] = std::max(points[i - 1][0], points[i - 1][2]) + val[i][1];
    points[i][2] = std::max(points[i - 1][1], points[i - 1][0]) + val[i][2];
  }
  
  std::cout << std::max({points[n][0], points[n][1], points[n][2]}) << std::endl;

  return 0;
}