class Solution {
public:
  /*
  // memory: O(n^2)
    int minimumTotal(vector<vector<int>>& triangle) {
      int n = triangle.size();
      vector<vector<int>> dp(n);
      dp[0] = triangle[0];
      for (int i = 1; i < n; ++i) {
        // check j == 0
        dp[i] = vector<int>(i + 1);
        dp[i][0] = dp[i - 1][0] + triangle[i][0];
        dp[i][i] = dp[i - 1][i - 1] + triangle[i][i];
        for (int j = 1; j < i; ++j) {
          dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
        }
      }
      int mn = dp[n - 1][0];
      for (int i = 1; i < n; ++i) {
        mn = min(mn, dp[n - 1][i]);
      }
      
      return mn;
    }
    */
  // memory: O(n)
    int minimumTotal(vector<vector<int>>& triangle) {
      int n = triangle.size();
      vector<int> prev = triangle[0];
      vector<int> curr;
      for (int i = 1; i < n; ++i) {
        // check j == 0
        curr = vector<int>(i + 1);
        curr[0] = prev[0] + triangle[i][0];
        curr[i] = prev[i - 1] + triangle[i][i];
        for (int j = 1; j < i; ++j) {
          curr[j] = min(prev[j - 1], prev[j]) + triangle[i][j];
        }
        prev = curr;
      }
      int mn = prev[0];
      for (int i = 1; i < n; ++i) {
        mn = min(mn, prev[i]);
      }
      return mn;
    }
};
// also can start from bottom to top and not use two vectors, just one.
