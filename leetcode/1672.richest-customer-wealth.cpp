class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
      int max = 0;
      int cmax;
      for (const auto &line : accounts) {
        cmax = 0;
        for (auto &j : line) {
          cmax += j;
        }
        if (cmax > max) {
          max = cmax;
        }
      }
      return max;
    }
};

