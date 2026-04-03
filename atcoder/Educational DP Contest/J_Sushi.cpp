#include <iostream>
#include <iomanip>
#include <vector>

int n;
double dp[301][301][301];
bool visited[301][301][301];

double mem(int num1, int num2, int num3) {
  if (visited[num1][num2][num3])
    return dp[num1][num2][num3];
  visited[num1][num2][num3] = true;
  if ((num1 == 0) && (num2 == 0) && (num3 == 0))
    return (dp[num1][num2][num3] = 0);

  double normal = num1 + num2 + num3;
  double ans = (double)(n) / (double)(normal);
  if (num1)
    ans += (double)num1 / normal * mem(num1 - 1, num2, num3);
  if (num2)
    ans += (double)num2 / normal * mem(num1 + 1, num2 - 1, num3);
  if (num3)
    ans += (double)num3 / normal * mem(num1, num2 + 1, num3 - 1);

  return (dp[num1][num2][num3] = ans);
}

int main() {
  std::cin >> n;
  std::vector<int> stats(3, 0);
  int a;
  for (int i = 0; i < n; i++) {
    std::cin >> a;
    stats[--a]++;
  }
  std::cout << std::fixed << std::setprecision(15) << mem(stats[0], stats[1], stats[2]) << std::endl;
  return 0;
}