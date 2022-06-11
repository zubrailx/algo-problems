class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
      string prefix;
      for (int j = 0; j < strs[0].size(); ++j) {
        int cur = strs[0][j];
        for (int i = 1; i < strs.size(); ++i) {
          if (j < strs[i].size() && cur == strs[i][j]) {
            continue;
          } else {
            return prefix;
          }
        }
        prefix.push_back(cur);
      }
      return prefix;
    }
};
