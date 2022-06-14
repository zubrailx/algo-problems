// memoization
class Solution {
public:
  int minDistance(string word1, string word2) {
    vector<vector<int>> memo(word1.size() + 1, vector<int>(word2.size() + 1, 0));       
    return word1.size() + word2.size() 
      - 2 * lcs(word1, word2, memo, word1.size() - 1, word2.size() - 1);
  }
  int lcs(string &s1, string &s2, vector<vector<int>> &memo, int i, int j) {
    if (i < 0 || j < 0) { return 0; }
    if (memo[i][j] > 0) { return memo[i][j]; }

    int ret;
    if (s1[i] == s2[j]) {
      ret = 1 + lcs(s1, s2, memo, i - 1, j - 1);
    } else {
      ret = max(lcs(s1, s2, memo, i, j - 1), lcs(s1, s2, memo, i - 1, j));
    }
    memo[i][j] = ret;
    return ret;
  }
};

class Solution {
public:
    int minDistance(string word1, string word2) {
      vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
      for (int i = 0; i <= word1.size(); ++i) { dp[i][0] = i; }
      for (int i = 0; i <= word2.size(); ++i) { dp[0][i] = i; }

      for (int i = 0; i < word1.size(); ++i) {
        for (int j = 0; j < word2.size(); ++j) {
          if (word1[i] == word2[j]) { 
            dp[i + 1][j + 1] = dp[i][j];
          } else {
            dp[i + 1][j + 1] = min(dp[i + 1][j], dp[i][j + 1]) + 1;
          }
        }
      }
      return dp[word1.size()][word2.size()];
    }
};
