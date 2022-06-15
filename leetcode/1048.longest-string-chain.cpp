// can also be solved using unoredered map and doint substrings
class Solution {
public:
  // long -> short
    bool isPredecessor(string &a, string &b) {
      if ((a.size() - b.size()) != 1) return false;
      int cnt = 0;
      int i = 0, j = 0;
      for (; i < a.size() && j < b.size(); ++i, ++j) {
        while (i < a.size() && a[i] != b[j]) {
          if (cnt) return false;
          ++cnt;
          ++i;
        }
      }
      return cnt == 1 && (i == a.size() && j == b.size()) 
        || cnt == 0 && (j == b.size() && i == a.size() - 1);
    }

    int longestStrChain(vector<string>& words) {
      sort(words.begin(), words.end(), [](const string &a, const string &b) {
          return a.size() < b.size();
      });
      vector<int> dp(words.size(), 0);
      int i = 0;
      for (; i < words.size() && words[i].size() == words[0].size(); ++i) {
        dp[i] = 1;
      }
      for (int start = 0, end = -1; i < dp.size(); ++i) {
        if (words[i].size() > words[i - 1].size()) {
          start = end + 1;
          end = i - 1;
        }
        for (int j = start; j <= end; ++j) {
          dp[i] = max(dp[i], 1 + (isPredecessor(words[i], words[j]) ? dp[j] : 0));
        }
      }
      int mx = 0;
      for (auto e : dp) {
        mx = max(mx, e);
      }
      return mx;
    }
};
