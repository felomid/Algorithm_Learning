#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

bool valid(int a, int b) {
  return (a >= 0) && (b >= 0);
}

int main() {
  std::string s, t;
  std::cin >> s >> t;
  int len_s = s.size(), len_t = t.size();
  std::vector<std::vector<int>> dp(len_s, std::vector<int>(len_t, 0));

  // Init
  bool flag = false;
  for (int i = 0; i < len_s; i++) {
    if (s[i] == t[0]) flag = true;
    dp[i][0] = (flag ? 1 : 0);
  }
  flag = false;
  for (int i = 0; i < len_t; i++) {
    if (s[0] == t[i]) flag = true;
    dp[0][i] = (flag ? 1 : 0);
  }

  for (int i = 1; i < len_s; i++) {
    for (int j = 1; j < len_t; j++) {
      if (s[i] == t[j])
        dp[i][j] = 1 + dp[i - 1][j - 1];
      else
        dp[i][j] = std::max(dp[i][j - 1], dp[i - 1][j]);
    }
  }

  int i = len_s - 1, j = len_t - 1;
  std::string ans = "";
  
  while ((i >= 0) && (j >= 0)) {
    // Add this pair
    if (s[i] == t[j]) {
      ans += s[i];
      --i, --j;
      continue;
    } 
    
    int temp_a = -1, temp_b = -1;
    if (valid(i - 1, j)) temp_a = dp[i - 1][j];
    if (valid(i, j - 1)) temp_b = dp[i][j - 1];
    // std::cout << temp_a << ", " << temp_b << std::endl;
    if (temp_a >= temp_b)
      --i;
    else 
      --j;
  }

  std::reverse(ans.begin(), ans.end());
  std::cout << ans << std::endl;

  return 0;
}